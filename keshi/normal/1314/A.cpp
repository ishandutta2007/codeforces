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
#define pll pair<ll, ll>
#define F first
#define S second

ll n, t, p, x, ans;

pair<ll, pll> a[maxn];

set<pll> s;

int main(){
	fast_io;
	
	cin >> n;
	
	for(ll i = 0; i < n; i++){
		cin >> a[i].F;
	}
	
	for(ll i = 0; i < n; i++){
		cin >> a[i].S.F;
		a[i].S.S = i;
	}
	
	sort(a, a + n);
	
	x = 1;
	
	while(p < n || !s.empty()){
		if(s.empty()) x = lower_bound(a, a + n, make_pair(x, make_pair(-1ll, -1ll))) -> F;
		while(p < n && a[p].F <= x){
			s.insert({-a[p].S.F, a[p].S.S});
			t += a[p].S.F;
			p++;
		}
		t += s.begin() -> F;
		ans += t;
		s.erase(s.begin());
		x++;
	}
	
	cout << ans;
	
	return 0;
}