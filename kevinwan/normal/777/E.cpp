#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct ring { ll a, b, h; };
bool comp(const ring&a, const ring&b) { if (a.b < b.b)return 1; if (a.b == b.b)return a.a < b.a; return 0; }
ring r[100001];
ll dp[100001],seg[200001];
int n,far[100001];
ll q(int a,int b) {
	a += n - 1, b += n - 1;
	ll ans = 0;
	while (b > a) {
		if (a & 1)ans = max(ans, seg[a]), a++;
		if (!(b & 1))ans= max(ans, seg[b]), b--;
		a >>= 1, b >>= 1;
	}
	if (a == b)ans = max(ans, seg[a]);
	return ans;
}
void u(int a, ll b) {
	a += n - 1;
	seg[a] = b;
	for (a >>= 1; a; a >>= 1)seg[a] = max(seg[2*a], seg[2 * a + 1]);
}
int main() {
	int i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)scanf("%lld%lld%lld", &r[i].a, &r[i].b, &r[i].h);
	sort(r + 1, r + n + 1, comp);
	ll ans = 0;

	for (i = 1; i <= n; i++) {
		dp[i] = r[i].h;
		int cur = 0;
		for (int j = 1 << 17; j; j >>= 1) {
			if (cur + j > n)continue;
			if (r[cur + j].b <= r[i].a)cur += j;
		}
		dp[i] = max(dp[i], r[i].h + q(cur + 1, i - 1));
		u(i, dp[i]);
	}
	for (i = 0; i <= n; i++)ans = max(ans, dp[i]);
	printf("%lld", ans);
	getchar(); getchar();
}