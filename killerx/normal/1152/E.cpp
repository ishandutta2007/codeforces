#pragma GCC optimize(2)
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define rep(i, n) for (int i = 0; i < n; ++ i)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
const int inf = 0x3f3f3f3f;
const ll linf = 1LL << 60;
const ld eps = 1e-9;
int read() {
	int x = 0, f = 1, c = getchar();
	for(;!isdigit(c); c = getchar()) if(c == '-') f ^= 1;
	for(; isdigit(c); c = getchar()) x = x * 10 + c - 48;
	return f ? x : -x;
}
void write(int x) {
	if (!x) {putchar('0'); return;}
	if (x < 0) putchar('-'), x = -x;
	int stk[10], tp = 0;
	for (; x; x /= 10) stk[tp ++] = x - x / 10 * 10;
	for (; tp; putchar(48 + stk[-- tp]));
}
const int N = 1e5 + 5;
int n;
int b[N], c[N];
vector <int> vec, od;
multiset <int> g[N << 1];
int vis[N];
void dfs(int u) {
	multiset <int> :: iterator it;
	for (it = g[u].begin(); it != g[u].end(); it = g[u].begin()) {
		int v = *it;
		g[u].erase(g[u].find(v));
		g[v].erase(g[v].find(u));
		dfs(v);
		write(vec[v]); putchar(' ');
	}
}
int used[N << 1];
void dffs(int u) {
	used[u] = 1;
	for (int v : g[u]) {
		if (!used[v]) dffs(v);
	}
}
int main() {
	n = read() - 1;
	for (int i = 0; i < n; ++ i) b[i] = read();
	for (int i = 0; i < n; ++ i) c[i] = read();
//	n = 1e5 - 1;
//	for (int i = 0; i < n; ++ i) b[i] = 1;
//	for (int i = 0; i < n; ++ i) c[i] = 2;
	for (int i = 0; i < n; ++ i) vec.PB(b[i]), vec.PB(c[i]);
	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());
	for (int i = 0; i < n; ++ i) {
		b[i] = lower_bound(vec.begin(), vec.end(), b[i]) - vec.begin();
		c[i] = lower_bound(vec.begin(), vec.end(), c[i]) - vec.begin();
		if (b[i] > c[i]) {
			write(-1);
			return 0;
		}
		g[c[i]].insert(b[i]);
		g[b[i]].insert(c[i]);
	}
	int cnt = 0;
	for (int i = 0; i < (int) vec.size(); ++ i) {
		if (g[i].size() & 1) od.PB(i);
		if (!used[i]) dffs(i), ++ cnt;
	}
	if ((od.size() != 2 && od.size() != 0) || cnt > 1) write(-1);
	else {
		if (od.size()) dfs(od[0]), write(vec[od[0]]);
		else dfs(0), write(vec[0]);
	}
	return 0;
}