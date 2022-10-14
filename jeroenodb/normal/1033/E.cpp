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
map<vi,int> cache;
int query(vi v) {
    sort(all(v));
    if(v.size()<=1) return 0;
    if(cache.count(v)) return cache[v];
    cout << "? " << v.size() << '\n' << v << endl;
    int res; cin >> res;
    return cache[v]=res;
}
bool between(vi a, vi b) {
    vi c = a;
    c.insert(c.end(),all(b));
    return (query(c)-query(a)-query(b))!=0;
}
int main() {
    // find spanning tree
    int n; cin >> n;
    
    auto findE = [&](vi a, vi b) {
        // find any edge between vertex sets a and b
        auto lo = b.begin(),hi = b.end();
        while(hi-lo>1) {
            auto mid = lo+(hi-lo)/2;
            if(between(a,vector(b.begin(),mid))) {
                hi = mid;
            } else lo = mid;
        }
        int v=*lo;
        lo = a.begin(),hi = a.end();
        while(hi-lo>1) {
            auto mid = lo+(hi-lo)/2;
            if(between(vector(a.begin(),mid),{v})) {
                hi = mid;
            } else lo = mid;
        }
        return pi{*lo,v};
    };
    vi a = {1};
    vi b;
    vector<pi> es;
    for(int i=2;i<=n;++i) {
        b.push_back(i);
    }

    while(a.size()<n) {
        auto [u,v] = findE(a,b);
        es.push_back({u,v});
        a.push_back(v);
        b.erase(find(all(b),v));
    }
    // found spanning tree
    // now do bipartite thing
    vvi adj(n+1);
    for(auto [u,v] : es) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> col(n+1);
    {
        auto dfs = [&](auto self, int at, int from) -> void {
            for(int to : adj[at]) if(to!=from) {
                col[to]=!col[at];
                self(self,to,at);
            }
        };
        dfs(dfs,1,1);
    }
    vi pr,pb;
    for(int i=1;i<=n;++i) {
        if(col[i]) pr.push_back(i);
        else pb.push_back(i);
    }
    if(query(pr)) {
        swap(pr,pb);
    }
    if(query(pb)) {
        // need to find the bad edge
        auto lo=pb.begin(),hi=pb.end();
        while(true) {
            auto mid = lo + (hi-lo)/2;
            if(query(vector(lo,mid))) {
                hi = mid;
            } else if(query(vector(mid,hi))) {
                lo = mid;
            } else {
                auto [u,v] = findE(vector(lo,mid),vector(mid,hi));
                adj[u].push_back(v);
                adj[v].push_back(u);
                break;
            }
        }
        vector<bool> vis(n+1),mark(n+1);
        vi par(n+1);
        auto dfs = [&](auto self, int at, int from) -> void {
            vis[at]=true;
            mark[at]=true;
            for(auto to : adj[at]) if(to!=from) {
                if(!vis[to]) {
                    par[to]=at;
                    self(self,to,at);
                } else if(mark[to]) {
                    vi res = {at};
                    while(res.back()!=to) {
                        res.push_back(par[res.back()]);
                    }
                    cout << "N " << res.size() << '\n' << res << endl;
                    exit(0);
                }
            }
            mark[at]=false;
        };
        dfs(dfs,1,1);
    } else {
        cout << "Y " << pb.size() << '\n' << pb << endl;
    }
}