//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1e6 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll t, n, ans, a[maxn], ps[maxn];
string s;

int main(){
	fast_io;
	
	cin >> t;
	while(t--){
		cin >> s;
		n = s.size();
		s = ' ' + s;
		ans = 0;
		for(ll i = 1; i <= n; i++){
			a[i] = a[i - 1] + (s[i] == '+' ? 1 : -1);
			ps[i] = max(ps[i - 1], -a[i]);
		}
		for(ll i = 1; i <= n; i++){
			ans += ps[n] - ps[i - 1] + 1;
		}
		cout << ans << '\n';
	}
	
	return 0;
}