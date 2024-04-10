#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define pb push_back
#define F first
#define S second
#define sd(x) scanf("%d", &(x))
#define print(s) cerr<<#s<<" : ";for(auto i:(s))cerr<<i<<" ";cerr<<"\n";

const int N = 2005, mod = 1e9 + 7;
vector<int> divs[N];
int dp[N][N];
int main(){
	for(int i = 1; i < N; i++)
		for(int j = i; j < N; j += i)
			divs[j].pb(i);
	int n, k;
	cin >> n >> k;
	dp[0][1] = 1;
	for(int i = 1; i <= k; i++){
		for(int j = 1; j <= n; j++){
			for(int k : divs[j]){
				dp[i][j] += dp[i - 1][k];
				if(dp[i][j] >= mod)
					dp[i][j] -= mod;
			}
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; i++)
		ans = (ans + dp[k][i]) % mod;
	cout << ans;
}