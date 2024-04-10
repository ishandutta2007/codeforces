//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 210;
const ll maxm = 500;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, x, dp[maxn][maxn][maxm], a, b;

string s, t, ans;

char par[maxn][maxn][maxm];

int main(){
	fast_io;
	
	cin >> s >> t;
	n = s.size();
	m = t.size();
	s = ' ' + s;
	t = ' ' + t;
	
	for(ll k = 0; k < maxn; k++){
		dp[0][0][k] = k;
		par[0][0][k] = '(';
	}
	for(ll i = 0; i <= n; i++){
		for(ll j = 0; j <= m; j++){
			if(i + j == 0) continue;
			if(s[i] == '(' || t[j] == '('){
				for(ll k = maxm; k--;){
					dp[i][j][k] = inf;
					if(k + 1 < maxm && dp[i][j][k] > dp[i - (s[i] == ')')][j - (t[j] == ')')][k + 1] + 1) dp[i][j][k] = dp[i - (s[i] == ')')][j - (t[j] == ')')][k + 1] + 1, par[i][j][k] = ')';
					if(k && dp[i][j][k] > dp[i - (s[i] == '(')][j - (t[j] == '(')][k - 1] + 1) dp[i][j][k] = dp[i - (s[i] == '(')][j - (t[j] == '(')][k - 1] + 1, par[i][j][k] = '(';
				}
			}
			else{
				for(ll k = 0; k < maxm; k++){
					dp[i][j][k] = inf;
					if(k + 1 < maxm && dp[i][j][k] > dp[i - (s[i] == ')')][j - (t[j] == ')')][k + 1] + 1) dp[i][j][k] = dp[i - (s[i] == ')')][j - (t[j] == ')')][k + 1] + 1, par[i][j][k] = ')';
					if(k && dp[i][j][k] > dp[i - (s[i] == '(')][j - (t[j] == '(')][k - 1] + 1) dp[i][j][k] = dp[i - (s[i] == '(')][j - (t[j] == '(')][k - 1] + 1, par[i][j][k] = '(';
				}
			}
		}
	}
	
	x = 0;
	while(x + n + m){
		ans += par[n][m][x];
		if(par[n][m][x] == '(') b = -1;
		else b = 1;
		a = (s[n] == par[n][m][x]);
		m -= (t[m] == par[n][m][x]);
		n -= a;
		x += b;
	}
	
	reverse(ans.begin(), ans.end());
	
	cout << ans;
	
	return 0;
}