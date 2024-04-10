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
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, ans, dp[maxn], ps1[maxn], ps2[maxn], k;

string s, sp, t;

int main(){
	fast_io;
	
	cin >> sp >> m;
	n = sp.size();
	for(ll i = 0; i < m; i++){
		cin >> t;
		if(t.size() == 1) continue;
		s = t + '?' + sp;
		dp[0] = k = 0;
		for(ll i = 1; i < s.size(); i++){
			while(k && s[i] != s[k]) k = dp[k - 1];
			if(s[i] == s[k]) k++;
			dp[i] = k;
			if(i >= t.size()) ps1[i] = max(ps1[i - 1], dp[i]);
			else ps1[i] = 0;
		}
		s = sp + '?' + t;
		reverse(s.begin(), s.end());
		dp[0] = k = 0;
		for(ll i = 1; i < s.size(); i++){
			while(k && s[i] != s[k]) k = dp[k - 1];
			if(s[i] == s[k]) k++;
			dp[i] = k;
			if(i >= t.size()) ps2[i] = max(ps2[i - 1], dp[i]);
			else ps2[i] = 0;
		}
		for(ll i = 0; i <= n; i++){
			if(ps1[t.size() + i] + ps2[t.size() + n - i] >= t.size()){
				ans++;
				break;
			}
		}
	}
	
	cout << ans;
	
	
	return 0;
}