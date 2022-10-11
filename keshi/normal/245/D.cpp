//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1e2 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, a[maxn][maxn];

int main(){
	fast_io;
	
	cin >> n;
	
	for(ll i = 0; i < n; i++){
		for(ll j = 0; j < n; j++){
			cin >> a[i][j];
		}
		a[i][i] = 0;
	}
	
	for(ll i = 0; i < n; i++){
		for(ll j = 0; j < n; j++){
			a[i][i] |= a[i][j];
		}
		cout << a[i][i] << " ";
	}
	
	
	
	return 0;
}