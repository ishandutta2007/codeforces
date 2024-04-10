#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define pb push_back
#define F first
#define S second
#define sd(x) scanf("%d", &(x))
#define print(s) cerr<<#s<<" : ";for(auto i:(s))cerr<<i<<" ";cerr<<"\n";

const int N = 1005;
int dp[N], p[N];
const int mod = 1e9 + 7;
int main(){
	int n;
	cin >> n;
	for(int i = 1; i <= n + 1; i++){
		if(i <= n) cin >> p[i];
		if(i > 1) dp[i] = ((2 * dp[i - 1] + 2 - dp[p[i - 1]]) % mod + mod) % mod;
	}
	cout << dp[n + 1];
}