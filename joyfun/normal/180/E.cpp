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

const int N = 222222;
int n, m, k;
vi c[N];

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++) {
		int x; scanf("%d", &x);
		c[x].pb(i);
	}
	int ans = 0;
	for (int i = 1; i <= m; i++) {
		int r = 0;
		for (int j = 0; j < sz(c[i]); j++) {
			while (r + 1 < sz(c[i]) && c[i][r + 1] - c[i][j] + 1 - (r + 1 - j + 1) <= k) r++;
			ans = max(ans, r - j + 1);
		}
	}
	printf("%d\n", ans);
	return 0;
}