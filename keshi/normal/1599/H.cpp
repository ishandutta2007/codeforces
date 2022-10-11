//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 999999999;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()

ll a, b, c;

ll get(ll x, ll y){
	cout << "? " << x + 1 << " " << y + 1 << "\n";
	cout.flush();
	ll ans;
	cin >> ans;
	return ans;
}

int main(){
    fast_io;
    
    a = get(0, 0);
    b = get(0, inf);
    c = get(inf, 0);
    ll l = 0, r = inf, mid;
    while(r - l > 1){
    	mid = (l + r) >> 1;
    	if(get(0, mid) == a - mid) l = mid;
    	else r = mid;
	}
	cout << "! " << a - l + 1 << " " << l + 1 << " " << inf - (c - l) + 1 << " " << inf - (b - (a - l)) + 1 << "\n";
	cout.flush();
 
    return 0;
}