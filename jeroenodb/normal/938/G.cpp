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


struct basis {
    vi v;
    void add(int w) {
        for(auto& i : v) w = min(w,w^i);
        if(w) v.push_back(w);
    }
    int reduce(int w) {
        for(auto& i : v) w = min(w,w^i);
        return w;
    }
};


struct dynamicXorPaths {
    struct edge {
        int l,r;
        int u,v,w;
        int o(int at) {
            return u^v^at;
        }
    };
    map<pi,int> edgeids;
    vector<edge> ives; // edges + time interval that they are active.
    vector<array<int,3>> startes; 
    vi touch; // last time this edge was touched
    int totaln;
    dynamicXorPaths(const vector<array<int,3>>& ES, int n) : startes(ES), touch(ES.size()), totaln(n)  {
        // give all edges upfront.
        for(int i=0;i<(int)ES.size();++i) {
            auto& e = startes[i];
            if(e[0]>e[1]) swap(e[0],e[1]);
            edgeids[{e[0],e[1]}]=i;
        }
    }
    int q=0;
    void update(int i, int x) {
        // toggles edge numbered i
        q++;
        auto& [u,v,w] = startes[i];
        if(touch[i]!=-1) {
            ives.push_back({touch[i],q,u,v,w});
            touch[i]=-1; // now deleted
        } else touch[i] = q,w=x;
    }
    void update(int u, int v, int w) {
        if(u>v) swap(u,v);
        if(!edgeids.count({u,v})) {
            edgeids[{u,v}]=startes.size();
            startes.push_back({u,v,w});
            touch.push_back(-1);
        }
        update(edgeids[{u,v}],w);
    }
    vector<int> ans;
    struct query {
        int u,v,t,id,w=0;
    };
    vector<query> qs;
    void addQuery(int u, int v) {
        query myq = {u,v,q,(int)qs.size()};
        qs.push_back(myq);
    }
    vvi adj;
    vi id,pref;
    void solve(int l, int r, vector<edge> es, basis b, int n, vector<query> qs) {
        // remove edges that don't belong to this interval
        es.erase(partition(all(es),[&](const edge& e) {return !(e.r<=l or r<=e.l);}),es.end());
        qs.erase(partition(all(qs),[&](const query& myq) {return l<=myq.t and myq.t<r;}),qs.end());
        adj.assign(n,{});
        id.assign(n,-1),pref.assign(n,0);

        for(int i=0;i<(int)es.size();++i){
            auto& e = es[i];
            if(e.l<=l and r<=e.r) {
                adj[e.u].push_back(i);
                adj[e.v].push_back(i);
            }
        }
        auto dfs = [&](auto&& self, int at, int ef)->void {
            for(auto ei : adj[at]) if(ei!=ef) {
                int to = es[ei].o(at);
                if(id[to]==-1) {
                    pref[to] = es[ei].w^pref[at];
                    id[to]=id[at];
                    self(self,to,ei);
                } else b.add(pref[to]^pref[at]^es[ei].w);
            }
        };
        int cnt=0;
        for(int i=0;i<n;++i) if(id[i]==-1) {
            id[i]=cnt++;
            dfs(dfs,i,-1);
        }
        if(l+1==r) { // base case, we found everything
            // answer queries
            for(auto myq : qs ) {
                ans[myq.id] = b.reduce(pref[myq.u]^pref[myq.v]^myq.w);
            }
            return;
        }
        // compress graph
        es.erase(partition(all(es),[&](const edge& e) {return l<e.l or e.r<r;}),es.end());
        for(auto& e : es)  {
            e.w^=pref[e.u]^pref[e.v];
            e.u = id[e.u], e.v = id[e.v];
        }
        for(auto& myq : qs) {
            myq.w ^= pref[myq.u]^pref[myq.v];
            myq.u = id[myq.u],myq.v = id[myq.v];
        }
        int mid = (l+r)/2;
        solve(l,mid,es,b,cnt,qs);
        solve(mid,r,es,b,cnt,qs);

    }
    vector<int> run() {
        int m = startes.size();
        q++;
        for(int i=0;i<m;++i) {
            auto& [u,v,w] = startes[i];
            if(touch[i]!=-1) ives.push_back({touch[i],q,u,v,w});
        }
        ans.resize(qs.size(),-1);
        solve(0,q,ives,{},totaln,qs);
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m; cin >> n >> m;
    vector<array<int,3>> es(m);

    for(auto& [u,v,w] : es) {
        cin >> u >> v >> w;
        --u,--v;
    }

    dynamicXorPaths paths(es,n);
    int q; cin >> q;
    for(int i=0;i<q;++i) {
        int type,x,y; cin >> type >> x >> y;
        --x,--y;
        if(type==1) {
            int w; cin >> w;
            paths.update(x,y,w);
        } else if(type==2) {
            paths.update(x,y,-1);
        } else {
            paths.addQuery(x,y);
        }
    }
    auto res = paths.run();
    for(auto i : res) cout << i << '\n';

    
}