#pragma GCC optimize(3, "inline")
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

const int N = 1000500;
ll ans;
int f[N], siz[N], vis[N], n;

inline int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
pair<int, int> poi[N];
vector<int> to[N];

ll work(void) {
	ll res = 0;
	for (int i = 1;i <= n; i++) vis[i] = 0, siz[f[i] = i] = 1;
	for (int i = 1;i <= n; i++) {
		int a = poi[i].first, x = poi[i].second; res += a;
		for (auto y: to[x]) {
			if (!vis[y]) continue;
			int fx = find(x), fy = find(y);
			if (siz[fx] < siz[fy]) swap(fx, fy);
			res += (ll)siz[fx] * siz[fy] * a;
			siz[fx] += siz[fy], f[fy] = fx;
		}
		vis[x] = 1;
	}
	return res;
}

int main() {
	read(n);
	for (int i = 1, x;i <= n; i++) 
		read(x), poi[i] = MP(x, i);
	for (int i = 1;i < n; i++) {
		int x, y; read(x), read(y);
		to[x].push_back(y);
		to[y].push_back(x);
	}
	sort(poi + 1, poi + n + 1);
	ans += work();
	reverse(poi + 1, poi + n + 1);
	ans -= work();
	printf ("%lld\n", ans);
	return 0;
}