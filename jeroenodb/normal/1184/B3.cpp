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
const int oo = 1e9 + 1;
const int mxN = 5e3+2, mxM = 30e3+2;
// use Dinic
struct flow {
    // Source is Node 0;
    // Sink is node n-1
    // Uses capacity scaling.
    // Instead of adjacency vectors with pointers to edges inside, use nxt pointer
    struct edge {
        ll f,c;
        int to;
    };
    typedef vector<edge> ve;
    vector<int> adj[mxN];
    ve edges;
    int n;
    ll scale=1;
    flow(int _n) {
        n=_n;
    }
    map<pi,int> mapedge;
    void addEdge(int a, int b, ll w) {
        adj[a].push_back((int)edges.size());
        adj[b].push_back((int)edges.size()+1);
        edges.push_back({0,w,b});
        edges.push_back({0,0,a});
    }
 
    int q[mxN], level[mxN];
    bitset<mxN> visited;
    int leveljump[mxM*2], lend[mxN], iter[mxN];
    bool constructlevels() {
        visited.reset();
        int tail = 1, beginp = 0;
        q[0] = 0; level[0] = 0; visited[0] = true; // visit the first node, node 0
        bool finished=false;
        for(int head=0;head<tail;++head) {
            int at = q[head];
            iter[at] = beginp;
            if(at==n-1) {
                finished = true; 
                continue; // edges from the sink to other nodes are not important
            }
            for(int ei: adj[at]) {
                const auto& e = edges[ei];
                if(e.c-e.f<scale or (visited[e.to] and level[e.to]!=level[at]+1)) continue;
                leveljump[beginp++] = ei;
                if(!visited[e.to]) {
                    visited[e.to] = true;
                    q[tail++] = e.to;
                    level[e.to] = level[at]+1;
                }
            }
            lend[at] = beginp;
        }
        return finished;
    }
 
    ll dfs(int at, ll f) {
        if(at==n-1) {
            // debug(f);
            return f;
        }
        for(int& id = iter[at];id<lend[at];++id) {
            int eid = leveljump[id];
            auto& e = edges[eid];
            if(e.c-e.f>0) {
                auto ff = dfs(e.to, min(f,e.c-e.f));
                if(ff!=0) {
                    e.f+=ff;
                    edges[eid^1].f-=ff;
                    return ff;
                }
            } 
        }
        return 0;
    }
    ll solve() {
        ll res = 0;
        while(true) {
            bool good = constructlevels();
            if(!good) {
                break;
            } else {
                // Do DFS's
                ll tmp;
                do {
                    tmp = dfs(0,1e18);
                    res+=tmp;
                } while(tmp>0);
            }
        }
        return res;
    }
};
int g[mxN][mxN];
#define rep(i,n) for(int i=0;i<n;++i)
struct bestbase {
    set<pi> s; // pairs of (-defence,gold) 
    void add(pi p) {
        p.first=-p.first;
        auto it = s.lower_bound(p);
        if(it!=s.end() and it->second>=p.second) {
            return;
        }
        bool good;
        tie(it,good) = s.insert(p);
        while(it!=s.begin()) {
            --it;
            if(it->second<p.second) {
                it = s.erase(it);
            } else break;
        }
    }
    int get(int a) {
        auto it = s.lower_bound({-a,-oo});
        if(it==s.end()) {
            return -oo;
        }
        return it->second;
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m; cin >> n >> m;
    for(int i=0;i<n;++i) fill_n(g[i],n,oo),g[i][i]=0;
    while(m--) {
        int a,b; cin >> a >> b;
        --a,--b;
        g[a][b]=g[b][a]=1;
    }
    rep(j,n) rep(i,n) rep(k,n) {
        if(g[i][j]+g[j][k]<g[i][k]) g[i][k] = g[i][j]+g[j][k];
    }
    int s,b,k; cin >> s >> b>> k;
    vvi shs(n);
    struct ship {
        int x,a,f,p;
        int profit=-oo;
        void read(){cin >> x >> a >> f >> p; --x;}
    };
    vector<ship> sh(s);
    {
    int id=0;
    for(auto& i : sh) {
        i.read();
        shs[i.x].push_back(id++);
    }
    }
    vector<vector<pi>> bases(n);
    while(b--) {
        int x,d,g; cin >> x >> d >> g;
        --x;
        bases[x].push_back({d,g});
    }
    for(int at=0;at<n;++at) {
        vi ord(n); iota(all(ord),0);
        sort(all(ord),[&](int i, int j){return g[at][i]<g[at][j];});
        auto& v = shs[at];
        sort(all(v),[&](int i, int j) {return sh[i].f<sh[j].f;});
        auto it = v.begin(),it2=ord.begin();
        bestbase bb;
        while(it!=v.end()) {
            if(it2==ord.end() or sh[*it].f<g[at][*it2]) {
                sh[*it].profit = bb.get(sh[*it].a)-sh[*it].p;
                ++it;
            } else {
                for(auto p : bases[*it2]) {
                    bb.add(p);
                }
                ++it2;
            }
        }
    }
    vi lab(s,0);
    vector<pi> es(k);
    for(auto& [a,b] : es) {
        cin >> a >> b,--a,--b;
        lab[a]=1,lab[b]=1;
    }
    int pref=0;
    for(int i=0;i<s;++i) {
        pref+=lab[i];
        if(lab[i]) lab[i]=pref;
        else lab[i]=-1;
    }
    flow f(pref+2);
    const ll B = 4e14;
    ll ans=0;
    int goodV=0;
    for(int i=0;i<s;++i) {
        auto& mys = sh[i];
        if(lab[i]==-1) {
            ans+=max(0, mys.profit);
        } else {
            auto j = lab[i];
            if(mys.profit>0) f.addEdge(0,j,B), f.addEdge(j,pref+1,B-mys.profit),goodV++;
            else if(mys.profit>-oo) {
                f.addEdge(j,pref+1,-mys.profit);
            } else f.addEdge(j,pref+1,B);
        }
    }
    for(auto [a,b] : es) {
        f.addEdge(lab[a],lab[b],B);
    }
    ans+=B*goodV - f.solve();

    cout << ans << '\n';
}