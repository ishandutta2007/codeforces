//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1e6 + 100;
const ll mod = 998244353;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll n, x, a[maxn], ans[maxn];

ll pwlg(ll pa, ll pb){
	if(pb == 0) return 1;
	ll pc = pwlg(pa, pb / 2);
	pc = (pc * pc) % mod;
	if(pb & 1) pc = (pc * pa) % mod;
	return pc;
}

int main(){
	fast_io;
	
	cin >> n;
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for(ll i = 1; i <= n; i++){
		a[i] += a[i - 1];
	}
	for(ll i = 1; i <= n; i++){
		x = n - i;
		while(x > 0){
			ans[i] += a[x];
			x -= i;
		}
	}
	x = pwlg(n, mod - 2);
	for(ll i = 1; i <= n; i++){
		cout << ((ans[i] % mod) * x) % mod << " ";
	}
	
	return 0;
}