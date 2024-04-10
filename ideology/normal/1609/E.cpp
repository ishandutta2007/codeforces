#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>
 
#include <algorithm>
#include <random>
#include <bitset>
#include <queue>
#include <stack>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <chrono>
#include <iostream>
#include <limits>
#include <numeric>

using namespace std;

using ll = long long;
using ull = unsigned long long;

// const int P = 998244353;

// int norm(int x) { return x >= P ? x - P : x; }
// void add(int& x, int y) { if ((x += y) >= P) x -= P; }
// void sub(int& x, int y) { if ((x -= y) < 0) x += P; }

// int mpow(int x, int k) {
// 	if (k == 0) return 1;
// 	int ret = mpow(x * (ull)x % P, k >> 1);
// 	if (k & 1) ret = x * (ull)ret % P;
// 	return ret;
// }

const int _ = 100010, INF = 1e8;

char s[_];

struct Node {
	int mat[3][3];
	Node() { memset(mat, 0, sizeof(mat)); }
	Node(const Node& x) { memcpy(mat, x.mat, sizeof(mat)); }
	Node operator+(const Node& rhs) const {
		Node tmp;
		for (int i = 0; i != 3; ++i) for (int j = i; j != 3; ++j) {
			tmp.mat[i][j] = INF;
			for (int k = i; k <= j; ++k) tmp.mat[i][j] = min(tmp.mat[i][j], mat[i][k] + rhs.mat[k][j]);
		}
		tmp.mat[0][1] = min({tmp.mat[0][1], tmp.mat[0][0], tmp.mat[1][1]});
		tmp.mat[1][2] = min({tmp.mat[1][2], tmp.mat[1][1], tmp.mat[2][2]});
		tmp.mat[0][2] = min({tmp.mat[0][2], tmp.mat[0][1], tmp.mat[1][2]});
		return tmp;
	}
	void set(int v) {
		memset(mat, 0, sizeof(mat)); mat[v][v] = 1;
	}
} P[_ << 2];

void build(int o, int l, int r) {
	if (l == r) {
		P[o].set(s[l] - 'a');
		return;
	}
	int mid = (l + r) / 2;
	build(o << 1, l, mid); build(o << 1 | 1, mid + 1, r);
	P[o] = P[o << 1] + P[o << 1 | 1];
}
void chg(int o, int l, int r, int k, int x) {
	if (l == r) {
		P[o].set(x);
		return;
	}
	int mid = (l + r) / 2;
	if (k <= mid) chg(o << 1, l, mid, k, x);
	else chg(o << 1 | 1, mid + 1, r, k, x);
	P[o] = P[o << 1] + P[o << 1 | 1];
	// for (int i = 0; i != 3; ++i) for (int j = i; j != 3; ++j) cout << P[o].mat[i][j] << " ";
	// 	cout << "OF " << o << ',' << l << ',' << r << '\n';
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int N, Q; cin >> N >> Q >> (s + 1);
	build(1, 1, N);
	while (Q--) {
		int pos; char c; cin >> pos >> c; s[pos] = c;
		chg(1, 1, N, pos, c - 'a');
		cout << P[1].mat[0][2] << '\n';

		// {
		// 	Node val; val.set(s[1] - 'a');
		// 	for (int i = 2; i <= N; ++i) {
		// 		Node tmp; tmp.set(s[i] - 'a');
		// 		val = val + tmp;
		// 		if (i == 6) cout << "tmp " << val.mat[0][2] << '\n';
		// 	}
		// 	cout << (s + 1) << '\n';
		// 	cout << "DEB " << val.mat[0][2] << '\n';
		// }

		// for (int i = 0; i != 3; ++i) for (int j = i; j != 3; ++j) cout << P[1].mat[i][j] << " ";
		// cout << '\n';
	}

	return 0;
}