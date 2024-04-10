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
const int mxN = 1e5+1, oo = 1e9, D=52;
vvi adj,rev;
vector<bitset<D>> museums;
struct SCC {
    int n,d; // parameters of graph
    vi dp,boss,lastseen,order;
    vector<bitset<D>> vis;
    int bid,t,val; // extra state for DFS
    int id(int at, int tt) {return at*d+tt;}
    SCC(int nn, int dd) {
        n=nn,d=dd;
        dp.resize(n*d);
        boss=dp;
        vis.resize(n);
    }
    void inc() {
        if(++t >= d) t=0;
    }
    void dcr() {
        if(--t < 0) t=d-1;
    }
    void dfs(int at) {
        vis[at][t]=true;
        dcr();
        for(int to: rev[at]) if(!vis[to][t]) {
            dfs(to);
        }
        inc();
        order.push_back(id(at,t));
    }
    void dfs2(int at) {
        vis[at][t]=true;
        if(museums[at][t] and lastseen[at]!=bid) {
            lastseen[at] = bid;
            val++;
        }
        boss[id(at,t)]=bid;
        inc();
        for(int to: adj[at]) {
            if(!vis[to][t]) dfs2(to);
            else dp[bid] = max(dp[bid],dp[boss[id(to,t)]]);
        }
        dcr();
    }
    void run() {
        order.reserve(n*d);
        for(int j=0;j<d;++j) for(int i=0;i<n;++i) if(!vis[i][j]) {
            t=j; dfs(i);
        }
        for(auto& i : vis) i.reset();
        reverse(all(order));
        lastseen.resize(n,-1);
        for(auto i : order) {
            int at = i/d;
            t=i%d;
            if(!vis[at][t]) {
                val=0;
                bid=i,dfs2(at);
                dp[i]+=val;
            }
        }
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,d; cin >> n >> m >> d;
    adj.resize(n),rev.resize(n);
    while(m--) {
        int u,v; cin >> u >> v,--u,--v;
        adj[u].push_back(v);
        rev[v].push_back(u);
    }
    museums.resize(n);
    for(int i=0;i<n;++i) {
        string s; cin >> s;
        for(int j=0;j<d;++j) museums[i][j]= (s[j]=='1');
    }
    SCC scc(n,d);
    scc.run();
    cout << scc.dp[scc.boss[0]] << '\n';

}