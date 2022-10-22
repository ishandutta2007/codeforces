#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read() {
	int  x = 0, f = 1, c = getchar();
	for (;!isdigit(c); c = getchar()) if (c == '-') f ^= 1;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}
int n, m;
int b[100005];
int g[100005];
map <int, ll> cnt;
int main() {
	n = read(), m = read();
	for (int i = 0; i < n; ++ i) b[i] = read();
	for (int i = 0; i < m; ++ i) g[i] = read();
	int mxb = 0;
	ll sumb = 0;
	for (int i = 0; i < n; ++ i) {
		mxb = max(mxb, b[i]);
		sumb += b[i];
		cnt[b[i]] += m - 1;
	}
	ll ans = 0;
	for (int i = 0; i < m; ++ i) {
		if (mxb > g[i]) {
			puts("-1"); return 0;
		}
		ans += sumb;
		if (mxb == g[i]) continue;
		if (cnt.empty()) {
			puts("-1"); return 0;
		}
		map <int, ll> :: iterator it;
		it = cnt.end(); -- it;
		it -> second --;
		ans += g[i] - it -> first;
		if (it -> second == 0) cnt.erase(it);
	}
	printf("%lld\n", ans);
	return 0;
}