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
	int n;
	cin >> n;
	string st;
	cin >> st;
	vector<int[3]> dp(3);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = i; k < n; k += 3) {
				if (j == 0 && st[k] != 'R') dp[i][j]++;
				if (j == 1 && st[k] != 'G') dp[i][j]++;
				if (j == 2 && st[k] != 'B') dp[i][j]++;
			}
		}
	}
	vector<char> a(3);
	a[0] = 'R'; a[1] = 'G'; a[2] = 'B';
	int ans = INFi;
	char c1, c2, c3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				if (i == j || j == k || i == k) continue;
				if (dp[0][i] + dp[1][j] + dp[2][k] < ans) {
					ans = dp[0][i] + dp[1][j] + dp[2][k];
					c1 = a[i]; c2 = a[j]; c3 = a[k];
				}
			}
		}
	}
	cout << ans << endl;
	for (int i = 0; i < n; i++) {
		if (i % 3 == 0) cout << c1;
		if (i % 3 == 1) cout << c2;
		if (i % 3 == 2) cout << c3;
	}
	cout << endl;
	//system("pause");
	return 0;
}