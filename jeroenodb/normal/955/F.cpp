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
const int mxN = 3e5+1, oo = 1e9, LG = 21;
typedef vector<array<int,LG+1>> DS; // cnt[k][depth] stores how many trees have that

DS dp[mxN];
struct DS2 {
    DS2(int n) {
        sum=n-1;   
    }
    DS2(){}
    int size() {return best.size();}
    ll sum=0;
    vi best = {0,0};
    void update(int i, int d) {
        while(best.size()<=i) best.push_back(1);
        int dif = max(0,d-best[i]);
        sum+=dif, best[i]+=dif;
    }
};
void merge(DS2& a, DS2& b) {
    if(a.size()<b.size()) swap(a,b);
    for(int i=2;i<b.size();++i) {
        int dif = max(0,b.best[i]-a.best[i]);
        a.sum+=dif,a.best[i]+=dif;
    }
}
DS2 mxdp[mxN];
vi adj[mxN];
int mxd[mxN],dd[mxN];
ll ans=0;
int n;
void dfs(int at, int from) {
    if(from) adj[at].erase(find(all(adj[at]),from));
    mxd[at]=dd[at];
    dp[at].resize(adj[at].size()+1);
    auto& c = mxdp[at];
    c = DS2(n);
    for(int to : adj[at]) {
        dd[to]=dd[at]+1;
        dfs(to,at);
        merge(c,mxdp[to]);
        mxd[at]=max(mxd[at],mxd[to]);
        int sz = min(dp[at].size(),dp[to].size());
        for(int k=2;k<sz;++k) {
            for(int j=LG;j>=0;--j) {
                dp[at][k][j]+=dp[to][k][j];
            }
        }
    }
    
    for(int k=2;k<=(int)adj[at].size();++k) {
        int myd = 2;
        for(int d=LG;d>=0;--d) {
            if(dp[at][k][d]>=k) {
                myd = max(d+1,myd);
                break;
            }
        }
        dp[at][k] = array<int,22>();
        fill(dp[at][k].begin(),dp[at][k].begin()+myd+1,1);
        c.update(k,myd);
    }
    ans+=mxd[at]-dd[at]+1;
    ans+=c.sum;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i=0;i<n-1;++i) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0);
    cout << ans << '\n';
}