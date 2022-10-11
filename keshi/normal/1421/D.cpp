//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 4e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second

ll t, c[6], xx, yy;
ll a[6][2] = {{1, 1}, {0, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, 0}};

ll get(ll i, ll j){
	ll x = xx, y = yy;
	if(a[i][0] == 0){
		if(a[j][0] * x < 0) return inf;
		y -= a[j][1] * abs(x);
		if(a[i][1] * y < 0) return inf;
		return abs(x) * c[j] + abs(y) * c[i];
	}
	if(a[i][1] == 0){
		if(a[j][1] * y < 0) return inf;
		x -= a[j][0] * abs(y);
		if(a[i][0] * x < 0) return inf;
		return abs(x) * c[i] + abs(y) * c[j];
	}
	return inf;
}

int main(){
    fast_io;

	cin >> t;
	while(t--){
		cin >> xx >> yy;
		for(ll i = 0; i < 6; i++){
			cin >> c[i];
		}
		ll ans = inf;
		for(ll i = 0; i < 6; i++){
			ans = min(ans, min(min(get(i, (i + 1) % 6), get((i + 1) % 6, i)), min(get(i, (i + 2) % 6), get((i + 2) % 6, i))));
		}
		cout << ans << '\n';
	}

    return 0;
}