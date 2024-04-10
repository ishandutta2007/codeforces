//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 3e3 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, t, a[maxn], b[maxn];

bool vis[maxn];

vector<ll> vec[maxn], ans;

pll p;

int main(){
	fast_io;
	
	cin >> n;
	
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	cin >> m;
	
	while(true){
		for(ll i = 0; i <= n; i++){
			vec[i].clear();
			vis[i] = 0;
		}
		t = 0;
		for(ll i = 1; i <= n; i++){
			if(vis[i]) continue;
			ll j = a[i];
			vis[i] = 1;
			b[i] = t;
			vec[t].pb(i);
			while(j != i){
				vec[t].pb(j);
				vis[j] = 1;
				b[j] = t;
				j = a[j];
			}
			sort(vec[t].begin(), vec[t].end());
			t++;
		}
		if(n - t < m){
			for(ll i = 1; i <= n; i++){
				if(b[i] != b[1]){
					ans.pb(1);
					ans.pb(i);
					swap(a[1], a[i]);
					break;
				}
			}
		}
		else if(n - t > m){
			p = {inf, inf};
			for(ll i = 0; i < t; i++){
				if(vec[i].size() > 1){
					p = min(p, {vec[i][0], vec[i][1]});
				}
			}
			ans.pb(p.F);
			ans.pb(p.S);
			swap(a[p.F], a[p.S]);
		}
		else break;
	}
	
	cout << ans.size() / 2 << '\n';
	
	for(ll i = 0; i < ans.size(); i++){
		cout << ans[i] << " ";
	}
	
	return 0;
}