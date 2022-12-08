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
	vector<vector<pair<int, int>>> dp(n);
	dp[0].resize(3);
	vector<char> a = { 'R', 'G', 'B' };
	dp[0][1] = { 1, -1 }; dp[0][0] = { 1, -1 }; dp[0][2] = { 1, -1 };
	if (st[0] == 'R') dp[0][0] = { 0, -1 };
	if (st[0] == 'G') dp[0][1] = { 0, -1 };
	if (st[0] == 'B') dp[0][2] = { 0, -1 };
	for (int i = 1; i < n; i++) {
		dp[i].resize(3);
		for (int j = 0; j < 3; j++) {
			int t = 0;
			if (a[j] != st[i]) t++;
			if (dp[i - 1][(j + 2) % 3].first < dp[i - 1][(j + 1) % 3].first) {
				dp[i][j] = { dp[i - 1][(j + 2) % 3].first + t, (j + 2) % 3 };
			}
			else {
				dp[i][j] = { dp[i - 1][(j + 1) % 3].first + t, (j + 1) % 3 };
			}
			//cout << i << " " << a[j] << " " << dp[i][j].first << " " << dp[i][(j + 2) % 3].first << " " << dp[i][(j + 1) % 3].first << endl;
		}
	}
	int ans = INFi;
	int cur = -1;
	for (int i = 0; i < 3; i++) {
		if (dp[n - 1][i].first < ans) {
			ans = dp[n - 1][i].first;
			cur = i;
		}
	}
	vector<char> an(n);
	for (int i = n - 1; i >= 0; i--) {
		an[i] = a[cur];
		cur = dp[i][cur].second;
	}
	cout << ans << endl;
	for (char c : an) cout << c;
	cout << endl;
	//system("pause");
	return 0;
}