#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))
#define pii pair<int, int>
#define F first
#define S second
#define all(c) ((c).begin()), ((c).end())


#ifdef LOCAL
#define cerr cout
#else
#endif

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

const int M = 9.5e6 + 10;
const ll INF = 1e18;
struct line{
	int m;
	ll b;
	ll get(int x){
		return m * (ll) x + b;
	}
	line(int m, ll b) : m(m), b(b){}
	line(){
		m = 0, b = INF;
	}
} L[M];

int lft[M], rgt[M], cnt;
const int MAXX = 5e5 + 10;
const int N = 500005;
ll dp[N];
int sz[N];
int tail[N], nxt[2 * N], which[2 * N], st[N], pos;

// gives min
struct lst{
	int root, h;
	lst(){
		root = ++cnt;
		h = 0;
	}
	void insert_line(line l){
		int s = 0, e = MAXX, ind = root;
		while(ind){
			if(l.b==INF) break;
			int m = (s + e) >> 1;
			bool better_m = l.get(m) < L[ind].get(m);
			bool better_s = l.get(s) < L[ind].get(s);
			if(better_m) swap(L[ind], l);
			if(better_s ^ better_m){
				if(s != e && !lft[ind]) lft[ind] = ++cnt; 
				e = m, ind = lft[ind];
			}
			else{
				if(s != e && !rgt[ind]) rgt[ind] = ++cnt;
				s = m + 1, ind = rgt[ind];
			}
		};
	}

	ll eval(int x){		
		int s = 0, e = MAXX, ind = root;
		ll ans = INF;
		while(ind){
			int m = (s + e) >> 1;
			ans = min(ans, L[ind].get(x));
			if(x <= m) e = m, ind = lft[ind];
			else s = m + 1, ind = rgt[ind];
		}
		return ans;
	}
};
ll n;
int timer;
void dfs0(int s = 1, int p = 0){
	st[++timer] = s;
	for(int ind = tail[s]; ind; ind = nxt[ind]) if(which[ind] != p){
		dfs0(which[ind], s);
	}
}
ll ans = 1e18;
int main(){
	n = 500000;
	scanf("%lld", &n);
	for(int i = 1; i <= n; i++) nxt[i] = i, which[i] = i;
	for(int i = 1; i < n; i++){
		int u = i, v = i + 1;
		sd(u);
		sd(v);
		int lst_u = tail[u];
		tail[u] = ++pos;
		which[pos] = v;
		nxt[pos] = lst_u;

		int lst_v = tail[v];
		tail[v] = ++pos;
		which[pos] = u;
		nxt[pos] = lst_v;
	}

	dfs0();

	for(int i = n; i >= 1; i--){
		int s = st[i];
		sz[s] = 1;
		for(int ind = tail[s]; ind; ind = nxt[ind]) if(sz[which[ind]] != 0){
			sz[s] += sz[which[ind]];
		}
		
		dp[s] = sz[s] * (ll) sz[s];
		lst hd;

		for(int ind = tail[s]; ind; ind = nxt[ind]) if(sz[which[ind]] != 0){
			int v = which[ind];
			dp[s] = min(dp[s], dp[v] + (sz[s] - sz[v]) * (ll) (sz[s] - sz[v]));
			ans = min(ans, dp[v] + (n - sz[v]) * (n - sz[v]));
			ans = min(ans, hd.eval(sz[v]) + dp[v] - 2ll * n * sz[v] + sz[v] * (ll) sz[v] + n * n);
			hd.insert_line(line(2 * sz[v], dp[v] - 2ll * n * sz[v] + sz[v] * (ll) sz[v]));
		}
	}
	printf("%lld\n", ((n * (n - 1)) + n * n - ans) / 2);
}