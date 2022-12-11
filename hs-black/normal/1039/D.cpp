#pragma GCC optimize(3, "inline")
#include <cmath>
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

const int N = 100500;
vector<int> to[N];
inline void add(int x, int y) {
	to[x].push_back(y), to[y].push_back(x);
}
int n;

int dp[N], d[N], f[N], mx[N], t;

void dfs(int x, int fa) {
	d[++t] = x, f[x] = fa;
	for (auto y: to[x]) if (y ^ fa) dfs(y, x);
}

#define re register
int get(int k) {
	int cnt = 0;
	for (re int i = n; i; --i) dp[i] = 1;
	for (re int i = n; i ; --i) {
		int x = d[i];
		if (f[x] && dp[f[x]] && dp[x]) {
			if (dp[x] + dp[f[x]] >= k) 
				cnt++, dp[f[x]] = 0;
			else Mx(dp[f[x]], dp[x] + 1);
		}
	}
	return cnt;
}

int ans[N];
int main() {
	ios::sync_with_stdio(false);
	read(n); int m = sqrt(n * log(n) / log(2));
	for (re int i = n - 1, x, y; i; i--)
		read(x), read(y), add(x, y);
	ans[1] = n, dfs(1, 0);
	for (re int i = 2;i <= m; i++) ans[i] = get(i);
	
	for (re int i = m + 1, l, r, t;i <= n; i = r + 1) {
		l = i, r = n, t = get(i);
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (get(mid) ^ t) r = mid - 1;
			else l = mid + 1;
		}
		for (re int j = i;j <= r; j++) ans[j] = t;
	}

	for (re int i = 1;i <= n; i++) cout << ans[i] << endl;
	
	return 0;
}