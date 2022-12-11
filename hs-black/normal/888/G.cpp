#include <queue>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MP make_pair
#define ll long long
#define fi first
#define se second
using namespace std;

template <typename T>
void read(T &x) {
    x = 0; bool f = 0;
    char c = getchar();
    for (;!isdigit(c);c=getchar()) if (c=='-') f=1;
    for (;isdigit(c);c=getchar()) x=x*10+(c^48);
    if (f) x=-x;
}

template <typename T>
inline void Mx(T &x, T y) { x < y && (x = y); }

template <typename T>
inline void Mn(T &x, T y) { x > y && (x = y); }

const int N = 8000500;
int ch[N][2], cnt = 1, n;
vector<int> v[N];

void insert(int x) {
	int nw = 1;
	for (int i = 30;i >= 0; i--) {
		int di = (x >> i) & 1;
		if (!ch[nw][di]) ch[nw][di] = ++cnt;
		nw = ch[nw][di]; v[nw].push_back(x);
	}
}

int query(int x, int nw, int dep) {
	for (int i = dep - 1;i >= 0; i--) {
		int di = (x >> i) & 1;
		if (ch[nw][di]) nw = ch[nw][di];
		else nw = ch[nw][!di];
	}
	return v[nw][0] ^ x;
}

ll ans = 0;
void dfs(int x, int dep) {
	if (dep == 0) return;
	if (!ch[x][0]) return dfs(ch[x][1], dep - 1);
	if (!ch[x][1]) return dfs(ch[x][0], dep - 1);
	ll tmp = 1e15, k = ch[x][0], nw = ch[x][1];
	if (v[ch[x][0]].size() > v[ch[x][1]].size()) swap(k, nw);
	dfs(ch[x][0], dep - 1), dfs(ch[x][1], dep - 1); 
	for (auto y: v[k]) Mn(tmp, (ll)query(y, nw, dep-1));
	ans += tmp;
}

int main() {
	read(n);
	for (int i = 1, a;i <= n; i++) read(a), insert(a); 
	dfs(1, 31); cout << ans << endl;
	return 0;
}