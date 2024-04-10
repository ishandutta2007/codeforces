//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef int ll;

const ll maxn = 8e3 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e9;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll t, n, a[maxn], c[maxn], ans, s;
bool vis[maxn];

int main(){
	fast_io;
	
	cin >> t;
	
	while(t--){
		cin >> n;
		fill(vis, vis + n + 1, 0);
		fill(c, c + n + 1, 0);
		ans = 0;
		for(ll i = 0; i < n; i++){
			cin >> a[i];
			c[a[i]]++;
		}
		for(ll i = 0; i < n; i++){
			s = 0;
			ll j = i;
			while(j >= 0 && s + a[j] <= n){
				s += a[j--];
				if(i - j > 1 && !vis[s]) ans += c[s], vis[s] = 1;
			}
		}
		cout << ans << '\n';
	}
	
	return 0;
}