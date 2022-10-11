//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll maxn = 1e6 + 100;
const ll mod = 1e9 + 7;
const int inf = 1e9 + 100;

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

ll n, h[maxn], ans, cur;

int main(){
	fast_io;
	
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> h[i];
		h[i]--;
	}
	h[0] = h[n + 1] = inf;
	cur = 0;
	for(int i = 1; i <= n; i++){
		ans = (ans + h[i] + cur * min(h[i], h[i - 1])) % mod;
		cur = (cur * min({h[i - 1], h[i], h[i + 1]}) + min(h[i], h[i + 1])) % mod;
	}
	cout << ans;
	
	return 0;
}