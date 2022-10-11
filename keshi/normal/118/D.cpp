#include <bits/stdc++.h>
using namespace std;

const int MAXN = 110;
const long long MOD = 1e8;
const long long INF = 1e18;

#define ll long long
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define X first
#define Y second

ll n1, n2, n, k1, k2, a[MAXN][MAXN], b[MAXN][MAXN];

int main(){
	fast_io;
	n = 101;
	
	cin >> n1 >> n2 >> k1 >> k2;
	
	a[0][0] = 1;
	b[0][0] = 1;
	
	for(ll i = 0; i < n; i++){
		for(ll j = 0; j < n; j++){
			for(ll k = 1; k <= k1 && (i - k) >= 0; k++){
				a[i][j] += b[i - k][j];
				a[i][j] %= MOD;
			}
			for(ll k = 1; k <= k2 && (j - k) >= 0; k++){
				b[i][j] += a[i][j - k];
				b[i][j] %= MOD;
			}
		}
	}
	
	cout << (a[n1][n2] + b[n1][n2]) % MOD;
	
	return 0;
}