#include "bits/stdc++.h"
using namespace std;
#define all(x) begin(x),end(x)
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { string sep; for (const T &x : v) os << sep << x, sep = " "; return os; }
#define debug(a) cerr << "(" << #a << ": " << a << ")\n";
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
const int mxN = 1.5e5+1, oo = 1e9;
struct Line {
	mutable ll k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ll x) const { return p < x; }
};
struct LineContainer : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	static const ll inf = LLONG_MAX;
	ll div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) return x->p = inf, 0;
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(ll k, ll m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	ll query(ll x) {
        if(empty()) return -1e18;
		assert(!empty());
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
};
vi adj[mxN];

bitset<mxN> vis;
int sz[mxN],a[mxN];

void dfsz(int at) {
    sz[at]=1;
    vis[at]=true;
    for(auto to: adj[at])if(!vis[to]) {
        dfsz(to);
        sz[at]+=sz[to];
    }
    vis[at]=false;
}
int centroid(int at) {
    int from=at, n=sz[at];
    bool done=false;
    while(!done) {
        done=true;
        for(auto to: adj[at]) if(!vis[to] and to!=from) {
            if(sz[to]*2>n) {
                from = at, at = to, done=false;
                break;
            }
        }
    }
    return at;
}
ll psum=0,ppsum=0,ans=0;
ll d=0;
LineContainer lc;
void dfs(int at) {
    d++;
    ppsum+=d*a[at];
    psum+=a[at];
    
    vis[at]=true;
    bool good=true;
    for(auto to: adj[at]) if(!vis[to]) {
        dfs(to);
        good=false;
    }
    if(good) ans=max(ans,lc.query(psum)+ppsum);
    ppsum-=d*a[at];
    psum-=a[at];
    d--;
    vis[at]=false;
}
void dfs2(int at) {
    d++;
    psum+=a[at];
    ppsum+=psum;
    lc.add(d,ppsum);
    ans = max(ans,ppsum);
    vis[at]=true;
    for(auto to: adj[at]) if(!vis[to]) {
        dfs2(to);
    }
    ppsum-=psum;
    psum-=a[at];
    d--;
    vis[at]=false;
}
void decomp(int at) {
    dfsz(at);
    int c = centroid(at);
    vis[c]=true;
    for(auto to : adj[c]) if(!vis[to]) {
        decomp(to);
    }
    // do useful work
    for(int rep=0;rep<2;++rep) {
        lc.clear();
        lc.add(1,a[c]);
        ans = max(ans,(ll)a[c]);
        for(auto to : adj[c]) if(!vis[to]) {
            dfs(to);
            psum+=a[c];
            ppsum+=a[c];
            d++;
            dfs2(to);
            psum-=a[c];
            ppsum-=a[c];
            --d;
        }
        reverse(all(adj[c]));
    }
    vis[c]=false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    for(int i=1;i<n;++i) {
        int u,v; cin >> u >> v;
        --u,--v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=0;i<n;++i) cin >> a[i];
    decomp(0);
    cout << ans;
}