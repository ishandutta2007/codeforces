//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, k, m, l[maxn], r[maxn], x;

vector<ll> ans, s[maxn], e[maxn], v;

set<pll> p;

int main(){
	fast_io;
	
	cin >> n >> k;
	
	for(ll i = 0; i < n; i++){
		cin >> l[i] >> r[i];
		s[l[i]].pb(i);
		e[r[i]].pb(i);
	}
	
	for(ll i = 1; i < maxn; i++){
		for(ll j = 0; j < e[i - 1].size(); j++){
			p.erase({-r[e[i - 1][j]], e[i - 1][j]});
		}
		for(ll j = 0; j < s[i].size(); j++){
			p.insert({-r[s[i][j]], s[i][j]});
		}
		x = p.size() - k;
		v.clear();
		for(set<pll>::iterator j = p.begin(); j != p.end(); j++){
			if(x <= 0) break;
			v.pb(j -> S);
			x--;
		}
		for(ll j = 0; j < v.size(); j++){
			ans.pb(v[j]);
			p.erase({-r[v[j]], v[j]});
		}
	}
	
	cout << ans.size() << endl;
	
	for(ll i = 0; i < ans.size(); i++){
		cout << ans[i] + 1 << " ";
	}
	
	return 0;
}