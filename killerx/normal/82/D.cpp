#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector <int>
#define pii pair <int, int>
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i,n) for (int i = 0; i < (int) (n); ++ i)
#define foreach(it,c) for (__typeof(c.begin()) it = c.begin(); it != c.end(); ++ it)

inline int read() {
	int x = 0, f = 1, c = getchar();
	for (;!isdigit(c);c = getchar()) if (c == '-') f ^= 1;
	for (; isdigit(c);c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}

int n;
int t[1005];
int dp[505][1005];
pair <pii, int> prv[505][1005];

void prt(int i, int j) {
	if (i == 0) return;
	prt(i - 1, prv[i][j].second);
	printf("%d %d\n", prv[i][j].first.first + 1, prv[i][j].first.second + 1);
}

int main() {
	n = read();
	rep(i, n) t[i] = read();
	if (n == 1) {
		printf("%d\n%d\n", t[0], 1);
		return 0;
	}
	memset(dp, inf, sizeof dp);
	dp[0][0] = 0;
	rep(i, n / 2) {
		rep(j, i * 2 + 1) {
			vi arr; arr.pb(j);
			arr.pb(i * 2 + 1);
			if (i * 2 + 2 < n) arr.pb(i * 2 + 2);
			rep(s2, arr.size()) rep(s1, s2) {
				int lft = (arr.size() == 3 ? arr[3 - s1 - s2] : 1001);
				int ndp = dp[i][j] + max(t[arr[s1]], t[arr[s2]]);
				if ((n & 1) && i == n / 2 - 1) ndp += t[lft];
				if (dp[i + 1][lft] > ndp) {
					dp[i + 1][lft] = ndp;
					prv[i + 1][lft] = mp(mp(arr[s1], arr[s2]), j);
				}
			}
		}
	}
	int ans = inf;
	int ansi = 0;
	rep(j, 1005) if (ans > dp[n / 2][j]) {
		ans = dp[n / 2][j];
		ansi = j;
	}
	printf("%d\n", ans);
	prt(n / 2, ansi);
	if (ansi < n) printf("%d\n", ansi + 1);
	return 0;
}