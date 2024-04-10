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
const int mxN = 18*18+18;
const ll oo = 1e16;
const int mxM=2000;
struct flow {
    // Source is Node 0;
    // Sink is node n-1
    // Uses capacity scaling.
    // Runtime: O(|E|^2 *(1+log2(C )))
    struct edge {
        ll f,c;
        int to;
    };
    typedef vector<edge> ve;
    vector<vector<int>> adj;
    vector<edge> edges;
    int n;
    ll scale=0;
    flow(int _n) {
        n=_n;
        adj.resize(n);
    }
    void addEdge(int a, int b, ll w, bool directed = true) {
        scale = max(w,scale);
        adj[a].push_back((int)edges.size());
        adj[b].push_back((int)edges.size()+1);
        edges.push_back({0,w,b});
        edges.push_back({0,directed?0:w,a});
    }
    bitset<mxN> visited;
    void dfs2(int at=0) {
        visited[at]=true;
        for(int i : adj[at]) {
            auto& e = edges[i];
            if(e.c!=e.f and !visited[e.to]) {
                dfs2(e.to);
            }
        }
    }
    ll dfs(int at=0, ll mn=oo) {
        if(at==n-1) return mn;
        visited[at] = true;
        for(int i: adj[at]) {
            auto& e = edges[i];
            if(!visited[e.to] and e.f+scale<=e.c) {
                ll tmp = min(mn,e.c-e.f);
                tmp =  min(tmp,dfs(e.to,tmp));
                if(tmp) {
                    e.f+=tmp;
                    auto& o = edges[i^1];
                    o.f-=tmp;
                    return tmp;
                }
            }
        }
        return 0;
    }

    ll solve() {
        ll res = 0;
        while(true) {
            visited.reset();
            ll tmp = dfs();
            if(tmp!=0) res+=tmp;
            else {
                scale/=2;
                if(!scale) break;
            }
        }
        return res;
    }
};
const ll big=1e12;
int id[18][19];
int main() {
    int n,m; cin >> n >> m;
    int total=1;
    for(int i=0;i<n;++i) for(int j=0;j<=n;++j) id[i][j]=total++;
    flow f(total+1);
    int T = total;
    int c[18] = {};
    for(int i=0;i<m;++i) {
        int x,y,w; cin >> x >> y >> w,--x,--y;
        c[x]+=w,c[y]-=w;
        for(int j=0;j<n;++j) f.addEdge(id[y][j],id[x][j+1],oo);
    }
    for(int i=0;i<n;++i) {
        for(int j=0;j<n;++j) f.addEdge(id[i][j],id[i][j+1],c[i]*j+big);
        f.addEdge(0,id[i][0],oo);
        f.addEdge(id[i][n],T,oo);
    }
    f.solve();
    f.visited.reset();
    f.dfs2();
    vi ans(n);
    for(int i=0;i<n;++i) {
        for(int j=0;j<n;++j) {
            if(f.visited[id[i][j]]) ans[i]=j;
        }
    }
    cout << ans << '\n';


}