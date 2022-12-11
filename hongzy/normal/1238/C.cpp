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

const int N = 4e5 + 10;
const ll INF = 1e15;

int h, n, a[N];
ll dp[N][2];

int main() {
	ucin();
	int q; cin >> q;
	while(q --) {
		cin >> h >> n;
		for(int i = 1; i <= n; i ++) cin >> a[i];
		for(int i = 0; i <= n + 1; i ++) dp[i][0] = dp[i][1] = INF;		
		dp[1][1] = 0;
		for(int i = 2; i <= n; i ++) {
			if(a[i - 1] - 1 == a[i]) {
				dp[i][1] = min(dp[i - 1][0], dp[i][1] + 1);
				dp[i][0] = dp[i - 1][1];
			} else {
//				if(a[i - 1] - 2 == a[i]) {
//					dp[i][0] = min(dp[i][0], dp[i - 1][1]);
//				}
				dp[i][1] = min(dp[i][1], min(dp[i - 1][0] + 2, dp[i - 1][1] + 1));
				dp[i][0] = min(dp[i][0], dp[i - 1][0] + 1);
				dp[i][0] = min(dp[i][0], dp[i - 1][1]);
			}
//			printf("dp[%d] = %d, %d\n", i, dp[i][0], dp[i][1]);
		}
		ll ans = min(dp[n][1], dp[n][0] + (a[n] != 1));
		cout << ans << endl;
	}
	return 0;
}