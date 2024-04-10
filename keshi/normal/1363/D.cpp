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

ll t, k, n, m, x, b[maxn], l, r, mx;
vector<ll> a[maxn], vec;
bool vis[maxn];
string s;

int main(){
	fast_io;
	
	cin >> t;
	while(t--){
		cin >> n >> k;
		fill(vis, vis + n + 1, 0);
		for(ll i = 0; i < k; i++){
			a[i].clear();
			cin >> m;
			for(ll j = 0; j < m; j++){
				cin >> x;
				vis[x] = 1;
				a[i].pb(x);
			}
		}
		a[k].clear();
		for(ll i = 1; i <= n; i++){
			if(!vis[i]) a[k].pb(i);
		}
		cout << "? " << n;
		for(ll i = 1; i <= n; i++){
			cout << " " << i;
		}
		cout << '\n';
		cout.flush();
		cin >> mx;
		l = 0;
		for(ll i = 9; i >= 0; i--){
			vec.clear();
			b[i] = 0;
			for(ll j = 0; j < (1ll << i); j++){
				if(l + j > k) break;
				for(ll o = 0; o < a[l + j].size(); o++){
					vec.pb(a[l + j][o]);
				}
			}
			if(vec.empty()) continue;
			cout << "? " << vec.size();
			for(ll j = 0; j < vec.size(); j++){
				cout << " " << vec[j];
			}
			cout << '\n';
			cout.flush();
			cin >> x;
			if(x != mx) l += (1ll << i);
		}
		cout << "? " << n - a[l].size();
		for(ll i = 0; i <= k; i++){
			if(l != i){
				for(ll j = 0; j < a[i].size(); j++){
					cout << " " << a[i][j];
				}
			}
		}
		cout << '\n';
		cout.flush();
		cin >> x;
		cout << "!";
		for(ll i = 0; i < k; i++){
			if(i == l) cout << " " << x;
			else cout << " " << mx;
		}
		cout << '\n';
		cout.flush();
		cin >> s;
		if(s != "Correct") return 0;
	}
	
	return 0;
}