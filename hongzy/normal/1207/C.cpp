#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define fs first
#define sc second
#define ucin() ios :: sync_with_stdio(0)

typedef map<int, int> mii;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long long ll;
typedef double db;

const int N = 2e5 + 10;
const ll INF = 1e17;

char s[N];
int a, b, n;
ll dp[N][2]; //b zhu

int main() {
	ucin();
	int t; cin >> t;
	while(t --) {
		cin >> n >> a >> b >> s + 1; s[n + 1] = '0';
		dp[0][0] = b; dp[0][1] = INF;
		for(int i = 1; i <= n; i ++) {
			dp[i][0] = min(dp[i - 1][0] + a, dp[i - 1][1] + 2 * a) + b;
			dp[i][1] = min(dp[i - 1][1] + a, dp[i - 1][0] + 2 * a) + 2 * b;
			if(s[i] == '1' || s[i + 1] == '1') dp[i][0] = INF;
		}
		cout << dp[n][0] << endl;
	}
	return 0;
}