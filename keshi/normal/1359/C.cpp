//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;
const long double eps = 1e-6;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll q;
long double h, c, t, n, np;

int main(){
	fast_io;
	
	cin >> q;
	while(q--){
		cin >> h >> c >> t;
		if(c + h >= t + t){
			cout << "2\n";
			continue;
		}
		if(t >= h){
			cout << "1\n";
			continue;
		}
		n = floor(((h - c) / (t + t - c - h) + 1) / 2);
		np = ceil(((h - c) / (t + t - c - h) + 1) / 2);
		if(n < 1) n = 1;
		if(np < 1) np = 1;
		if(abs((c + h) / 2 + (h - c) / (4 * n - 2) - t) <= abs((c + h) / 2 + (h - c) / (4 * np - 2) - t)){
			cout << ll(2 * n - 1);
		}
		else cout << ll(2 * np - 1);
		cout << '\n';
	}
	
	return 0;
}