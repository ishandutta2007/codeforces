//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 1e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()

template <int _N, int _sig>
struct SuffixAutomaton{
	static const int N = _N << 1;
	static const int sig = _sig;
	
	array<int, sig> nxt[N];
	bool cp[N];
	int link[N], len[N];
	int sz, last;
	
	SuffixAutomaton(){
		last = 0, sz = 1;
		len[last] = 0;
		memset(link, -1, sizeof link);
		memset(nxt, -1, sizeof nxt);
	}
	ll add(ll c){
		int cur = sz++;
		len[cur] = len[last] + 1;
		int p = last;
		last = cur;
		while(~p && nxt[p][c] == -1){
			nxt[p][c] = cur;
			p = link[p];
		}
		if(p == -1){
			link[cur] = 0;
			return cur;
		}
		int q = nxt[p][c];
		if(len[q] == len[p] + 1){
			link[cur] = q;
			return cur;
		}
		int clone = sz++;
		cp[clone] = 1;
		len[clone] = len[p] + 1;
		link[clone] = link[q];
		nxt[clone] = nxt[q];
		link[cur] = link[q] = clone;
		while(~p && nxt[p][c] == q){
			nxt[p][c] = clone;
			p = link[p];
		}
		return cur;
	}
	void init(){
		last = 0, sz = 1;
		len[last] = 0;
		memset(link, -1, sizeof link);
		memset(nxt, -1, sizeof nxt);
	}
};

ll q, dp[maxn << 1], ans;
SuffixAutomaton<maxn, 26> sa;
vector<ll> g[maxn << 1];

void dfs(ll v){
	for(ll u : g[v]){
		dfs(u);
		dp[v] += dp[u];
	}
	if(v) ans += dp[v] * dp[v] * (sa.len[v] - sa.len[sa.link[v]]);
	return;
}

int main(){
	fast_io;
	
	cin >> q;
	while(q--){
		string s;
		cin >> s;
		ll n = Sz(s);
		ans = 0;
		for(ll i = 0; i < n + n + 10; i++){
			dp[i] = 0;
			g[i].clear();
		}
		sa.init();
		for(char c : s){
			dp[sa.add(c - 'a')] = 1;
		}
		for(ll i = 0; i < sa.sz; i++){
			g[sa.link[i]].pb(i);
		}
		dfs(0);
		cout << ans << "\n";
	}
	
	return 0;
}