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
int n, m, x[N][N];
ll a[4][N][N];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &x[i][j]);
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= m; j++) 
			a[0][i][j] = max(a[0][i - 1][j], a[0][i][j - 1]) + x[i][j];
	for (int i = n; i >= 1; i--)
		for (int j = m; j >= 1; j--)
			a[1][i][j] = max(a[1][i + 1][j], a[1][i][j + 1]) + x[i][j];
	for (int i = 1; i <= n; i++)
		for (int j = m; j >= 1; j--)
			a[2][i][j] = max(a[2][i - 1][j], a[2][i][j + 1]) + x[i][j];
	for (int i = n; i >= 1; i--)
		for (int j = 1; j <= m; j++)
			a[3][i][j] = max(a[3][i + 1][j], a[3][i][j - 1]) + x[i][j];
	ll ans = 0;
	for (int i = 2; i < n; i++)
		for (int j = 2; j < m; j++) {
			ans = max(ans, a[0][i - 1][j] + a[1][i + 1][j] + a[2][i][j + 1] + a[3][i][j - 1]);
			ans = max(ans, a[0][i][j - 1] + a[1][i][j + 1] + a[2][i - 1][j] + a[3][i + 1][j]);
		}
	printf("%lld\n", ans);
	return 0;
}