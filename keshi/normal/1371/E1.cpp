//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 5e3;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll p, n, a[maxn], s;
vector<ll> ans;

int main(){
	fast_io;
	
	cin >> n >> p;
	for(ll i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a, a + n, greater<ll>());
	for(ll i = 1; i < maxn; i++){
		s = 1;
		for(ll j = 0; j < n; j++){
			if((n - max(0ll, a[j] - i) - j) <= 0) s = 0;
			s = (s * (n - max(0ll, a[j] - i) - j)) % p;
		}
		if(s != 0) ans.pb(i);
	}
	cout << ans.size() << '\n';
	for(ll i = 0; i < ans.size(); i++){
		cout << ans[i] << " ";
	}
	
	return 0;
}