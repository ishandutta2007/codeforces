//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 3e5 + 100;
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

struct idk{
	ll a, b, c;
	idk(ll _a = 0, ll _b = 0, ll _c = 0){
		a = _a, b = _b, c = _c;
		return;
	}
	void operator += (idk x){
		a += x.a;
		b += x.b;
		c += x.c;
		a %= mod;
		b %= mod;
		c %= mod;
		return;
	}
};

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
	
};

ll ans, ps[maxn << 1];
string s[3];
SuffixAutomaton<maxn, 30> sa;
idk dp[maxn << 1];
vector<int> g[maxn << 1];

void dfs(ll v){
	for(ll u : g[v]){
		dfs(u);
		dp[v] += dp[u];
	}
	if(v == 0) return;
	ll x = dp[v].a * dp[v].b % mod * dp[v].c % mod;
	ps[sa.len[v] + 1] -= x;
	ps[sa.len[v] + 1] %= mod;
	ps[sa.len[sa.link[v]] + 1] += x;
	ps[sa.len[sa.link[v]] + 1] %= mod;
	return;
}

int main(){
	fast_io;
	
	cin >> s[0] >> s[1] >> s[2];
	for(char c : s[0]){
		dp[sa.add(c - 'a')] = idk(1, 0, 0);
	}
	sa.add(26);
	for(char c : s[1]){
		dp[sa.add(c - 'a')] = idk(0, 1, 0);
	}
	sa.add(27);
	for(char c : s[2]){
		dp[sa.add(c - 'a')] = idk(0, 0, 1);
	}
	for(ll i = 0; i < sa.sz; i++){
		g[sa.link[i]].pb(i);
	}
	dfs(0);
	for(ll i = 1; i <= min({Sz(s[0]), Sz(s[1]), Sz(s[2])}); i++){
		ps[i] += ps[i - 1];
		ps[i] %= mod;
		cout << (ps[i] + mod) % mod << " ";
	}
	
	return 0;
}