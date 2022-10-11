#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1e6 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, dp[2][5];

string s;

int main(){
	fast_io;
	
	cin >> s;
	
	n = s.size();
	
	if(s[0] == '0' || s[0] == '?') dp[0][0] = 1;
	if(s[0] == '1' || s[0] == '?') dp[0][1] = 1;
	if(s[0] == '*' || s[0] == '?') dp[0][4] = 1;
	
	for(ll i = 1; i < n; i++){
		dp[i % 2][0] = (dp[(i - 1) % 2][0] + dp[(i - 1) % 2][2]) % mod;
		dp[i % 2][1] = (dp[(i - 1) % 2][0] + dp[(i - 1) % 2][2]) % mod;
		dp[i % 2][2] = dp[(i - 1) % 2][4];
		dp[i % 2][3] = dp[(i - 1) % 2][4];
		dp[i % 2][4] = (dp[(i - 1) % 2][1] + dp[(i - 1) % 2][3] + dp[(i - 1) % 2][4]) % mod;
		if(s[i] == '*'){
			dp[i % 2][0] = 0;
			dp[i % 2][1] = 0;
			dp[i % 2][2] = 0;
			dp[i % 2][3] = 0;
		}
		if(s[i] == '0'){
			dp[i % 2][4] = 0;
			dp[i % 2][1] = 0;
			dp[i % 2][2] = 0;
			dp[i % 2][3] = 0;
		}
		if(s[i] == '1'){
			dp[i % 2][0] = 0;
			dp[i % 2][3] = 0;
			dp[i % 2][4] = 0;
		}
		if(s[i] == '2'){
			dp[i % 2][0] = 0;
			dp[i % 2][1] = 0;
			dp[i % 2][2] = 0;
			dp[i % 2][4] = 0;
		}
	}
	
	cout << (dp[(n - 1) % 2][0] + dp[(n - 1) % 2][2] + dp[(n - 1) % 2][4]) % mod;
	
	return 0;
}