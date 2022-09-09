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
#include <unordered_set>
#include <set>
#include <map>
#include <vector>
#include <chrono>
#include <iostream>
#include <limits>
#include <numeric>

using namespace std;

using ull = unsigned long long;
using ll = long long;

const int P = 998244353;

int norm(int x) { return x >= P ? x - P : x; }
int reduce(int x) { return x < 0 ? x + P : x; }
int neg(int x) { return x ? P - x : 0; }
void add(int& x, int y) { if ((x += y - P) < 0) x += P; }
void sub(int& x, int y) { if ((x -= y) < 0) x += P; }
void fam(int& x, int y, int z) { x = (x + y * (ull)z) % P; }
int mpow(int x, unsigned k) {
	if (k == 0) return 1;
	int ret = mpow(x * (ull)x % P, k >> 1);
	if (k & 1) ret = ret * (ull)x % P;
	return ret;
}
int quo2(int x) { return ((x & 1) ? x + P : x) >> 1; }

const int _ = 150010;

struct Node {
	int v;
	union {
		int ch[2];
		struct { int ls, rs;};
	};
} Q[_ * 35];

int top, root, x;

int dfs2(int p, int q, int dep) {
	if (!p || !q) return 0;
	if (dep == -1) return 0;
	if ((x >> dep) & 1) {
		int ret = (Q[Q[p].ls].v * (ull)Q[Q[q].ls].v + Q[Q[p].rs].v * (ull)Q[Q[q].rs].v) % P;
		int a = dfs2(Q[p].ls, Q[q].rs, dep - 1);
		int b = dfs2(Q[q].ls, Q[p].rs, dep - 1);
		return (ret + a * (ull)b + a * (1ULL + Q[Q[p].rs].v + Q[Q[q].ls].v)
		                         + b * (1ULL + Q[Q[q].rs].v + Q[Q[p].ls].v)) % P;
	} else {
		return norm(dfs2(Q[p].ls, Q[q].ls, dep - 1) + dfs2(Q[p].rs, Q[q].rs, dep - 1));
	}
}

int dfs(int u, int dep) {
	if (!u) return 0;
	if (dep == -1) return 0;
	if ((x >> dep) & 1) {
		int ret = norm(Q[Q[u].ls].v + Q[Q[u].rs].v);
		add(ret, dfs2(Q[u].ls, Q[u].rs, dep - 1));
		return ret;
	} else {
		int ret = norm(dfs(Q[u].ls, dep - 1) + dfs(Q[u].rs, dep - 1));
		return ret;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	root = ++top;
	int N; cin >> N >> x; ++x;
	while (N--) {
		int ai; cin >> ai;
		int p = root;
		for (int i = 30; i >= 0; --i) {
			Q[p].v = norm(Q[p].v * 2 + 1);
			if (!Q[p].ch[(ai >> i) & 1])
				Q[p].ch[(ai >> i) & 1] = ++top;
			p = Q[p].ch[(ai >> i) & 1];
		}
		Q[p].v = norm(Q[p].v * 2 + 1);
	}
	cout << dfs(root, 30) << '\n';

	return 0;
}