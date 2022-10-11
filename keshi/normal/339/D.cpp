#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 100;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;

#define ll long long
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, p, b, a[18][MAXN];

int main(){
	fast_io;
	
	cin >> n >> m;
	
	for(ll i = 0; i < (1 << n); i++){
		cin >> a[0][i];
	}
	
	for(ll i = 1; i <= n; i++){
		for(ll j = 0; j < (1 << (n - i)); j++){
			if(i % 2){
				a[i][j] = a[i - 1][2 * j] | a[i - 1][2 * j + 1];
			}
			else{
				a[i][j] = a[i - 1][2 * j] ^ a[i - 1][2 * j + 1];
			}
		}
	}
	
	for(ll i = 0; i < m; i++){
		cin >> p >> b;
		p--;
		a[0][p] = b;
		for(ll j = 1; j <= n; j++){
			p /= 2;
			if(j % 2){
				a[j][p] = a[j - 1][2 * p] | a[j - 1][2 * p + 1];
			}
			else{
				a[j][p] = a[j - 1][2 * p] ^ a[j - 1][2 * p + 1];
			}
		}
		cout << a[n][0] << endl;
	}
	
	return 0;
}