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

ll k, d, t, e, f, ans;

int main(){
	fast_io;
	
	cin >> k >> d >> t;
	e = (d - k % d) % d;
	f = (t + t) % (k + k + e);
	ans += 2 * ((t + t) / (k + k + e)) * ((k + d - 1) / d) * d;
	if(f <= k + k) ans += f;
	else ans += 2 * (f - k);
	
	cout << ans / 2;
	if(ans & 1) cout << ".5";
	
	return 0;
}