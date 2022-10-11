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
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, x, y, f, f1, f2, f3, f4;
pll a = Mp(inf, -1);

int main(){
	fast_io;
	
	cin >> n >> m;
	cin >> n;
	f1 = f2 = f3 = f4 = -inf;
	for(ll i = 0; i < n; i++){
		cin >> x >> y;
		f1 = max(f1, x + y);
		f2 = max(f2, x - y);
		f3 = max(f3, -x + y);
		f4 = max(f4, -x - y);
	}
	cin >> m;
	for(ll i = 0; i < m; i++){
		cin >> x >> y;
		f = 0;
		f = max(f, x + y + f4);
		f = max(f, x - y + f3);
		f = max(f, -x + y + f2);
		f = max(f, -x - y + f1);
		a = min(a, Mp(f, i + 1));
	}
	cout << a.F << '\n' << a.S;
	
	return 0;
}