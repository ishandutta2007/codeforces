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

const int N = 5005;
const int inf = 0x3f3f3f3f;
int n, id[N];
pii g[N];
vi ans;

bool cmp(int a, int b) {
	return g[a] < g[b];
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d%d", &g[i].fi, &g[i].se), id[i] = i;
	sort(id + 1, id + 1 + n, cmp);
	for (int ii = 1; ii <= n; ii++) {
		int i = id[ii];
		int r = -inf;
		int f = 1;
		for (int jj = 1; jj <= n; jj++) {
			if (ii == jj) continue;
			int j = id[jj];
			if (r > g[j].fi) {
				f = 0;
				break;
			}
			r = max(r, g[j].se);
		}
		if (f) ans.pb(i);
	}
	printf("%d\n", sz(ans));
	sort(ans.begin(), ans.end());
	for (int i = 0; i < sz(ans); i++) printf("%d ", ans[i]);
	return 0;
}