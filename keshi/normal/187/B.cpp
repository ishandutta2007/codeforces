//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 70;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, r, a[maxn][maxn][maxn], b[maxn][maxn][maxn], c[maxn][maxn][maxn], s, t, x;

int main(){
	fast_io;
	
	memset(b, 63, sizeof b);
	memset(c, 63, sizeof c);
	
	cin >> n >> m >> r;
	
	for(ll i = 0; i < m; i++){
		for(ll j = 0; j < n; j++){
			for(ll k = 0; k < n; k++){
				cin >> a[i][j][k];
				b[i][j][k] = a[i][j][k];
			}
			b[i][j][j] = 0;
		}
	}
	
	for(ll l = 0; l < m; l++){
		for(ll k = 0; k < n; k++){
			for(ll i = 0; i < n; i++){
				for(ll j = 0; j < n; j++){
					b[l][i][j] = min(b[l][i][j], b[l][i][k] + b[l][k][j]);
					c[0][i][j] = min(c[0][i][j], b[l][i][j]);
				}
			}
		}
	}
	
	for(ll k = 1; k < n; k++){
		for(ll i = 0; i < n; i++){
			for(ll j = 0; j < n; j++){
				for(ll l = 0; l < n; l++){
					c[k][i][j] = min(c[k][i][j], c[0][i][l] + c[k - 1][l][j]);
				}
			}
		}
	}
	
	for(ll i = 0; i < r; i++){
		cin >> s >> t >> x;
		cout << c[min(n - 1, x)][s - 1][t - 1] << '\n';
	}
	
	return 0;
}