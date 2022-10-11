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

ll q, n, m, x, y, ans, l;
char c;

int main(){
	fast_io;
	
	cin >> q;
	while(q--){
		cin >> n >> m >> x >> y;
		ans = 0;
		for(ll i = 0; i < n; i++){
			l = 0;
			for(ll j = 1; j <= m; j++){
				cin >> c;
				if(c == '*'){
					ans += min((j - l - 1) * x, ((j - l - 1) / 2) * y + ((j - l - 1) & 1) * x);
					l = j;
				}
			}
			ans += min((m - l) * x, ((m - l) / 2) * y + ((m - l) & 1) * x);
		}
		cout << ans << '\n';
	}
	
	return 0;
}