//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef int ll;

const ll maxn = 510;
const ll maxm = 676;
const ll mod = 1e9 + 7;
const ll inf = 1e9;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, a[2][26], dp[maxn][maxm], par[maxn][maxm];

string s[maxn];

char e[2][maxn];

int main(){
	fast_io;
	
	cin >> n >> m;
	
	for(ll i = 1; i <= n; i++){
		cin >> s[i];
	}
	
	for(ll i = 1; i <= n; i++){
		fill(a[0], a[0] + 26, 0);
		fill(a[1], a[1] + 26, 0);
		for(ll j = 0; j < m; j++){
			a[j % 2][s[i][j] - 'a']++;
		}
		for(ll j = 0; j < 26; j++){
			for(ll k = 0; k < 26; k++){
				dp[i][j * 26 + k] = -inf;
				if(j == k) continue;
				for(ll j2 = 0; j2 < 26; j2++){
					if(j == j2) continue;
					for(ll k2 = 0; k2 < 26; k2++){
						if(k == k2) continue;
						if(dp[i][j * 26 + k] < a[0][j] + a[1][k] + dp[i - 1][j2 * 26 + k2]){
							dp[i][j * 26 + k] = a[0][j] + a[1][k] + dp[i - 1][j2 * 26 + k2];
							par[i][j * 26 + k] = j2 * 26 + k2;
						}
					}
				}
			}
		}
	}
	
	ll ans = -1, x;
	
	for(ll j = 0; j < 26; j++){
		for(ll k = 0; k < 26; k++){
			if(dp[n][j * 26 + k] > ans){
				ans = dp[n][j * 26 + k];
				x = j * 26 + k;
			}
		}
	}
	
	cout << n * m - ans << '\n';
	
	for(ll i = n; i > 0; i--){
		e[0][i] = 'a' + x / 26;
		e[1][i] = 'a' + x % 26;
		x = par[i][x];
	}
	
	for(ll i = 1; i <= n; i++){
		for(ll j = 0; j < m; j++){
			cout << e[j % 2][i];
		}
		cout << '\n';
	}
	
	return 0;
}