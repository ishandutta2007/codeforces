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

const int N = 100005;
int n, pri[N], pn, vis[N];
int tmp[N], tn;
vector<pii> ans;

int main() {
	for (int i = 2; i < N; i++) {
		if (vis[i]) continue;
		pri[pn++] = i;
		if (1ll * i * i >= 1ll * N) continue;
		for (int j = i * i; j < N; j += i)
			vis[j] = 1;
	}
	scanf("%d", &n);
	memset(vis, 0, sizeof(vis));
	for (int i = pn - 1; i >= 0; i--) {
		tn = 0;
		for (int j = pri[i]; j <= n; j += pri[i]) {
			if (vis[j]) continue;
			tmp[tn++] = j;
		}
		if (tn % 2) swap(tmp[1], tmp[tn - 1]);
		for (int i = 0; i < tn - 1; i += 2) {
			vis[tmp[i]] = vis[tmp[i + 1]] = 1;
			ans.pb(mp(tmp[i], tmp[i + 1]));
		}
	}
	printf("%d\n", sz(ans));
	for (int i = 0; i < sz(ans); i++) printf("%d %d\n", ans[i].fi, ans[i].se);
	return 0;
}