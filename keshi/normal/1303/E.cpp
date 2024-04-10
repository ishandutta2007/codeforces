//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 420;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll q, n, m, dp[maxn][maxn];

bool f;

string s, t;

int main(){
	fast_io;
	
	fill(dp[0], dp[0] + maxn, -inf);
	dp[0][0] = 0;
	
	cin >> q;
	
	while(q--){
		cin >> s >> t;
		n = s.size();
		m = t.size();
		f = 0;
		for(ll k = 1; k <= m; k++){
			for(ll i = 1; i <= n; i++){
				for(ll j = 0; j <= k; j++){
					dp[i][j] = dp[i - 1][j];
					if(j && s[i - 1] == t[j - 1]) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
					if(k + dp[i - 1][j] >= 0 && k + dp[i - 1][j] < m && s[i - 1] == t[k + dp[i - 1][j]]) dp[i][j] = max(dp[i][j], dp[i - 1][j] + 1);
				}
			}
			if(dp[n][k] >= m - k) f = 1;
		}
		if(f) cout << "YES";
		else cout << "NO";
		cout << '\n';
	}
	
	return 0;
}