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

ll t, n, a, b;

int main(){
	fast_io;
	
	cin >> t;
	while(t--){
		cin >> n >> a >> b;
		if(abs(a - b) > 1){
			cout << "-1\n";
			continue;
		}
		if(a + b > n - 2){
			cout << "-1\n";
			continue;
		}
		if(a < b){
			if(b * 2 > n){
				cout << "-1\n";
				continue;
			}
			ll t = 1;
			for(ll i = 0; i < b; i++){
				cout << t + 1 << " " << t << " ";
				t += 2;
			}
			while(t <= n){
				cout << t++ << " ";
			}
			cout << "\n";
			continue;
		}
		else if(a > b){
			if(a * 2 > n){
				cout << "-1\n";
				continue;
			}
			ll t = 1;
			for(ll i = 0; i < a; i++){
				cout << n - (t + 1) + 1 << " " << n - t + 1 << " ";
				t += 2;
			}
			while(t <= n){
				cout << n - (t++) + 1 << " ";
			}
			cout << "\n";
			continue;
		}
		else{
			cout << n << " ";
			ll t = 2;
			for(ll i = 0; i < a; i++){
				cout << n - (t + 1) + 1 << " " << n - t + 1 << " ";
				t += 2;
			}
			while(t <= n){
				cout << n - (t++) + 1 << " ";
			}
			cout << "\n";
			continue;
		}
	}
	
	return 0;
}