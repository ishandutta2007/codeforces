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

const int N = 500005;
int n, q, B;
ll a[N];
int id[N];
vector<pair<ll, int> > v[N];
ll ad[N];

int main() {
	scanf("%d%d", &n, &q); B = sqrt(n + 0.5);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		id[i] = i / B;
		v[id[i]].pb(mp(a[i], i));
	}
	for (int i = 0; i <= id[n]; i++) sort(v[i].begin(), v[i].end());
	int tp, l, r;
	ll x;
	while (q--) {
		scanf("%d", &tp);
		if (tp == 1) {
			scanf("%d%d%lld", &l, &r, &x);
			for (int i = id[l] + 1; i <= id[r] - 1; i++) ad[i] += x;
			for (int i = 0; i < v[id[l]].size(); i++)
				if (v[id[l]][i].se >= l && v[id[l]][i].se <= r) v[id[l]][i].fi += x;
			sort(v[id[l]].begin(), v[id[l]].end());
			if (id[l] != id[r]) {
				for (int i = 0; i < v[id[r]].size(); i++)
					if (v[id[r]][i].se >= l && v[id[r]][i].se <= r) v[id[r]][i].fi += x;
				sort(v[id[r]].begin(), v[id[r]].end());
			}
		} else {
			ll y;
			scanf("%lld", &y);
			int l = n + 1, r = 0;
			for (int i = 0; i <= id[n]; i++) {
				x = y - ad[i];
				if (lower_bound(v[i].begin(), v[i].end(), mp(x, 0)) == v[i].end()) continue;
				if (lower_bound(v[i].begin(), v[i].end(), mp(x, 0))->fi != x) continue;
				l = min(l, lower_bound(v[i].begin(), v[i].end(), mp(x, 0))->se);
				int sb = lower_bound(v[i].begin(), v[i].end(), mp(x, n + 1)) - v[i].begin(); sb--;
				r = max(r, v[i][sb].se);
			}
			if (l > r) printf("-1\n");
			else printf("%d\n", r - l);
		}
	}
	return 0;
}