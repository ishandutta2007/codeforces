//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll maxn = 2e5 + 100;
const ll maxm = 3e4;
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

ll t, n, a[maxn], b[maxn];
bitset<maxm> bt;

int main(){
	fast_io;
	
	cin >> t;
	while(t--){
		cin >> n;
		ll ans = 0, s = 0;
		for(ll i = 0; i < n; i++){
			cin >> a[i];
			s += a[i];
			ans += (n - 2) * a[i] * a[i];
		}
		for(ll i = 0; i < n; i++){
			cin >> b[i];
			s += b[i];
			ans += (n - 2) * b[i] * b[i];
		}
		bt.reset();
		bt[0] = 1;
		for(ll i = 0; i < n; i++){
			bt = (bt << a[i]) | (bt << b[i]);
		}
		ll mn = inf;
		for(ll i = 0; i < maxm; i++){
			if(bt[i]){
				mn = min(mn, i * i + (s - i) * (s - i));
			}
		}
		cout << ans + mn << "\n";
	}
	
	return 0;
}