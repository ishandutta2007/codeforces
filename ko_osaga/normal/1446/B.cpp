#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 5005;

int n, m;
char s[MAXN], t[MAXN];
int dp[MAXN][MAXN];

int main(){
	cin >> n >> m >> (s + 1) >> (t + 1);
	int ret = 0;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			if(s[i] == t[j]){
				dp[i][j] = max(dp[i-1][j-1] + 2, dp[i][j]);
			}
			dp[i][j] = max({dp[i-1][j] - 1, dp[i][j-1] - 1, dp[i][j]});
			ret = max(ret, dp[i][j]);
		}
	}
	cout << ret << endl;
}