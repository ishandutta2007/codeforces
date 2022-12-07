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

ll n, m, k;

int main() {
	scanf("%lld%lld%lld", &n, &m, &k);
	if (k > n + m - 2) printf("-1\n");
	else {
		ll ans = 0;
		if (k > n - 1) ans = max(ans, m / (k - (n - 1) + 1));
		else ans = max(ans, m * (n / (k + 1)));
		swap(n, m);
		if (k > n - 1) ans = max(ans, m / (k - (n - 1) + 1));
		else ans = max(ans, m * (n / (k + 1)));
		printf("%lld\n", ans);
	}
	return 0;
}