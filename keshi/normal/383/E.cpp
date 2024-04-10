//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef int ll;

const ll maxn = 24;
const ll maxm = 2e7;
const ll mod = 1e9 + 7;
const ll inf = 1e9;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, dp[maxm], ans;

void solve(string s){
	ll x, t, sz = s.size();
	for(ll i = 1; i < (1ll << sz); i++){
		x = t = 0;
		for(ll j = 0; j < sz; j++){
			if((i >> j) & 1) x += (1ll << (s[j] - 'a')), t++;
		}
		if(t % 2) dp[x]++;
		else dp[x]--;
	}
	return;
}

int main(){
	string s;
	fast_io;
	
	cin >> n;
	
	for(ll i = 0; i < n; i++){
		cin >> s;
		sort(s.begin(), s.end());
		if(s[0] == s[1]){
			if(s[1] == s[2]) solve(s.substr(1, 1));
			else solve(s.substr(1, 2));
		}
		else{
			if(s[1] == s[2]) solve(s.substr(0, 2));
			else solve(s);
		}
	}
	
	for(ll j = 0; j < maxn; j++){
		for(ll i = (1ll << maxn); i--;){
			if((i >> j) & 1) dp[i] += dp[i - (1ll << j)];
		}
	}
	
	for(ll i = 0; i < (1ll << maxn); i++){
		ans ^= dp[i] * dp[i];
	}
	
	cout << ans;
	
	return 0;
}