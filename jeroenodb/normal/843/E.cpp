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
const int mxN = 2e3+1, oo = 1e9;
/*
minimum number of edges that are saturated is equivalent to mincut
when edges have integer coefs
There are extra constraints because 0-edges should not result in augmenting paths
u is reachable via some path, and uv is a 0-edge, and v can reach the sink via some path
Then u and v should be on the same side of the minimum cut, otherwise there's an augmenting path
Make their capacity = infinity.

For mincut, the rest should all be cost 1.

Find mincut and maxflow
Could be that flow goes through 0-edges...
If you remove the 0-edges, mincut could become smaller
If you have some path with 0-edge in between, than it must go through cut, so no augmenting path...
Ok, then we start constructing the flow.
Pick any edge, construct path that goes through 1 edges, ends in u, and then goes through v, add 1 capacity to them.

*/
struct flow {
    // Source is Node 0;
    // Sink is node n-1
    // Uses capacity scaling.
    // Runtime: O(|E|^2 *(1+log2(C )))
    struct edge {
        ll f,c;
        int at,to;
    };
    typedef vector<edge> ve;
    vector<vector<int>> adj;
    vector<edge> edges;
    int n;
    ll scale=1;
    flow(int _n) {
        n=_n;
        adj.resize(n);
    }
    void addEdge(int a, int b, ll w, bool directed = true) {
        adj[a].push_back((int)edges.size());
        adj[b].push_back((int)edges.size()+1);
        edges.push_back({0,w,a,b});
        edges.push_back({0,directed?0:w,b,a});
    }
    bitset<mxN> visited;
    int T;
    ll dfs(int at=0, ll mn=1e18) {
        if(at==T) return mn;
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

    ll solve(int s, int t) {
        T=t;
        ll res = 0;
        while(true) {
            visited.reset();
            ll tmp = dfs(s);
            if(tmp!=0) res+=tmp;
            else {
                scale/=2;
                if(!scale) break;
            }
        }
        return res;
    }
    vector<pi> mincut() {
        vector<pi> ans;
        for(int i=0;i<edges.size();i+=2) {
            int u = edges[i].at, v = edges[i].to;
            if(visited[u] and !visited[v]) {
                ans.push_back({u,v});
            }
        }
        return ans;
    }
};
int main() {
    int n,m,s,t; cin >> n >> m >> s >> t,--s,--t;
    vector<vector<array<int,3>>> adj(n);
    flow f(n);

    vector<array<int,3>> es(m);
    for(int i=0;i<m;++i) {
        auto&  [u,v,g] = es[i];
        cin >> u >> v >> g;
        --u,--v;
        if(g==0) f.addEdge(u,v,oo);
        else {
            f.addEdge(u,v,1);
            adj[u].push_back({v,0,i});
        }
    }
    for(auto& [u,v,g] : es) {
        if(g==1) f.addEdge(v,u,oo);
    }
    
    int k = f.solve(s,t);
    cout << k << '\n';
    vector<pi> saturated=f.mincut();
    sort(all(saturated));
    assert(saturated.size()==k);
    // construct the flow
    
    auto augment = [&](int u, int v) {
        vector<bool> vis(n);
        int stop=u;
        auto dfs = [&](auto&& rec, int at) -> bool {
            vis[at]=1;
            if(at ==stop) {
                return true;
            }
            for(auto& [to,w,id] : adj[at]) if(!vis[to]) {
                if(rec(rec,to)) {
                    w++;
                    return true;
                }
            }
            return false;
        };
        if(dfs(dfs,v)) return;
        stop=u;
        dfs(dfs,s);
        fill(all(vis),0);
        stop=t;
        dfs(dfs,v);
        

    };
    while(true) {
        bool found=false;
        for(int at=0;at<n;++at) {
            for(auto& [to,w,id] : adj[at]) if(w==0) {
                found=true;
                augment(at,to);
                w++;
            }
        }
        if(!found) break;
    }
    vi balance(n);
    for(int at=0;at<n;++at) {
        for(auto& [to,w,id] : adj[at]) {
            balance[at]-=w;
            balance[to]+=w;
            es[id][2]=w;
        }
    }
    for(int i=0;i<n;++i) if(i!=s and i!=t) {
        assert(balance[i]==0);
    }
    int cnt=0;
    for(auto& [u,v,g] : es) {
        int tmp = binary_search(all(saturated),pi{u,v});
        cnt+=tmp;
        if(g==0) cout << "0 1\n";
        else cout << g << ' ' << g + !tmp  << '\n';
    }
    assert(cnt==k);
    
}