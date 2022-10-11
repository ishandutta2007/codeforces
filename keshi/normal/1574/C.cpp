//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 2e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()

ll n, m, a[maxn], x, y, s;

int main(){
    fast_io;
    
    cin >> n;
    for(ll i = 0; i < n; i++){
    	cin >> a[i];
    	s += a[i];
	}
	cin >> m;
	sort(a, a + n);
	for(ll i = 0; i < m; i++){
		cin >> x >> y;
		ll j = lower_bound(a, a + n, x) - a;
		assert(a[n - 1] >= x || j == n);
		ll ans = inf;
		if(j < n) ans = min(ans, max(0ll, y - (s - a[j])));
		if(j) ans = min(ans, x - a[j - 1] + max(0ll, y - (s - a[j - 1])));
		cout << ans << "\n";
	}
 
    return 0;
}