#include <queue>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
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
void write(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x >= 10) write(x / 10);
    putchar('0' + x % 10);
}

const int N = 4005;
const ll INF = 0x7fffffffff;
ll sz[N][N], vis[N], n, m, s, t;
ll sum[N][N], p[N], A[N], B[N];
vector<ll> to[N], w[N];

inline void add(int x, int y, ll z) {
	to[x].push_back(y), w[x].push_back(z);
}

#define MP make_pair
priority_queue<pair<ll, int> > q;
void diji(ll *dis, int s) {
	for (int i = 1;i <= n; i++) dis[i] = INF, vis[i] = 0;
	dis[s] = 0, q.push(MP(0, s));
	while (q.size()) {
		int x = q.top().second; q.pop();
		if (vis[x]) continue; vis[x] = 1;
		for (int i = 0;i < to[x].size(); i++) {
			int y = to[x][i];
			if (dis[x] + w[x][i] < dis[y]) 
				dis[y] = dis[x] + w[x][i], q.push(MP(-dis[y], y));
		}
	}
}

int lisan(ll *dis) {
	vector<ll> pre;
	for (int i = 1;i <= n; i++) pre.push_back(dis[i]);
	sort(pre.begin(), pre.end());
	pre.erase(unique(pre.begin(), pre.end()), pre.end());
	for (int i = 1;i <= n; i++)
		dis[i] = lower_bound(pre.begin(), pre.end(), dis[i]) - pre.begin() + 1;
	return pre.size();
}

ll f[2][N][N], sa, sb;

inline ll Sum(int lx, int ly, int rx, int ry) {
	return sum[rx][ry] - sum[lx-1][ry] - sum[rx][ly-1] + sum[lx-1][ly-1];
}

inline ll cnt(int lx, int ly, int rx, int ry) {
	return sz[rx][ry] - sz[lx-1][ry] - sz[rx][ly-1] + sz[lx-1][ly-1];
}

int main() {
	read(n), read(m), read(s), read(t);
	for (int i = 1;i <= n; i++) read(p[i]);
	for (int i = 1;i <= m; i++) {
		int x, y, z; read(x), read(y), read(z);
		add(x, y, z), add(y, x, z);
	} diji(A, s), diji(B, t); sa = lisan(A), sb = lisan(B);
	for (int i = 1;i <= n; i++) sum[A[i]][B[i]] += p[i], sz[A[i]][B[i]]++;
	for (int i = 1;i <= sa + 1; i++) 
		for (int j = 1;j <= sb + 1; j++)
			sum[i][j] += sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1],
			sz[i][j] += sz[i-1][j] + sz[i][j-1] - sz[i-1][j-1];
	
	for (int i = sa; i >= 0; i--) {
		for (int j = sb; j >= 0; j--) {
			if (cnt(i, j, i, sb) > 0) f[0][i][j] = max(f[0][i+1][j], f[1][i+1][j]) + Sum(i, j, i, sb);
			else f[0][i][j] = f[0][i+1][j];
			if (cnt(i, j, sa, j) > 0) f[1][i][j] = min(f[1][i][j+1], f[0][i][j+1]) - Sum(i, j, sa, j);
			else f[1][i][j] = f[1][i][j+1]; 
		}
	}
	if (f[0][1][1] > 0) puts("Break a heart");
	else if (f[0][1][1] < 0) puts("Cry");
	else puts("Flowers");
}
/*
5 4
1 2
2 2 -5 -4 6
1 2 4
2 3 5
2 4 2
4 5 2

*/