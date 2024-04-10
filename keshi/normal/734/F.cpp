//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;
const int lg = 60;

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

ll n, a[maxn], b[maxn], c[maxn], s, cnt[lg];

int main(){
	fast_io;
	
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> b[i];
		s += b[i];
	}
	for(int i = 0; i < n; i++){
		cin >> c[i];
		s += c[i];
	}
	if(s % (2 * n)){
		cout << -1;
		return 0;
	}
	s /= 2 * n;
	for(int i = 0; i < n; i++){
		ll x = b[i] + c[i] - s;
		if(x < 0 || x % n){
			cout << -1;
			return 0;
		}
		a[i] = x / n;
		for(int j = 0; j < lg; j++){
			cnt[j] += ((a[i] >> j) & 1);
		}
	}
	for(int i = 0; i < n; i++){
		ll x = 0, y = 0;
		for(int j = 0; j < lg; j++){
			if((a[i] >> j) & 1) x += n * (1ll << j), y += cnt[j] * (1ll << j);
			else x += cnt[j] * (1ll << j);
		}
		if(x != c[i] || y != b[i]){
			cout << -1;
			return 0;
		}
	}
	for(int i = 0; i < n; i++){
		cout << a[i] << " ";
	}
	
	
	return 0;
}