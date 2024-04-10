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

int n;

ll get(ll l, ll r) {
	ll ans = 0;
	while (l % 2) ans ^= (--l);
	while (r % 2 == 0) ans ^= (++r);
	ans ^= (r - l + 1) / 2 % 2;
	return ans;
}

int main() {
	scanf("%d", &n);
	ll ans = 0;
	while (n--) {
		ll x, m;
		scanf("%lld%lld", &x, &m);
		ans ^= get(x, x + m - 1);
	}
	printf("%s\n", ans ? "tolik" : "bolik");
	return 0;
}