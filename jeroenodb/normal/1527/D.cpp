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
vi adj[mxN];
int sz[mxN],par[mxN];
bitset<mxN> vis;
void dfs(int at, int from=-1) {
    sz[at]=1;
    for(int to: adj[at]) if(to!=from) {
        par[to]=at;
        dfs(to,at);
        sz[at]+=sz[to];
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        for(int i=0;i<n;++i) adj[i].clear(),vis[i]=false;
        for(int i=0;i<n-1;++i) {
            int a,b; cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        dfs(0);
        vector<ll> ans(n+1);
        for(int to: adj[0]) {
            ans[0]+=(ll)sz[to]*(sz[to]-1)/2;
        }
        ll p = (ll)n*(n-1)/2 - ans[0];
        vis[0]=true;
        for(int i=1,l=0,r=0;i<n;++i) {
            // invariant: p = # paths with mex >=i
            if(vis[i]) continue;
            int at=i;
            int s=sz[at];
            while(!vis[at]) {
                vis[at]=true;
                sz[par[at]]-=s;
                s+=sz[par[at]];
                at=par[at];
            }
            if(l==at) {
                // paths with mex>i
                ans[i] = p-(ll)sz[i]*sz[r];
                p-=ans[i];
                l=i;
            } else if(r==at) {
                // paths with mex>i
                ans[i] = p-(ll)sz[i]*sz[l];
                p-=ans[i];
                r=i;
            } else {
                ans[i]=p;
                p=0;
                break;
            }
        }
        ans[n]=p;
        cout << ans << '\n';
        


    }
}