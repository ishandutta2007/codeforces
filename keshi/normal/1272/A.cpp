//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, a, b, c, ans;

int main(){
	fast_io;
	
	cin >> n;
	
	while(n--){
		cin >> a >> b >> c;
		ans = inf;
		for(ll i = a - 1; i <= a + 1; i++){
			for(ll j = b - 1; j <= b + 1; j++){
				for(ll k = c - 1; k <= c + 1; k++){
					ans = min(ans, abs(i - j) + abs(i - k) + abs(j - k));
				}
			}
		}
		cout << ans << '\n';
	}
	
	return 0;
}