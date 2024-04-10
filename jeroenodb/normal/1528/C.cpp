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
int in[mxN],out[mxN],cnt;
int adj[mxN],adj2[mxN];
int nxt[mxN], nxt2[mxN];
void dfspre(int at) {
    in[at] = cnt++;
    for(int to = adj2[at];to;to=nxt2[to]) {
        dfspre(to);
    }
    out[in[at]]=cnt-1;
}
set<int> active;
int ans;
void dfs(int at) {
    int inat = in[at];
    auto it = active.lower_bound(inat);
    bool changed=true;
    int par=-1;
    if(it==active.end() or *it>out[inat]) {
        if(it!=active.begin()) {
            par = *--it;
            if(out[par]>=inat) {
                active.erase(it);
            } else par=-1;
        }
        active.insert(inat);
    }
    ans = max(ans,(int)active.size());
    for(int to = adj[at];to;to=nxt[to]) {
        dfs(to);
    }
    if(changed) {
        active.erase(inat);
        if(par!=-1) active.insert(par);
    }
}
void read(int n, int* ad, int* nx) {
    ad[0] = 0;
    for(int i=1;i<n;++i) {
        int par; cin >> par,par--;
        if(ad[par]) {
            nx[i]=ad[par];
        } else nx[i]=0;
        ad[par]=i;
        ad[i]=0;
    }
}
void solve() {
    int n; cin >> n;
    read(n,adj,nxt);
    read(n,adj2,nxt2);
    cnt=0;
    dfspre(0);
    ans=0;
    dfs(0);
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        solve();
    }
}