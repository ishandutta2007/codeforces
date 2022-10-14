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
const int mxN = 2e5+1, oo = 1e9;
struct DP {
    int best=0;
    void comb(const DP& o) {
        best = max({best,o.best,best+o.best});
    }
    DP root(int v) {
        return {v+max(0,best)};
    }
};
DP comb(DP a, const DP& o) {
    a.comb(o);
    return a;
}
vector<DP> pref[mxN],suf[mxN];
vi adj[mxN];
int a[mxN];
DP dfs(int at, int from) {   
    for(int to : adj[at])if(to!=from) {
        pref[at].push_back(dfs(to,at));
    }
    suf[at]=pref[at];
    pref[at].insert(pref[at].begin(),DP{});
    partial_sum(all(pref[at]),pref[at].begin(),comb);
    suf[at].push_back({});
    partial_sum(suf[at].rbegin(),suf[at].rend(),suf[at].rbegin(),comb);
    return pref[at].back().root(a[at]);
}
DP complement[mxN];
int ans[mxN];
void dfs2(int at, int from=-1, int id=-1) {
    if(from==-1) complement[at] = DP{};
    else complement[at] = comb(comb(complement[from],pref[from][id]),suf[from][id+1]).root(a[from]);
    ans[at] = comb(complement[at],pref[at].back()).root(a[at]).best;
    int toid=0;
    for(auto to : adj[at]) if(to!=from) {
        dfs2(to,at,toid++);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    for(int i=0;i<n;++i) {
        cin >> a[i];
        if(!a[i]) a[i]=-1;
    } 
    for(int i=1;i<n;++i) {
        int u,v; cin >> u >> v;
        --u,--v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0,-1);
    dfs2(0);
    for(int i=0;i<n;++i) {
        cout << ans[i] << ' ';
    }
}