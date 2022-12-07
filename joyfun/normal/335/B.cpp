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

const int N = 50005;
char s[N];
int n, cnt[26];
int dp[2666][2666], p[N], fa[2666][2666][2];
char ans[N];

int main() {
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	for (int i = 1; i <= n; i++) 
		cnt[s[i] - 'a']++;
	for (int i = 0; i < 26; i++) if (cnt[i] >= 100) {
		for (int j = 0; j < 100; j++) printf("%c", i + 'a'); printf("\n");
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = n; j >= i; j--) {
			dp[i][j] = dp[i - 1][j];
			fa[i][j][0] = i - 1;
			fa[i][j][1] = j;
			if (dp[i][j] < dp[i][j + 1]) {
				dp[i][j] = dp[i][j + 1];
				fa[i][j][0] = i;
				fa[i][j][1] = j + 1;
			}
			if (s[i] == s[j]) {
				if (dp[i][j] < dp[i - 1][j + 1] + 1) {
					fa[i][j][0] = i - 1;
					fa[i][j][1] = j + 1;
					dp[i][j] = dp[i - 1][j + 1] + 1 + (i != j);
				}
			}
		}
	}
	int x = 0, y = 0;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) if (dp[x][y] < dp[i][j]) x = i, y = j;
	int len = dp[x][y], an = 0;
	int l = (len - 1) / 2, r = (len - 1) / 2;
	while (x && y <= n) {
		if (fa[x][y][0] != x && fa[x][y][1] != y) {
			ans[l--] = s[x];
			if (x != y) ans[++r] = s[y];
		}
		int xx = x, yy = y;
		x = fa[xx][yy][0]; y = fa[xx][yy][1];
	}
	an = len;
	l = 0, r = an - 1;
	while (r - l + 1 - 2 >= 100) {
		l++; r--;
	}
	for (int i = l; i <= r; i++) {
		if (r - l + 1 > 100 && i == (r + l) / 2) continue;
		printf("%c", ans[i]);
	}
	printf("\n");
	return 0;
}