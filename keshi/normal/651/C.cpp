#include <bits/stdc++.h>
using namespace std;


typedef long long ll;

const ll maxn = 60;
const ll mod = 1e9;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define X first
#define Y second

ll n, ans;
pll a;
map<ll, ll> x, y;
map<pll, ll> b;

int main(){
	fast_io;
	
	cin >> n;
	
	for(ll i = 0; i < n; i++){
		cin >> a.X >> a.Y;
		ans += x[a.X];
		x[a.X]++;
		ans += y[a.Y];
		y[a.Y]++;
		ans -= b[a];
		b[a]++;
	}
	
	cout << ans;
	
	return 0;
}