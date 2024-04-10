#include <bits/stdc++.h>
using namespace std;


typedef long long ll;

const ll maxn = 5e4 + 100;
const ll maxm = 110;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, pre[maxn][maxm], dp[maxm], f[30], o;

pll par[maxn][maxm];

bool val[maxm];

string s, t;

int main(){
	fast_io;
	
	cin >> s;
	
	n = s.size();
	
	for(ll j = 0; j < 26; j++){
		pre[0][j] = inf;
		f[j] = inf;
	}
	
	for(ll i = 0; i < n; i++){
		f[s[i] - 'a'] = min(f[s[i] - 'a'], i);
		for(ll j = 0; j < 26; j++){
			pre[i + 1][j] = pre[i][j];
		}
		pre[i + 1][s[i] - 'a'] = i;
	}
	
	val[1] = 1;
	val[0] = 1;
	
	for(ll i = 1; i < n; i++){
		dp[0] = i;
		dp[1] = i - 1;
		par[i][1] = {i, i};
		for(ll j = 100; j > 1; j--){
			par[i][j] = par[i - 1][j];
			if(!val[j - 2])continue;
			if(f[s[i] - 'a'] >= dp[j - 2])continue;
			if(!val[j] || dp[j] < pre[dp[j - 2]][s[i] - 'a']){
				dp[j] = pre[dp[j - 2]][s[i] - 'a'];
				par[i][j].S = par[i - 1][j - 2].F;
				par[i][j].F = i;
			}
			val[j] = 1;
		}
	}
	dp[1] = n - 1;
	
	for(ll j = 100; j > 0; j--){
		if(val[j]){
			o = n - 1;
			for(ll k = j; k > 0; k -= 2){
				t += s[par[o][k].F];
				o = par[o][k].S;
			}
			cout << t;
			for(ll i = j / 2 - 1; i > -1; i--){
				cout << t[i];
			}
			return 0;
		}
	}
	
	return 0;
}