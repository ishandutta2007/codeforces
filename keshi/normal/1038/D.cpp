//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 510;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, a, mi, ma, s;

int main(){
	fast_io;
	
	cin >> n;
	
	mi = inf;
	ma = -inf;
	
	for(ll i = 0; i < n; i++){
		cin >> a;
		mi = min(mi, a);
		ma = max(ma, a);
		s += abs(a);
	}
	
	if(n == 1){
		cout << a;
		return 0;
	}
	if(mi > 0){
		cout << s - 2 * mi;
		return 0;
	}
	if(ma < 0){
		cout << s + 2 * ma;
		return 0;
	}
	cout << s;
	
	return 0;
}