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


struct graph {

    vvi adj;
    vi par,d;
    vector<bool> mark,vis;

    struct cycle {
        int ch,par, leaf;
    };
    vector<cycle> cycs;
    int deepest=0;
    graph(int n) : adj(n),par(n),d(n),mark(n),vis(n) {}
    void addE(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void dfs(int at, int from) {
        vi bs;
        bool leaf=true;
        vis[at]=mark[at]=true;
        if(d[at]>d[deepest]) deepest=at;
        for(auto to : adj[at])if(to!=from) {
            if(!vis[to]) {
                leaf=false;
                par[to]=at;
                d[to]=d[at]+1;
                dfs(to,at);
            } else if(mark[to]) {
                // backedge
                bs.push_back(to);
            }
        }
        if(leaf) {
            assert(bs.size()>=2);
            bool found=false;
            for(auto b : bs) {
                if((d[at]-d[b])%3!=2) {
                    cycs.push_back({par[at],b,at});
                    found=true;
                    break;
                }
            }
            if(!found) {
                if(d[bs[0]]<d[bs[1]]) swap(bs[0],bs[1]);
                cycs.push_back({bs[0],bs[1],at});
            }
        }
        mark[at]=false;
    }
    void output(int k) {
        int n = adj.size();
        if(d[deepest]+1>=n/k) {
            cout << "PATH\n";
            vi p = {deepest};
            while(p.back()!=0) {
                p.push_back(par[p.back()]);
            }
            cout << p.size() << '\n';
            for(auto i : p) {
                cout << i+1 << ' ';
            }
            cout << '\n';
        } else {
            cout << "CYCLES\n";
            cycs.resize(k);
            for(auto& c : cycs) {
                vi p = {c.leaf,c.ch};
                while(p.back()!=c.par) {
                    p.push_back(par[p.back()]);
                }
                cout << p.size() << '\n';
                for(auto& i : p) {
                    cout << i+1 << ' ';
                }
                cout << '\n';
            }
        }
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int  n,m,k; cin >> n >> m >> k;
    graph g(n);
    while(m--) {
        int u,v; cin >> u >> v;
        --u,--v;
        g.addE(u,v);
    }
    g.dfs(0,0);
    g.output(k);
    
}