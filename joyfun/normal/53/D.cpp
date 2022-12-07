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

const int N = 305;
int n, a[N], b[N];
vector<pii> ans;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
	for (int i = n, c = 0; i >= 1; i--, c++) {
		for (int j = 1; j <= n - c; j++) {
			if (a[i] == b[j]) {
				for (int k = j; k < i; k++) {
					ans.pb(mp(k, k + 1));
					swap(b[k], b[k + 1]);
				}
				break;
			}
		}
	}
//	for (int i = 1; i <= n; i++) printf("%d ", a[i]); printf("\n");
//	for (int i = 1; i <= n; i++) printf("%d ", b[i]); printf("\n");
	printf("%d\n", sz(ans));
	for (int i = 0; i < sz(ans); i++) printf("%d %d\n", ans[i].fi, ans[i].se);
	return 0;
}