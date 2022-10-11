//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 62;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll t, n, m, x, s, ans, c[maxn];

map<ll, ll> o;

int main(){
	fast_io;
	
	for(ll i = 0; i < maxn; i++){
		o[(1ll << i)] = i;
	}
	
	cin >> t;
	
	while(t--){
		fill(c, c + maxn, 0);
		cin >> n >> m;
		s = 0;
		ans = 0;
		for(ll i = 0; i < m; i++){
			cin >> x;
			c[o[x]]++;
			s += x;
		}
		if(s < n){
			cout << "-1\n";
			continue;
		}
		for(ll i = 0; i + 1 < maxn; i++){
			if(n % 2){
				for(ll j = i; j < maxn; j++){
					if(c[j]){
						c[j]--;
						break;
					}
					c[j]++;
					ans++;
				}
				n--;
			}
			c[i + 1] += c[i] / 2;
			n /= 2;
		}
		cout << ans << '\n';
	}
	
	return 0;
}