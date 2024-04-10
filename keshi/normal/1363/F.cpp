//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 3e3 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll q, n, dp[maxn][maxn], ps[maxn][maxn], c[26][maxn], d[26][maxn];
string s, t;
bool f;

int main(){
	fast_io;
	
	cin >> q;
	while(q--){
		cin >> n >> s >> t;
		s = ' ' + s;
		t = ' ' + t;
		for(ll i = 1; i <= n; i++){
			for(ll j = 0; j < 26; j++){
				c[j][i] = c[j][i - 1];
				d[j][i] = d[j][i - 1];
			}
			c[s[i] - 'a'][i]++;
			d[t[i] - 'a'][i]++;
		}
		f = 0;
		for(ll i = 0; i < 26; i++){
			if(c[i][n] != d[i][n]) f = 1;
		}
		if(f){
			cout << "-1\n";
			continue;
		}
		for(ll i = 1; i <= n; i++){
			ps[i][i - 1] = inf;
			for(ll j = i; j <= n; j++){
				dp[i][j] = inf;
				if(s[i] == t[j]) dp[i][j] = min(dp[i][j], ps[i - 1][j - 1]);
				if(c[s[i] - 'a'][i] <= d[s[i] - 'a'][j - 1]) dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
				ps[i][j] = min(ps[i][j - 1], dp[i][j]);
			}
		}
		cout << dp[n][n] << '\n';
	}
	
	return 0;
}