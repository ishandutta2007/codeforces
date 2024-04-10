//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef int ll;
typedef pair<ll, ll> pll;

const ll maxn = 50000;
const ll mod = 1e9 + 7;
const ll inf = 1e9;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()

ll n, m, cnt, cnt2, t, match[maxn], ans;
ll vis[maxn];
string s[maxn];
vector<ll> g[maxn];

inline bool ok(ll i, ll j){
	return (0 <= i && i < n && 0 <= j && j < m && s[i][j] == '#');
}

inline ll cal(ll i, ll j){
	return i * m + j;
}

inline void add(ll x, ll y){
	g[x].pb(y);
}

bool dfs(ll v){
	vis[v] = t;
	for(ll u : g[v]){
		if(match[u] == -1 || (vis[match[u]] != t && dfs(match[u]))){
			match[u] = v;
			return 1;
		}
	}
	return 0;
}

int main(){
	fast_io;
	
	cin >> n >> m;
	for(ll i = 0; i < n; i++){
		cin >> s[i];
		for(ll j = 0; j < m; j++){
			if(s[i][j] == '#') cnt++;
		}
	}
	for(ll i = 0; i < n; i++){
		for(ll j = 0; j < m; j++){
			if(!ok(i, j)) continue;
			if(ok(i - 1, j)) cnt2++;
			if(ok(i, j - 1)) cnt2++;
			if(ok(i, j - 1) && ok(i - 1, j)) add(cal(i, j), cal(i, j));
			if(ok(i, j - 1) && ok(i + 1, j)) add(cal(i, j), cal(i + 1, j));
			if(ok(i, j + 1) && ok(i - 1, j)) add(cal(i, j + 1), cal(i, j));
			if(ok(i, j + 1) && ok(i + 1, j)) add(cal(i, j + 1), cal(i + 1, j));
		}
	}
	for(ll i = 0; i < n * m; i++){
		sort(all(g[i]), greater<ll>());
	}
	fill(match, match + n * m, -1);
	for(ll i = 0; i < n * m; i++){
		t++;
		ans += dfs(i);
	}
	cout << cnt - (cnt2 - ans) << "\n";
	
	return 0;
}