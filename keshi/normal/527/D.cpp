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

ll n, x, w, r, ans;

pll a[maxn];

int main(){
	fast_io;
	
	cin >> n;
	
	for(ll i = 0; i < n; i++){
		cin >> x >> w;
		a[i].F = x + w;
		a[i].S = x - w;
	}
	
	sort(a, a + n);
	
	r = -inf;
	
	for(ll i = 0; i < n; i++){
		if(a[i].S >= r){
			ans++;
			r = a[i].F;
		}
	}
	
	cout << ans;
	
	return 0;
}