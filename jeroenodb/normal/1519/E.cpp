#include "bits/stdc++.h"
using namespace std;
#define all(x) begin(x),end(x)
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { string sep; for (const T &x : v) os << sep << x, sep = " "; return os; }
#define debug(a) cerr << "(" << #a << ": " << a << ")\n";
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef array<int,2> pi;
const int mxN = 1e5+1, oo = 1e9;
struct frac {
    ll n,d;
    frac() {}
    frac(ll _n, ll _d) {
        n=_n,d=_d;
        simplify();
    }
    void simplify() {
        auto g = gcd(n,d);
        n/=g,d/=g;
    }
    bool operator==(const frac& o) const {
        return n==o.n and d==o.d;
    }
    bool operator<(const frac& o) const {
        return make_pair(n,d)<make_pair(o.n,o.d);
    }
};
struct graph {
    vector<vector<pi>> adj;
    vector<bool> vis,mark;
    vector<pi> ans;
    graph(int n) {
        adj.resize(n);
        vis.resize(n);
        mark.resize(n);
    }
    void addedge(int i, int j, int id) {
        // cerr << i << " " << j << '\n';
        adj[i].push_back({j,id});
        adj[j].push_back({i,id});
    }
    int dfs(int at, int idf=-1) {
        vis[at]=true;
        mark[at]=true;
        int prev=-1;
        auto consider = [&](int id) {
            if(id==-1) 
                return;
            if(prev==-1) 
                prev=id;
            else {
                ans.push_back({id,prev});
                prev=-1;
            }
        };
        for(auto [to,id] : adj[at]) if(id!=idf) {
            if(vis[to]) {
                if(!mark[to] or to==at) {
                    // consider as leaf
                    consider(id);
                }
            } else {
                int maybe = dfs(to,id);
                if(maybe!=-1) ans.push_back({id,maybe});
                else consider(id);
            }
        }
        mark[at]=false;
        return prev;
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    vector<array<frac,2>> pts(n);
    vector<frac> coords;
    for(auto& [p,q] : pts) {
        int a,b,c,d; cin >> a >> b >> c >> d;
        p = frac((ll)(a+b)*d,(ll)b*c);
        q = frac((ll)a*d, (ll)b*(c+d));
        coords.push_back(p);
        coords.push_back(q);
    }
    sort(all(coords));
    coords.erase(unique(all(coords)),coords.end());
    int k = coords.size();
    graph g(k);
    auto get = [&](const frac& p) {
        return lower_bound(all(coords),p)-coords.begin();
    };
    for(int i=0;i<n;++i) {
        int a = get(pts[i][0]), b = get(pts[i][1]);
        // cerr << a << ' ' << b << '\n';
        g.addedge(a,b,i+1);
    }
    // now reduced to graph problem
    for(int i=0;i<k;++i) {
        if(!g.vis[i]) {
            g.dfs(i);
        }
    }
    cout << g.ans.size() << '\n';
    for(auto ar: g.ans) {
        cout << ar << '\n';
    }
    
}