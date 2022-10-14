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
const int mxN = 1e7+1, oo = 1e9;
typedef array<double,101> D;
const int mxDP = 1e6 + 1;
double dp[mxDP][6] = {};
double ncr(int n, int k) {
    if(n<k) return 0;
    return dp[n][k];
}
double calc(int total, int good, int take, int totaltake) {
    auto num = ncr(good,take)*ncr(total-good,totaltake-take);
    if(num==0) return 0;
    auto denum = ncr(total,totaltake);
    return num/denum;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i=0;i<mxDP;++i) for(int j=0;j<6;++j) {
        if(i<j) continue;
        if(i==j or j==0) dp[i][j]=1;
        else dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
    }
    int n; cin >> n;
    vector<D> probs(n);
    vi sz(n);
    double ans=0;
    for(int i=0;i<n;++i) {
        int a; cin >> a;
        probs[i][a]=1.;
        sz[i]=a;
        if(a==0) ans++;
    }
    int q; cin >> q;
    while(q--) {
        int u,v,k; cin >> u >> v >> k;
        --u,--v;
        
        // calculate new distribution for u
        auto& d = probs[u];
        ans-=d[0];
        D nw = {};
        for(int i=0;i<=100;++i) {
            if(d[i]==0) continue;
            for(int take=0;take<=min(i,k);++take) {
                nw[i-take] += d[i]*calc(sz[u],i,take,k);
            }
        }
        d= move(nw);
        ans+=d[0];
        sz[v]+=k;
        sz[u]-=k;
        cout << setprecision(15) << ans << '\n';
    }
}