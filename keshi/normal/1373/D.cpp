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

ll t, n, a[maxn], ps[maxn], mx[2], y, s;

int main(){
	fast_io;
	
	cin >> t;
	while(t--){
		cin >> n;
		mx[0] = 0;
		mx[1] = -inf;
		y = s = 0;
		for(ll i = 1; i <= n; i++){
			cin >> a[i];
			if(i & 1) ps[i] = ps[i - 1] - a[i], s += a[i];
			else ps[i] = ps[i - 1] + a[i];
			y = max(y, ps[i] + mx[i & 1]);
			mx[i & 1] = max(mx[i & 1], -ps[i]);
		}
		cout << y + s << '\n';
	}
	
	return 0;
}