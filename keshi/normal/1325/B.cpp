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
#define pll pair<ll, ll>
#define F first
#define S second

ll t, n, x, c;

vector<ll> a;

int main(){
	fast_io;
	
	cin >> t;
	
	while(t--){
		c = 0;
		cin >> n;
		a.clear();
		for(ll i = 0; i < n; i++){
			cin >> x;
			a.pb(x);
		}
		sort(a.begin(), a.end());
		for(ll i = 0; i < n; i++){
			if(i == 0 || a[i] != a[i - 1]) c++;
		}
		cout << c << '\n';
	}
	
	return 0;
}