//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll t, n, x, y;

int main(){
	fast_io;
	
	cin >> t;
	
	while(t--){
		cin >> n >> x >> y;
		if(x == n && y == n) cout << n << " " << n << '\n';
		else cout << max(1ll, x + y - n + 1) << " " << min(n, x + y - 1) << '\n';
	}
	
	return 0;
}