//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef int ll;

const ll maxn = 1e6 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e9;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m;

set<ll>::iterator itr;

int main(){
	fast_io;
	
	cin >> n >> m;
	
	
	char s[n + 10][m + 10];
	ll dp[n + 10][m + 10], dp2[n + 10][m + 10];
	bool f[n + 10][m + 10], d[n + 10][m + 10];
	
	for(ll i = 1; i <= n; i++){
		for(ll j = 1; j <= m; j++){
			cin >> s[i][j];
			f[i][j] = (s[i][j] == 'X');
		}
	}
	
	for(ll i = 1; i <= n; i++){
		for(ll j = 1; j <= m; j++){
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1]) + f[i][j];
		}
	}
	
	ll l = 0, r = min(n + 1, m + 1) / 2, x, y;
	
	while(r - l > 1){
		x = (l + r) / 2;
		for(ll i = 0; i <= n; i++){
			for(ll j = 0; j <= m; j++){
				d[i][j] = 0;
				dp2[i][j] = 0;
			}
		}
		for(ll i = x + 1; i <= n - x; i++){
			for(ll j = x + 1; j <= m - x; j++){
				if(dp[i + x][j + x] + dp[i - x - 1][j - x - 1] - dp[i + x][j - x - 1] - dp[i - x - 1][j + x] == (2 * x + 1) * (2 * x + 1)){
					d[i][j] = 1;
					dp2[i + x + 1][j + x + 1]++;
					dp2[i - x][j - x]++;
					dp2[i - x][j + x + 1]--;
					dp2[i + x + 1][j - x]--;
				}
			}
		}
		bool o = 1;
		for(ll i = 1; i <= n; i++){
			for(ll j = 1; j <= m; j++){
				dp2[i][j] += dp2[i][j - 1] + dp2[i - 1][j] - dp2[i - 1][j - 1];
				if((dp2[i][j] > 0) != f[i][j]) o = 0;
			}
		}
		if(o) l = x;
		else r = x;
	}
	
	cout << l << '\n';;
	
	x = l;
	for(ll i = 1; i <= n; i++){
		for(ll j = 1; j <= m + 1; j++){
			d[i][j] = 0;
		}
	}
	for(ll i = x + 1; i <= n - x; i++){
		for(ll j = x + 1; j <= m - x; j++){
			if(dp[i + x][j + x] + dp[i - x - 1][j - x - 1] - dp[i + x][j - x - 1] - dp[i - x - 1][j + x] == (2 * x + 1) * (2 * x + 1)){
				d[i][j] = 1;
			}
		}
	}
	
	for(ll i = 1; i <= n; i++){
		for(ll j = 1; j <= m; j++){
			cout << (d[i][j] ? 'X' : '.');
		}
		cout << '\n';
	}
	
	return 0;
}