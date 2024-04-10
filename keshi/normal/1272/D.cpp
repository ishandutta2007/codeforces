//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, ans, a[maxn], dp[maxn][2];

int main(){
	fast_io;
	
	cin >> n;
	
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	dp[1][0] = 1;
	dp[1][1] = 1;
	ans = 1;
	
	for(ll i = 2; i <= n; i++){
		dp[i][0] = 1;
		dp[i][1] = 1;
		if(a[i] > a[i - 1]){
			dp[i][0] = max(dp[i][0], dp[i - 1][0] + 1);
			dp[i][1] = max(dp[i][1], dp[i - 1][1] + 1);
		}
		if(a[i] > a[i - 2]){
			dp[i][1] = max(dp[i][1], dp[i - 2][0] + 1);
		}
		ans = max(ans, max(dp[i][0], dp[i][1]));
	}
	
	cout << ans;
	
	return 0;
}