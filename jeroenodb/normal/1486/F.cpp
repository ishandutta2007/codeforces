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
const int mxN = 3e5+2, oo = 1e9, LG=20;
int up[mxN][LG];
vector<pi> pathtop[mxN];
map<pi,int> have;
vi adj[mxN];
int dep[mxN],pref[mxN];
void dfs(int at=1, int from=1) {
    up[at][0] = from;
    for(int to : adj[at]) if(to!=from) {
        dep[to]=dep[at]+1;
        dfs(to,at);
    }
} 
int jump(int a, int k) {
    for(int i=0;1<<i <=k;++i) {
        if(1<<i & k) a = up[a][i];
    }
    return a;
}
pi LCAChild(int a, int b) {
    if(a==b) return {a,b};
    if(dep[a]<dep[b]) swap(a,b);
    int tmp = jump(a,dep[a]-dep[b]);
    if(tmp==b) {
        return {jump(a,dep[a]-dep[b]-1),b};
    }
    a=tmp;
    for(int i=LG-1;i>=0;--i) {
        if(up[a][i]!=up[b][i]) {
            a=up[a][i],b=up[b][i];
        }
    }
    if(a>b) swap(a,b);
    return {a,b};
}
ll ans=0;
void dfs2(int at=1,int from=1) {
    for(int to : adj[at]) if(to!=from) {
        dfs2(to,at);
        pref[at]+=pref[to];
    }
    int left = pathtop[at].size();
    for(auto [c,d] : pathtop[at]) {
        left--;
        ans+=pref[at]+left;
        have[{c,d}]--;
        if(c!=d and d==at) {
            pref[c]--;
            ans-=pref[c];
        } else if(c!=d) {
            pref[c]--,pref[d]--;
            ans+=have[{c,d}]-pref[c]-pref[d];
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    for(int i=0;i<n-1;++i) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs();
    for(int j=1;j<LG;++j) {
        for(int i=1;i<=n;++i) {
            up[i][j]=up[up[i][j-1]][j-1];
        }
    }
    int m; cin >> m;
    while(m--) {
        int a,b; cin >> a >> b;
        
        auto [c,d] = LCAChild(a,b);
        pref[a]++,pref[b]++;
        have[{c,d}]++;
        if(c==d) pref[c]-=2, pathtop[c].push_back({c,c});
        else pref[up[c][0]]-=2, pathtop[up[c][0]].push_back({c,d});
    }
    dfs2();
    cout << ans << '\n';
}