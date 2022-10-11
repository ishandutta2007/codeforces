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

ll n, s, c[2];
pll a[maxn];

int main(){
	fast_io;
	
	cin >> n;
	for(ll i = 0; i < n; i++){
		cin >> a[2 * i].F;
		a[2 * i].S = 0;
		cin >> a[2 * i + 1].F;
		a[2 * i + 1].S = 1;
	}
	sort(a, a + 2 * n, greater<pll>());
	for(ll i = 0; i < 2 * n; i++){
		if(c[1 - a[i].S]) c[1 - a[i].S]--;
		else c[a[i].S]++, s += a[i].F;
	}
	cout << n + s;
	
	return 0;
}