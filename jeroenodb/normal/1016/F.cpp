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
vector<vector<pi>> adj;
vector<bool> vis;
vi par;
vector<ll> pref;
void dfs(int at) {
    vis[at]=true;
    for(auto [to,w] : adj[at]) if(!vis[to]) {
        pref[to]=pref[at]+w;
        par[to]=at;
        dfs(to);
    }
}
int cnt=0;
void dfs2(int at) {
    cnt++;
    vis[at]=true;
    for(auto [to,w] : adj[at]) if(!vis[to]) {
        dfs2(to);
    }
    vis[at]=false;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m; cin >> n >> m;
    vis.resize(n+1),adj.resize(n+1);
    pref.resize(n+1),par.resize(n+1);
    for(int i=0;i<n-1;++i) {
        int u,v,w; cin >> u >>v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    dfs(1);
    fill(all(vis),0);
    ll best = 0, outofway=-oo;
    int at = n;
    ll total = pref[n];
    vi rts;
    while(at) {
        vis[at]=true;
        vis[par[at]]=true;
        cnt=0;
        int bestw=-1;
        for(auto [c,w] : adj[at]) if(!vis[c]) {
            dfs2(c);
            bestw=w;
        }
        if(cnt>1) {
            best = total;
            break;
        }
        if(outofway!=-oo) best = max(best, pref[at]+outofway);
        if(!rts.empty()) outofway = max(outofway, total-pref[rts.back()]);
        if(bestw!=-1) {
            best = max(best,pref[at]+bestw + outofway);
            outofway = max(outofway, total-pref[at]+bestw);
        }
        rts.push_back(at);
        at=par[at];
        
    }
    while(m--) {
        int x; cin >> x;
        cout << min(best+x,total) << '\n';
    }
}