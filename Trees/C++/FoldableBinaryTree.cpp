// C++ program to check foldable binary tree
#include <bits/stdc++.h>
using namespace std;


class node {
public:
	int data;
	node* left;
	node* right;
};


void mirror(node* node);

bool isStructSame(node* a, node* b);

bool isFoldable(node* root)
{
	bool res;

	/* base case */
	if (root == NULL)
		return true;

	mirror(root->left);

	res = isStructSame(root->left, root->right);
	mirror(root->left);

	return res;
}

bool isStructSame(node* a, node* b)
{
	if (a == NULL && b == NULL) {
		return true;
	}
	if (a != NULL && b != NULL
		&& isStructSame(a->left, b->left)
		&& isStructSame(a->right, b->right)) {
		return true;
	}

	return false;
}

void mirror(node* Node)
{
	if (Node == NULL)
		return;
	else {
		node* temp;

		
		mirror(Node->left);
		mirror(Node->right);

	
		temp = Node->left;
		Node->left = Node->right;
		Node->right = temp;
	}
}

node* newNode(int data)
{
	node* Node = new node();
	Node->data = data;
	Node->left = NULL;
	Node->right = NULL;

	return (Node);
}

int main(void)
{

	node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->right = newNode(4);
	root->right->left = newNode(5);

	if (isFoldable(root) == 1) {
		cout << "tree is foldable";
	}
	else {
		cout << "\ntree is not foldable";
	}
	return 0;
}
