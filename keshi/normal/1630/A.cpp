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

int t, n, k, p[maxn];

int main(){
	fast_io;

	cin >> t;
	while(t--){
		cin >> n >> k;
		if(n - 1 == k){
			if(n <= 4){
				cout << "-1\n";
				continue;
			}
			cout << "0 2\n";
			cout << "1 " << (n - 3) << "\n";
			cout << n - 1 << " " << n - 2 << "\n";
			for(int i = 3; i < n - 3; i++){
				int x = ((n - 1) ^ i);
				if(i < x) cout << i << " " << x << "\n";
			}
			continue;
		}
		for(int i = 0; i < n; i++){
			int x = ((n - 1) ^ i);
			if(k != 0){
			if(i == 0) x = ((n - 1) ^ k);
			if(i == n - 1) x = k;
			if(i == k) x = n - 1;
			if(i == ((n - 1) ^ k)) x = 0;
			}
			if(i < x) cout << i << " " << x << "\n";
		}
	}
	
	return 0;
}