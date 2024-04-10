//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 500;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll t, n, k, a[maxn][maxn], x, y;

int main(){
	fast_io;
	
	cin >> t;
	while(t--){
		cin >> n >> k;
		for(ll i = 0; i < n; i++){
			fill(a[i], a[i] + n, 0);
		}
		if(k % n == 0) cout << "0\n";
		else cout << "2\n";
		x = y = 0;
		for(ll i = 0; i < k; i++){
			a[x % n][y % n] = 1;
			x++;
			y++;
			if((i + 1) % n == 0) y++;
		}
		for(ll i = 0; i < n; i++){
			for(ll j = 0; j < n; j++){
				cout << a[i][j];
			}
			cout << '\n';
		}
	}
	
	return 0;
}