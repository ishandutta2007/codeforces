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

typedef unsigned long long ull;
const int N = 5005;
const int inf = 0x3f3f3f3f;
int dp[3][N][N];
char s1[N], s2[N];
int l1[N], l2[N];

void get(char *s1, char *s2, int dp[N][N]) {
	int n = strlen(s1 + 1), m = strlen(s2 + 1);
	for (int i = n; i >= 1; i--) {
		for (int j = m; j >= 1; j--) {
			if (s1[i] == s2[j]) dp[i][j] = dp[i + 1][j + 1] + 1;
			else dp[i][j] = 0;
		}
	}
}

int main() {
	scanf("%s%s", s1 + 1, s2 + 1);
	get(s1, s1, dp[0]); get(s2, s2, dp[1]); get(s1, s2, dp[2]);
	int n = strlen(s1 + 1), m = strlen(s2 + 1);
	for (int i = 1; i <= n; i++) {
		l1[i] = 1;
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			l1[i] = max(l1[i], dp[0][i][j] + 1);
		}
		if (l1[i] > n - i + 1) l1[i] = -1;
	}
	for (int i = 1; i <= m; i++) {
		l2[i] = 1;
		for (int j = 1; j <= m; j++) {
			if (i == j) continue;
			l2[i] = max(l2[i], dp[1][i][j] + 1);
		}
		if (l2[i] > m - i + 1) l2[i] = -1;
	}
	int ans = inf;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (l1[i] == -1 || l2[j] == -1) continue;
			if (dp[2][i][j] < max(l1[i], l2[j])) continue;
			ans = min(ans, max(l1[i], l2[j]));
		}
	}
	if (ans == inf) ans = -1;
	printf("%d\n", ans);
	return 0;
}