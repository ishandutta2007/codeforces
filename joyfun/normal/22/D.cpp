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

const int N = 1005;
const int inf = 0x3f3f3f3f;
int n, l[N], r[N], vis[N];
vi ans;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) { 
		scanf("%d%d", &l[i], &r[i]);
		if (l[i] > r[i]) swap(l[i], r[i]);
	}
	int cnt = 0;
	while (cnt < n) {
		int Min = inf;
		for (int i = 0; i < n; i++) if (!vis[i]) Min = min(Min, r[i]);
		ans.pb(Min);
		for (int i = 0; i < n; i++) if (!vis[i] && l[i] <= Min && r[i] >= Min) {
			vis[i] = 1; 
			cnt++;
		}
	}
	printf("%d\n", sz(ans));
	for (int i = 0; i < sz(ans); i++) printf("%d ", ans[i]);
	return 0;
}