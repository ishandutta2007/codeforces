//In the name of GOD
//Harsh Revenge
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 350;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, k, s, d[maxn][maxn];

int main(){
	ll v, u, c;
	fast_io;
	
	cin >> n;
	
	for(ll i = 1; i <= n; i++){
		for(ll j = 1; j <= n; j++){
			cin >> d[i][j];
		}
	}
	
	cin >> k;
	
	for(ll i = 0; i < k; i++){
		cin >> v >> u >> c;
		d[v][u] = min(d[v][u], c);
		d[u][v] = d[v][u];
		s = 0;
		for(ll i = 1; i <= n; i++){
			for(ll j = 1; j <= n; j++){
				d[i][j] = min(d[i][j], min(d[i][v] + d[v][u] + d[u][j], d[i][u] + d[u][v] + d[v][j]));
				s += d[i][j];
			}
		}
		cout << s / 2 << " ";
	}
	
	return 0;
}