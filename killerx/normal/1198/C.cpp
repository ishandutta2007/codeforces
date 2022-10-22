#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector <int>
#define pii pair <int, int>
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i,n) for (int i = 0; i < (int) (n); ++ i)
#define foreach(it,c) for (__typeof(c.begin()) it = c.begin(); it != c.end(); ++ it)

inline int read() {
	int x = 0, f = 1, c = getchar();
	for (;!isdigit(c);c = getchar()) if (c == '-') f ^= 1;
	for (; isdigit(c);c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}

int n, m;
bool vis[300005];
bool use[500005];

void Main() {
	n = read(), m = read();
	rep(i, n * 3) vis[i] = 0;
	rep(i, m) use[i] = 0;
	int cnt = 0;
	rep(i, m) {
		int u = read() - 1, v = read() - 1;
		if (vis[u] || vis[v]) continue;
		vis[u] = vis[v] = 1;
		use[i] = 1; cnt ++;
	}
	vi ans;
	if (cnt >= n) {puts("Matching"); rep(i, m) if (use[i]) ans.pb(i);}
	else {puts("IndSet"); rep(i, n * 3) if (!vis[i]) ans.pb(i);}
	rep(i, n) printf("%d ", ans[i] + 1); puts("");
}

int main() {
	int T = read(); while (T --) Main();
	return 0;
}