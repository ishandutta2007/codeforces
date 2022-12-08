//#pragma optimise('O3');
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <deque>
#include <cassert>

using namespace std;

#define PI 3.14159265
typedef long long ll;

const ll INF = 4 * 1e18;
const int INFi = 2 * 1e9;
ll mod = 1e9 + 7;

int rnd() {
	return (rand() << 15) + rand();
}

struct Node {
	int x, y;
	Node *L, *R;
	Node(int _x) {
		x = _x;
		y = rnd();
		L = R = NULL;
	}
};

pair<Node*, Node*> split(Node *root, int k) {
	if (root == NULL) return { NULL, NULL };
	if (root->x < k) {
		auto f = split(root->R, k);
		root->R = f.first;
		return { root, f.second };
	}
	else {
		auto f = split(root->L, k);
		root->L = f.second;
		return { f.first, root };
	}
}

Node* merge(Node *left, Node *right) {
	if (left == NULL) return right;
	if (right == NULL) return left;
	if (left->y > right->y) {
		left->R = merge(left->R, right);
		return left;
	}
	else {
		right->L = merge(left, right->L);
		return right;
	}
}

Node* insert(Node *root, int x) {
	auto f = split(root, x);
	return merge(merge(f.first, new Node(x)), f.second);
}

bool find(Node *root, int x) {
	auto f = split(root, x);
	bool fl = false;
	if (f.second->x == x) {
		fl = true;
	}
	root = merge(f.first, f.second);
	return fl;
}



int main() {
	int q;
	cin >> q;
	int l1, r1, l2, r2;
	for (int i = 0; i < q; i++) {
		cin >> l1 >> r1 >> l2 >> r2;
		if (l1 == l2) {
			if (r1 == r2) {
				cout << l1 << " " << r2 << endl;
			}
			else {
				cout << r1 << " " << r2 << endl;
			}
		}
		else {
			cout << l1 << " " << l2 << endl;
		}
	}
	//system("pause");
	return 0;
}