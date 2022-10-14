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
const int mxN = 1e5+1, oo = 1e9;
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
template<class I> I rnd(I l,I r){return std::uniform_int_distribution<I>(l,r)(rng);}
struct graph {
    int n;
    vvi adj;
    vector<bool> vis,mark;
    graph(int N) : n(N),adj(N),vis(N),mark(N) {}
    void addE(int u,int v) {
        adj[u].push_back(v);
    }
    bool dfsC(int at) {
        mark[at]=vis[at]=true;
        for(int to : adj[at]) {
            if(!vis[to]) {
                if(!dfsC(to)) return false;
            } else if(!mark[to]) {
                // non-tree edge that isn't a backedge!
                return false;
            }
        }
        mark[at]=false;
        return true;
    }
    bool good(int at) {
        fill(all(vis),0);
        fill(all(mark),0);
        return dfsC(at);
    }
    vi ans;
    vi in, low,low2;
    vector<bool> bad;
    int t=0;
    void dfs(int at) {
        vis[at]=true;
        low2[at] = low[at] = in[at] = t++;
        auto update = [&](int up) {
            if(up<=low[at]) {
                low2[at]=low[at];
                low[at]=up;
            } else low2[at]= min(low2[at],up);
        };
        for(int to : adj[at]) {
            if(vis[to]) {
                update(in[to]);
            } else {
                dfs(to);
                update(low[to]);
                update(low2[to]);
            }
        }
        bad[in[at]] = low2[at]<in[at];
    }
    void dfsB(int at) {
        vis[at]=true;
        bad[in[at]] =bad[in[at]] or bad[low[at]];
        for(int to : adj[at]) if(!vis[to]) {
            dfsB(to);
        }
        if(!bad[in[at]]) ans.push_back(at+1);
    }
    vi num(int root) {
        fill(all(vis),0);
        in.resize(n);
        low.resize(n,-oo);
        low2.resize(n,-oo);
        bad.resize(n);
        dfs(root);
        fill(all(vis),0);
        dfsB(root);
        return ans;
    }
};
void solve() {
    int n,m; cin >> n >> m;

    vi shuf(n);
    iota(all(shuf),0);
    shuffle(all(shuf),rng);
    while(shuf.size()>160) shuf.pop_back();
    
    graph g(n);
    for(int i=0;i<m;++i) {
        int u,v; cin >> u >> v,--u,--v;
        g.addE(u,v);
    }
    for(auto rt : shuf) {
        if(g.good(rt)) {
            auto ans = g.num(rt);
            sort(all(ans));
            if(ans.size()*5<n) {
                cout << "-1\n";
            } else cout << ans << '\n';
            return;
        }
    }

    cout << "-1\n";

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
}