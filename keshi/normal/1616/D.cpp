//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 2e5 + 100;
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

ll q, n, x, a[maxn], ps[maxn], b[maxn], dp[maxn], d[maxn];

int main(){
	fast_io;
	
	cin >> q;
	while(q--){
		cin >> n;
		for(ll i = 1; i <= n; i++){
			cin >> a[i];
			ps[i] = ps[i - 1] + a[i];
		}
		cin >> x;
		vector<ll> vec, v2;
		for(ll i = 1; i <= n; i++){
			b[i] = ps[i] - x * i;
			v2.clear();
			while(!vec.empty() && b[vec.back()] <= b[i]){
				v2.pb(vec.back());
				vec.pop_back();
			}
			if(vec.empty()) d[i] = -1;
			else d[i] = vec.back();
			while(!v2.empty()){
				vec.pb(v2.back());
				v2.pop_back();
			}
			while(!vec.empty() && b[vec.back()] <= b[i - 1]) vec.pop_back();
			vec.pb(i - 1);
		}
		ll mx = -1;
		for(ll i = 1; i <= n; i++){
			mx = max(mx, d[i]);
			if(mx == -1) dp[i] = 0;
			else dp[i] = dp[mx] + 1;
			dp[i] = min(dp[i], dp[i - 1] + 1);
		}
		cout << n - dp[n] << "\n";
	}
	
	return 0;
}