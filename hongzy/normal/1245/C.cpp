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

const int N = 1e5 + 10;
const int mo = 1e9 + 7;

int main() {
	ucin();
	static char s[N];
	static int dp[N];
	cin >> s + 1;
	int n = strlen(s + 1);
	dp[0] = 1;
	for(int i = 1; i <= n; i ++) {
		if(s[i] == 'w' || s[i] == 'm') {
			cout << 0;
			return 0;
		}
		dp[i] = dp[i - 1];
		if(i > 1 && s[i - 1] == s[i] && (s[i] == 'u' || s[i] == 'n')) {
			(dp[i] += dp[i - 2]) %= mo;
		}
	}
	cout << dp[n] << '\n';
	return 0;
}