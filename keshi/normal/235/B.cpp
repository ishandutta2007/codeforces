//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n;

ld dp, p, ans;

int main(){
	fast_io;
	
	cout << setprecision(10) << fixed;
	
	cin >> n;
	
	for(ll i = 0; i < n; i++){
		cin >> p;
		dp = (dp + 1) * p;
		ans += dp * 2 - p;
	}
	
	cout << ans;
	
	return 0;
}