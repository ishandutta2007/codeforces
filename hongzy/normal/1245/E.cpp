#include <bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define mp make_pair
#define pb push_back
#define ucin() ios :: sync_with_stdio(0)
typedef vector<int> vi;
typedef map<int, int> mii;
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long double ld;
typedef long long ll;
typedef double db;
 
const int N = 12, n = 10;
const int S[] = {1, 4, 9, 16, 25, 36};
int a[N][N], st[N][N], pp[N * N];
db dp[N * N];
pii pos[N * N];
int main() {
	int qwq = 0; dp[0] = 23333333;
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= n; j ++)
			scanf("%d", &a[i][j]);
		if(i & 1) {
			for(int j = 1; j <= n; j ++) {
				st[i][j] = ++ qwq;
				pos[qwq] = pii(i, j);
			}
		} else {
			for(int j = n; j >= 1; j --) {
				st[i][j] = ++ qwq;
				pos[qwq] = pii(i, j);
			}
		}
		for(int j = 1; j <= n; j ++)
			if(a[i][j]) {
				a[i][j] = i - a[i][j];
				pp[st[i][j]] = st[a[i][j]][j];
			}
	}
	for(int t = 2; t <= qwq; t ++) {
		db k = 1; dp[t] = 1;
		for(int j = 1; j <= 6; j ++) {
			if(t - j < 1) {
				k -= 1.0 / 6;
			} else {
				int p = t - j;
				dp[t] += min(dp[p], dp[pp[p]]) / 6.0;
			}
		}
		dp[t] /= k;
	}
	printf("%.9f\n", dp[st[n][1]]);
	return 0;
}