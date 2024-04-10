#include <bits/stdc++.h>
using namespace std;

#define ll long double
#define sd(x) scanf("%d", &(x))
#define pii pair<int, int>
#define F first
#define S second

#define TRACE

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


const ll is_query = -(1LL << 62);
 
struct Line {
    ll m, b;
    mutable function<const Line *()> succ;
 
    bool operator<(const Line &rhs) const {
        if (rhs.b != is_query) return m < rhs.m;
        const Line *s = succ();
        if (!s) return 0;
        ll x = rhs.m;
        return b - s->b < (s->m - m) * x;
    }
};
 
struct HullDynamic : public multiset<Line> {
    bool bad(iterator y) {
        auto z = next(y);
        if (y == begin()) {
            if (z == end()) return 0;
            return y->m == z->m && y->b <= z->b;
        }
        auto x = prev(y);
        if (z == end()) return y->m == x->m && y->b <= x->b;
        return (x->b - y->b) * (z->m - y->m) >= (y->b - z->b) * (y->m - x->m);
    }
 
    void insert_line(ll m, ll b) {
        auto y = insert({m, b});
        y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };
        if (bad(y)) {
            erase(y);
            return;
        }
        while (next(y) != end() && bad(next(y))) erase(next(y));
        while (y != begin() && bad(prev(y))) erase(prev(y));
    }
 
    ll eval(ll x) {
        auto l = *lower_bound((Line) {x, is_query});
        return l.m * x + l.b;
    }
};

const int N = 100005;
HullDynamic HD[N];
int ind[N];
ll dp[N];
int a[N], b[N];

vector<int> con[N];
vector<pair<ll, ll>> vec[N];
int cnt = 0;
int tree[N];
int dfs(int s = 1, int p = 0){
	// trace(s, p);
	int bigc = 0;
	tree[s] = 1;
	for(int v : con[s]){
		if(v != p){
			tree[s] += dfs(v, s);
			if(tree[v] > tree[bigc]) bigc = v;
		}
	}
	// trace(s, bigc);
	if(!bigc){
		ind[s] = ++cnt;
		dp[s] = 0;
		HD[ind[s]].insert_line(-b[s], -dp[s]);
		vec[ind[s]].push_back({-b[s], -dp[s]});
		return tree[s];
	}
	ind[s] = ind[bigc];
	for(int v : con[s]){
		if(v != p && v != bigc){
			for(auto it : vec[ind[v]]){
				vec[ind[s]].push_back(it);
				HD[ind[s]].insert_line(it.F, it.S);
			}
		}
	}
	dp[s] = -HD[ind[s]].eval(a[s]);
	vec[ind[s]].push_back({-b[s], -dp[s]});
	HD[ind[s]].insert_line(-b[s], -dp[s]);
	return tree[s];
}
ll EPS = 1e-2;

long long conv(ll x){
	if(x < 0) return -conv(-x);
	return (long long) (x + 0.5);
}
int main(){
    int n;
    sd(n);
    for(int i = 1; i <= n; i++) sd(a[i]);
    for(int i = 1; i <= n; i++) sd(b[i]);
    for(int i = 1; i < n; i++){
    	int u, v;
    	sd(u); sd(v);
    	con[u].push_back(v);
    	con[v].push_back(u);
    }
    dfs();
    for(int i = 1; i <= n; i++) printf("%lld ", conv(dp[i]));
}