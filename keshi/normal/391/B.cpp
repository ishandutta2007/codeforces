//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, dp[maxn], ans;

string s;

int main(){
	fast_io;
	
	cin >> s;
	
	n = s.size();
	
	for(ll i = n - 1; i > -1; i--){
		dp[i] = 1;
		for(ll j = i + 1; j < n; j += 2){
			if(s[i] == s[j]){
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		ans = max(ans, dp[i]);
	}
	
	cout << ans;
	
	return 0;
}