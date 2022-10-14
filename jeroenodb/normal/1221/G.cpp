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
const int mxN = 40, oo = 1e9;
bitset<mxN> g[mxN];
int main() {
    int n,m; cin >> n >> m;
    if(m==0) {
        cout << 0 << '\n';
        exit(0);
    }
    for(int i=0;i<m;++i) {
        int x,y; cin >> x >> y;
        --x,--y;
        g[x][y]=g[y][x]=1;
    }
    // 111
    ll ans=1LL<<n;
    // 100
    ll cur=1;
    for(int i=0;i<n;++i) if(!g[i].any()) {
        cur*=2;
    }
    ans+=cur;
    // 001
    ans+=cur;
    // 010
    int comps=0;
    {
    bitset<mxN> vis,col;
    cur=1;
    for(int i=0;i<n;++i) if(!vis[i]) {
        cur*=2;
        comps++;
        auto dfs = [&](auto&& self, int at) -> void {
            vis[at]=1;
            for(int to=0;to<n;++to) if(g[at][to]) {
                if(vis[to] and col[to]==col[at]) cur=0;
                else if(!vis[to]) {
                    col[to]=!col[at];
                    self(self,to);
                }
            }
        };
        dfs(dfs,i);
    }
    ans+=cur;
    }
    // 101
    ans-=1LL<<comps;

    // 110 and 011
    // find vertex covers and cliques
    // split in halve, enumerate one, do SOS for the other
    int n2 = n/2;
    vector<int> dp(1<<n2);
    {
    auto rec = [&](auto&& self, int i, int msk) -> void {
        if(i==n2) {
            dp[msk]++;
            return;
        }
        self(self,i+1,msk);
        if((msk&g[i].to_ullong())==0) self(self,i+1,msk|1<<i);
    };
    rec(rec,0,0);
    }
    for(int i=0;i<n2;++i) {
        for(int j=0;j<1<<n2;++j) if(j & (1<<i)) {
            dp[j]+=dp[j ^ (1<<i)];
        }
    }

    {
    typedef unsigned long long ull;
    auto rec = [&](auto&& self, int i, ull msk, int left) -> void {
        if(i==n) {
            ans-=2*dp[left];
            return;
        }
        self(self,i+1,msk,left);
        if((msk&g[i].to_ullong())==0) {
            self(self,i+1,msk|1ULL<<i, left&~g[i].to_ullong());
        }
    };
    rec(rec,n2,0,(1<<n2)-1);
    }
    cout << ans << '\n';
}