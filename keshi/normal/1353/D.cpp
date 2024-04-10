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

ll t, n, a[maxn], l, r, x;

set<pll> s;

int main(){
	fast_io;
	
	cin >> t;
	while(t--){
		cin >> n;
		s.clear();
		s.insert(Mp(1 - n, 1));
		for(ll i = 1; i <= n; i++){
			l = s.begin() -> S;
			r = l - s.begin() -> F;
			x = (l + r) / 2;
			a[x] = i;
			s.erase(s.begin());
			s.insert(Mp(l - (x - 1), l));
			s.insert(Mp(x + 1 - r, x + 1));
		}
		for(ll i = 1; i <= n; i++){
			cout << a[i] << " ";
		}
		cout << '\n';
	}
	
	return 0;
}