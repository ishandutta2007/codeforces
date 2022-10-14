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
const int mxN = 1e3+1, oo = 1e9;
vi adj[mxN];
int sz[mxN],n;
void dfsz(int at, int from) {
    sz[at]=1;
    for(auto to : adj[at]) if(to!=from) {
        dfsz(to,at);
        sz[at]+=sz[to];
    }
}
int centroid(int at) {
    int from=-1;
    bool done=false;
    while(!done) {
        done=true;
        for(auto to : adj[at]) if(to!=from) {
            if(sz[to]>n/2) {
                done=false;
                from=at;
                at=to;
                break;
            }
        }
    }
    return at;
}
int need[2] = {}, step[2]={1,0};
int d[mxN];
bool isBig;
void dfs(int at, int from) {
    need[isBig]+=step[isBig];
    d[at]=need[isBig];
    cout << from << ' ' << at << ' ' << d[at]-d[from] << '\n';
    
    for(auto to : adj[at]) if(to!=from) {
        dfs(to,at);
    }
}
int main() {
    cin >> n;
    for(int i=1;i<n;++i) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfsz(1,0);
    int c = centroid(1);
    dfsz(c,0);
    // knapsack
    vi from(n+1,-1);
    from[0]=-2;
    for(auto to : adj[c]) {
        int w = sz[to];
        for(int i=n-w;i>=0;--i) {
            if(from[i]!=-1 and from[i+w]==-1) {
                from[i+w]=to;
            }
        }
    }
    int a = n/2;
    while(from[a]==-1) 
        --a;
    vector<bool> small(n+1);
    step[1] = a+1;
    while(a!=0) {
        small[from[a]]=true;
        a-=sz[from[a]];
    }
    for(auto to : adj[c]) {
        isBig=!small[to];
        dfs(to,c);
    }


}