//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll maxn = 4e5 + 100;
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

ll n, a[maxn], ps[maxn];

int main(){
	fast_io;
	
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		ps[a[i]]++;
	}
	for(int i = 1; i < maxn; i++){
		ps[i] += ps[i - 1];
	}
	ll ans = 0;
	for(int i = 1; i < maxn; i++){
		if(ps[i] == ps[i - 1]) continue;
		ll x = 0;
		for(int j = i; j + i - 1 < maxn; j += i){
			x += (ps[j + i - 1] - ps[j - 1]) * j;
		}
		ans = max(ans, x);
	}
	cout << ans;
	
	return 0;
}