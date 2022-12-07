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
const ll inf = (1ll<<60);
int n;
ll h[N], dp[N][N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%lld", &h[i]), h[i] += h[i - 1];
	for (int i = 0; i <= n; i++) for (int j = 0; j < i; j++) dp[i][j] = inf;
	dp[1][0] = h[1];
	for (int i = 1; i <= n; i++) {
		int v = i;
		for (int j = i - 1; j >= 0; j--) {
			if (dp[i][j] == inf) continue;
			dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + h[i + 1] - h[i]);
			while (v <= n && h[v] - h[i] < dp[i][j]) v++;
			if (v <= n) dp[v][j + 1] = min(dp[v][j + 1], h[v] - h[i]);
		}
	}
	for (int i = n - 1; i >= 0; i--) if (dp[n][i] != inf) {printf("%d\n", n - i - 1); break;}
	return 0;
}