//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll t, n, a[maxn], b[maxn];
map<pll, ll> c;

int main(){
	fast_io;
	
	cin >> t;
	while(t--){
		cin >> n;
		c.clear();
		for(ll i = 0; i < n; i++){
			cin >> a[i];
		}
		for(ll i = 0; i < n; i++){
			cin >> b[i];
		}
		if(n % 2){
			if(a[n / 2] != b[n / 2]){
				cout << "No\n";
				continue;
			}
		}
		for(ll i = 0; i < n / 2; i++){
			if(a[i] > a[n - i - 1]) swap(a[i], a[n - i - 1]);
			c[Mp(a[i], a[n - i - 1])]++;
		}
		for(ll i = 0; i < n / 2; i++){
			if(b[i] > b[n - i - 1]) swap(b[i], b[n - i - 1]);
			c[Mp(b[i], b[n - i - 1])]--;
		}
		bool f = 1;
		for(map<pll, ll>::iterator it = c.begin(); it != c.end(); it++){
			if(it -> S) f = 0;
		}
		cout << (f ? "Yes\n" : "No\n");
	}
	
	return 0;
}