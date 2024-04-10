//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()


ll q, n;

int main(){
	fast_io;
	
	cin >> q;
	while(q--){
		cin >> n;
		ll ml = inf, cl = inf, mr = -inf, cr = inf, cc = inf;
		for(ll i = 0; i < n; i++){
			ll l, r, c;
			cin >> l >> r >> c;
			if(l < ml){
				ml = l;
				cl = inf;
				cc = inf;
			}
			if(l == ml){
				cl = min(cl, c);
			}
			if(r > mr){
				mr = r;
				cr = inf;
				cc = inf;
			}
			if(r == mr) cr = min(cr, c);
			if(l == ml && r == mr){
				cc = min(cc, c);
			}
			cout << min(cl + cr, cc) << "\n";
		}
	}
	
	return 0;
}