//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1e3 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, a[maxn], b[maxn][maxn], g;

int main(){
	fast_io;
	
	cin >> n;
	
	for(ll i = 0; i < n; i++){
		for(ll j = 0; j < n; j++){
			cin >> b[i][j];
		}
	}
	
	a[0] = (b[0][1] * b[0][2]) / b[1][2];
	a[0] = sqrt(a[0]);
	
	cout << a[0] << " ";
	
	for(ll i = 1; i < n; i++){
		cout << b[0][i] / a[0] << " ";
	}
	
	return 0;
}