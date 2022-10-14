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
const int mxN = 3e5+1, oo = 1e9;
vi adj[mxN];
int par[mxN],d[mxN],jmp[mxN],best;
void add(int i) {
    int p = par[i];
    d[i]=1+d[p];
    if(d[p] - d[jmp[p]] == d[jmp[p]] - d[jmp[jmp[p]]]) jmp[i] = jmp[jmp[p]];
    else jmp[i] = p;
}
int jump(int a, int k) {
    int D = max(0,d[a]-k);
    while(d[a]>D) {
        if(d[jmp[a]]>=D) a = jmp[a];
        else a = par[a];
    }
    return a;
}
int lca(int a, int b) {
    if(d[a]<d[b]) swap(a,b);
    a = jump(a,d[a]-d[b]);
    while(a!=b) {
        if(jmp[a]!=jmp[b]) a=jmp[a],b=jmp[b];
        else a=par[a],b=par[b];
    }
    return a;
}
int dist(int a, int b) {
    return d[a]+d[b]-2*d[lca(a,b)];
}
void dfs(int at, int from=0) {
    if(d[best]<d[at]) best=at;
    for(auto to : adj[at]) if(to!=from) {
        par[to]=at;
        add(to);
        dfs(to,at);
    }
}

void solve() {
    int n; cin >> n;
    for(int i=1;i<=n;++i) 
        adj[i].clear();
    for(int i=0;i<n-1;++i) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    jmp[1]=1,par[1]=1,best=1;
    dfs(1);
    int a=best,b=best,diam=-oo;
    vi ord(n); iota(all(ord),1);
    sort(all(ord),[&](int i, int j) {return d[i]>d[j];});
    vector<array<int,2>> ans = {};
    for(auto i : ord) {
        ans.push_back({d[i],(diam+1)/2});
        if(dist(a,i)>max(dist(b,i),diam)) {
            b=i,diam = dist(a,b);
        } else if(dist(b,i)>diam) {
            a=i,diam = dist(a,b);
        }
    }
    // each reasonable pair of diam and ...
    int i=0;
    vi res;
    for(int x=n;x>=1;--x) {
        int cur = oo;
        auto get = [&](int j) {
            cur = min(cur, max(ans[i][0],ans[i][1]+x));
        };
        if(i>0) i--;
        while(i<(int)ans.size()-1 and ans[i][0]>=ans[i][1]+x) {
            get(i);
            ++i;
        }
        get(i);
        res.push_back(cur);
    }
    reverse(all(res));
    cout << res << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
}