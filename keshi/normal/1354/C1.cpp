//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;
const ld pi = 3.1415926535897932384626433;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll t, n;

int main(){
	fast_io;
	cout << setprecision(20) << fixed;
	
	cin >> t;
	
	while(t--){
		cin >> n;
		cout << cos(pi / 2 / n) / sin(pi / 2 / n) << '\n';
	}
	
	return 0;
}