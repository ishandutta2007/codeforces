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
const int mxN = 2000, oo = 1e9;
// use Dinic
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
    ll dfs(int at=0, ll mn=1e18) {
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
vi xcoord,ycoord;
bool g[mxN][mxN];
typedef complex<int> pt;
#define X real()
#define Y imag()
void read(pt& p) {
    int a,b; cin >> a >> b;
    p = {a,b};
}
pt real(pt p) {
    return pt{lower_bound(all(xcoord),p.X)-xcoord.begin(),lower_bound(all(ycoord),p.Y)-ycoord.begin()};
}
struct rect {
    pt p, q;
    void rd() {
        read(p),read(q);
        q+=pt{1,1};
        xcoord.push_back(p.X);
        xcoord.push_back(q.X);
        ycoord.push_back(p.Y);
        ycoord.push_back(q.Y);
    }
    void paint() {
        p=real(p),q=real(q);
        for(int i=p.X;i<q.X;++i) {
            for(int j=p.Y;j<q.Y;++j) {
                g[i][j]=true;
            }
        }
    }
};
int main() {
    int n,m; cin >> n >> m;
    if(m==0) {
        cout << "0\n";
        exit(0);
    }
    vector<rect> rs(m);
    for(auto& r : rs) r.rd();
    sort(all(xcoord));
    xcoord.erase(unique(all(xcoord)),xcoord.end());
    sort(all(ycoord));
    ycoord.erase(unique(all(ycoord)),ycoord.end());
    for(auto& r : rs) r.paint();
    int L=xcoord.size()-1, R = ycoord.size()-1;
    flow f(2+L+R);
    for(int i=1;i<=L;++i) {
        f.addEdge(0,i,xcoord[i]-xcoord[i-1]);
    }
    for(int i=1;i<=R;++i) {
        f.addEdge(L+i,1+L+R,ycoord[i]-ycoord[i-1]);
    }
    for(int i=0;i<L;++i) {
        for(int j=0;j<R;++j) {
            if(g[i][j]) f.addEdge(i+1,j+1+L,1e9);
        }
    }
    cout << f.solve();
    
}