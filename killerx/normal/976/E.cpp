#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 2e5 + 5;
int n, a, b;
int h[mxn], d[mxn];
int id[mxn];

ll ans, res;

int main() {
	scanf("%d %d %d", &n, &a, &b);
	rep(i, n) scanf("%d %d", &h[i], &d[i]);
	b = min(b, n);
	vector <pair <int, int> > v;
	rep(i, n) v.pb(mp(h[i] - d[i], i));
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	rep(i, n) id[v[i].second] = i;
	rep(i, n) ans += d[i];
	rep(xx, b) {
		int i = v[xx].second;
		ans += max(0, h[i] - d[i]);
	}
	res = ans;
	ll ori = ans;
	rep(i, n) {
		ans = ori;
		ll nh = h[i];
		rep(j, a) nh <<= 1;
		if (id[i] < b) {
			ans -= max(0, h[i] - d[i]);
			ans += max(0LL, nh - d[i]);
		} else if (b) {
			int j = v[b - 1].second;
			ans -= max(0, h[j] - d[j]);
			ans += max(0LL, nh - d[i]);
		}
		res = max(res, ans);
	}
	printf("%lld\n", res);
	return 0;
}