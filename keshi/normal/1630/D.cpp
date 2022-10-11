//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 2e6 + 100;
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

ll pw(ll a, ll b){
	ll c = 1;
	while(b){
		if(b & 1) c = c * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return c;
}

ll t, n, m, a[maxn], b[maxn];

int main(){
	fast_io;

	cin >> t;
	while(t--){
		cin >> n >> m;
		ll s = 0;
		for(int i = 0; i < n; i++){
			cin >> a[i];
			s += abs(a[i]);
		}
		ll g = 0;
		for(int i = 0; i < m; i++){
			cin >> b[i];
			g = __gcd(g, b[i]);
		}
		ll mn0 = 0, mn1 = 0;
		for(int i = 0; i < g; i++){
			int c = 0;
			bool f = 0;
			ll mn = inf;
			for(int j = i; j < n; j += g){
				if(a[j] < 0) c++;
				if(a[j] == 0) f = 1;
				mn = min(mn, abs(a[j]));
			}
			if(f) continue;
			if(c & 1) mn1 += mn;
			else mn0 += mn;
		}
		cout << s - 2 * min(mn0, mn1) << "\n";
	}
	
	return 0;
}