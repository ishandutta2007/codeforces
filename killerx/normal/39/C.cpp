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

int n;
int c[4005], radii[4005];
vi v;
vi id[4005];
int dp[4005][4005];
int prv[4005][4005];
int has[4005][4005];

int DP(int l, int r) {
	if (~dp[l][r]) return dp[l][r];
	if (l == r) return 0;
	dp[l][r] = DP(l + 1, r);
	prv[l][r] = l;
	rep(ii, id[l].size()) {
		int i = lower_bound(v.begin(), v.end(), c[id[l][ii]] + radii[id[l][ii]]) - v.begin();
		if (i >= r) continue;
		if (dp[l][r] < DP(l, i) + DP(i, r)) {
			dp[l][r] = DP(l, i) + DP(i, r);
			prv[l][r] = i;
		}
	}
	return dp[l][r] += (~has[l][r] ? 1 : 0);
}

vi ans;
void PD(int l, int r) {
	if (~has[l][r]) ans.pb(has[l][r] + 1);
	if (l == r) return;
	if (!~prv[l][r]) return;
	if (prv[l][r] == l) {PD(l + 1, r); return;}
	PD(l, prv[l][r]); PD(prv[l][r], r);
}

int main() {
	n = read();
	rep(i, n) {
		c[i] = read(), radii[i] = read();
		v.pb(c[i] - radii[i]);
		v.pb(c[i] + radii[i]);
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	rep(i, n) id[lower_bound(v.begin(), v.end(), c[i] - radii[i]) - v.begin()].pb(i);
	memset(has, -1, sizeof(has));
	rep(i, n) has[lower_bound(v.begin(), v.end(), c[i] - radii[i]) - v.begin()][lower_bound(v.begin(), v.end(), c[i] + radii[i]) - v.begin()] = i;
	memset(dp, -1, sizeof(dp));
	printf("%d\n", DP(0, v.size() - 1));
	PD(0, v.size() - 1);
	sort(ans.begin(), ans.end());
	rep(i, ans.size()) printf("%d ", ans[i]); puts("");
	return 0;
}