//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 5e3 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll t, n, a[maxn], l[maxn], r[maxn];

int main(){
	fast_io;
	
	cin >> t;
	
	while(t--){
		cin >> n;
		fill(l, l + n + 1, inf);
		fill(r, r + n + 1, -1);
		for(ll i = 0; i < n; i++){
			cin >> a[i];
			l[a[i]] = min(l[a[i]], i);
			r[a[i]] = max(r[a[i]], i);
		}
		bool f = 0;
		for(ll i = 0; i <= n; i++){
			if(r[i] - l[i] > 1) f = 1;
		}
		if(f) cout << "YES\n";
		else cout << "NO\n";
	}
	
	return 0;
}