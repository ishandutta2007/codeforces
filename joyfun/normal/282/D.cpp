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
int n, a[4];
int dp[N][N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	int ret = 0;
	if (n == 1 || n == 3) {
		for (int i = 1; i <= n; i++) ret ^= a[i];
	} else {
		dp[0][0] = 0;
		for (int i = 0; i <= a[1]; i++) {
			for (int j = 0; j <= a[2]; j++) {
				if (dp[i][j]) continue;
				for (int k = 1; k <= 300; k++) {
					dp[i + k][j + k] = 1;
					dp[i + k][j] = 1;
					dp[i][j + k] = 1;
				}
			}
		}
		ret = dp[a[1]][a[2]];
	}
	printf("%s\n", ret ? "BitLGM" : "BitAryo");
	return 0;
}