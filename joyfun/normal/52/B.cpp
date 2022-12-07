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
int n, m;
char g[N][N];
int r[N], c[N];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%s", g[i] + 1);
		for (int j = 1; j <= m; j++)
			if (g[i][j] == '*') r[i]++, c[j]++;
	}
	ll ans = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (g[i][j] == '*') ans += (r[i] - 1) * (c[j] - 1);
	printf("%lld\n", ans);
	return 0;
}