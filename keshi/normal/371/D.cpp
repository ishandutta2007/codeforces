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

ll n, dsu[maxn], m, a[maxn], b[maxn], t, k, s;

ll root(ll i, ll x){
	if(b[i] + x > a[i]){
		dsu[i] = max(dsu[i], i + 1);
		dsu[i] = root(dsu[i], x - a[i] + b[i]);
	}
	b[i] = min(a[i], b[i] + x);
	return dsu[i];
}

int main(){
	fast_io;
	
	cin >> n;
	
	for(ll i = 0; i < n; i++){
		cin >> a[i];
		dsu[i] = i;
	}
	a[n] = inf;
	dsu[n] = n;
	
	cin >> m;
	
	for(ll i = 0; i < m; i++){
		cin >> t >> k;
		if(t == 1){
			cin >> s;
			root(k - 1, s);
		}
		else{
			cout << b[k - 1] << '\n';
		}
	}
	
	return 0;
}