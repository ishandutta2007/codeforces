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

const int N = 2005;
int n, p[N], s[N];
vector<pii> ans;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
	for (int i = 1; i <= n; i++) scanf("%d", &s[i]);
	for (int i = n; i >= 1; i--) {
		for (int j = i; j <= n; j++) {
			if (p[i] == s[j]) {
				int u = i;
				for (int k = i + 1; k <= j; k++) {
					if (p[k] == s[k]) continue;
					ans.pb(mp(u, k));
					swap(p[u], p[k]);
					u = k;
				}
				break;
			}
		}
	}
	ll sum = 0;
	for (int i = 0; i < sz(ans); i++) sum += abs(ans[i].fi - ans[i].se);
	printf("%lld\n", sum);
	printf("%d\n", sz(ans));
	for (int i = 0; i < sz(ans); i++) printf("%d %d\n", ans[i].fi, ans[i].se);
	return 0;
}