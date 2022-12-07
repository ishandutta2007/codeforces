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

int x, y, z, k;

int main() {
	scanf("%d%d%d%d", &x, &y, &z, &k);
	if (y > z) swap(y, z);
	ll ans = 0;
	for (int i = 0; i <= x - 1 && i <= k; i++) {
		int yu = k - i;
		if (yu / 2 > (y - 1)) {
			ans = max(ans, 1ll * (i + 1) * y * min(z, yu - (y - 1) + 1));
		} else ans = max(ans, 1ll * (i + 1) * (yu / 2 + 1) * min(z, yu - yu / 2 + 1));
	}
	printf("%lld\n", ans);
	return 0;
}