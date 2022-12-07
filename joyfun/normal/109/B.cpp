#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()

int pl, pr, vl, vr, k;
vi c;

double get(ll l, ll r, ll L, ll R) {
	r = min(r, R); l = max(l, L);
	if (l > r) return 0;
	return 1.0 * (r - l + 1) / (R - L + 1);
}

int main() {
	scanf("%d%d%d%d%d", &pl, &pr, &vl, &vr, &k);
	double out = 0;
	c.pb(0);
	for (int i = 1; i <= 10; i++) {
		for (int j = 0; j < (1<<i); j++) {
			ll ans = 0;
			for (int k = 0; k < i; k++) {
				if (j>>k&1) ans = ans * 10 + 7;
				else ans = ans * 10 + 4;
			}
			if (ans > 1e9) continue;
			c.pb(ans);
		}
	}
	c.pb(1000000001);
	sort(c.begin(), c.end());
	for (int i = 1; i < sz(c); i++) {
		if (i + k >= sz(c)) break;
		out += get(c[i - 1] + 1, c[i], pl, pr) * get(c[i + k - 1], c[i + k] - 1, vl, vr);
		out += get(c[i - 1] + 1, c[i], vl, vr) * get(c[i + k - 1], c[i + k] - 1, pl, pr);
		if (k == 1) out -= get(c[i], c[i], pl, pr) * get(c[i], c[i], vl, vr);
	}
	printf("%.12f\n", out);
	return 0;
}