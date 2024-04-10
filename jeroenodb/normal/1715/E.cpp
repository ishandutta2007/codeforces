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
const int mxN = 1e5+1;
const ll oo = 1e18;
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
		assert(!empty());
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
};
void cmin(ll& a, ll b) {a=min(a,b);}
int main() {
    int n,m,k; cin >> n >> m >> k;
    vector<vector<pi>> adj(n);
    while(m--) {
        int u,v,w; cin >> u >> v >> w;
        --u,--v;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    vector<ll> dp(n,oo);
    dp[0]=0;
    auto dijkstra = [&]() {
        struct el {
            int at;
            ll d;
            bool operator<(const el& o)const {
                return d>o.d;
            }
        };
        priority_queue<el> pq;
        for(int i=0;i<n;++i) pq.push({i,dp[i]});
        while(!pq.empty()) {
            auto e = pq.top(); pq.pop();
            if(e.d>dp[e.at]) continue;
            for(auto [to,w] : adj[e.at]) {
                if(dp[to]>dp[e.at]+w) {
                    dp[to] = dp[e.at]+w;
                    pq.push({to,dp[e.at]+w});
                }
            }
        }
    };
    for(int i=0;i<k;++i) {
        
        LineContainer lc;
        dijkstra();
        vector<ll> ndp = dp;
        for(ll at=0;at<n;++at) {
            if(dp[at]!=oo) lc.add(2*at,-dp[at]-at*at);
        }
        for(ll at=0;at<n;++at) {
            cmin(ndp[at],-lc.query(at)+at*at);
        }
        swap(dp,ndp);
    }
    dijkstra();
    cout << dp << '\n';

}