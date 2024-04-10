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

ll t, a, b, n, ans;

int main(){
	fast_io;
	
	cin >> t;
	while(t--){
		cin >> a >> b >> n;
		if(a > b) swap(a, b);
		ans = 0;
		while(b <= n){
			a += b;
			ans++;
			if(a > b) swap(a, b);
		}
		cout << ans << '\n';
	}
	
	return 0;
}