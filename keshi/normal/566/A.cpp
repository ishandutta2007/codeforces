//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef int ll;

const ll maxn = 1e6 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e9;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll n, e[2][maxn], h[maxn], g[26][maxn], t, x;
long long ans;
vector<ll> a[2][maxn];
string s;

void upd(ll id){
	a[ans][id].pb(x);
	if(h[id] == s.size()) return;
	if(g[s[h[id]] - 'a'][id] == 0){
		g[s[h[id]] - 'a'][id] = t;
		h[t++] = h[id] + 1;
	}
	upd(g[s[h[id]] - 'a'][id]);
	return;
}

void solve(ll id){
	for(ll i = 0; i < 26; i++){
		if(g[i][id]) solve(g[i][id]);
	}
	ll p1 = 0, p2 = 0;
	while(p1 != a[0][id].size() && p2 != a[1][id].size()){
		if(e[0][a[0][id][p1]]) p1++;
		else if(e[1][a[1][id][p2]]) p2++;
		else{
			ans += h[id];
			e[0][a[0][id][p1]] = a[1][id][p2];
			e[1][a[1][id][p2]] = a[0][id][p1];
			p1++, p2++;
		}
	}
	return;
}

int main(){
	fast_io;
	t++;
	cin >> n;
	for(ll i = 0; i < n; i++){
		cin >> s;
		x = i + 1;
		upd(0);
	}
	ans = 1;
	for(ll i = 0; i < n; i++){
		cin >> s;
		x = i + 1;
		upd(0);
	}
	ans = 0;
	solve(0);
	cout << ans << '\n';
	for(ll i = 1; i <= n; i++){
		cout << i << " " << e[0][i] << '\n';
	}
	
	return 0;
}