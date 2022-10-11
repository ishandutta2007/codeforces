//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 2e6 + 100;
const ll mod = 998244353;
const ll inf = 1e18;
const ll lg = 20;

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

ll n, k, rev[maxn], a[maxn];

void NTT(ll *A, bool inv = 0){
	ll n = (1 << lg);
	for(ll i = 0; i < (1 << lg); i++){
		if(rev[i] < i) swap(A[i], A[rev[i]]);
	}
	for(ll ln = 1; ln < n; ln <<= 1){
		ll w = pw(3, mod / 2 / ln);
		if(inv) w = pw(w, mod - 2);
		for(ll i = 0; i < n; i += ln + ln){
			ll wn = 1;
			for(ll j = i; j < i + ln; j++){
				ll x = A[j], y = A[j + ln] * wn % mod;
				A[j] = (x + y) % mod;
				A[j + ln] = (x - y + mod) % mod;
				wn = wn * w % mod;
			}
		}
	}
	if(inv){
		ll invn = pw(1 << lg, mod - 2);
		for(ll i = 0; i < n; i++){
			A[i] = A[i] * invn % mod;
		}
	}
}

int main(){
	fast_io;
	
	for(ll i = 1; i < (1 << lg); i++){
		rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (lg - 1));
	}
	cin >> n >> k;
	for(ll i = 0; i < k; i++){
		ll x;
		cin >> x;
		a[x] = 1;
	}
	NTT(a);
	for(ll i = 0; i < (1 << lg); i++){
		a[i] = pw(a[i], n / 2);
	}
	NTT(a, 1);
	ll ans = 0;
	for(ll i = 0; i < (1 << lg); i++){
		ans = (ans + a[i] * a[i]) % mod;
	}
	cout << ans;
	
	return 0;
}