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
typedef array<int,2> ar2;
const int mxN = 1e5+1, oo = 1e9+5;
const ll oo2 = 1e11;
template<typename T> void cmin(T& a, T b) {a=min(a,b);}
void solve() {
    int n,m; cin >> n >> m;
    vi a(n); for(auto& i : a) cin >> i;
    sort(all(a));
    vector<ar2> ivs(m);
    for(auto& [l,r] : ivs) cin >> l >> r;
    // remove all intervals with other intervals inside
    sort(all(ivs), [&](ar2 c, ar2 d) {return ar2{c[0],-c[1]} < ar2{d[0],-d[1]};});
    {
    vi st;
    for(int i=0;i<m;++i) {
        auto& [l,r] = ivs[i];
        while(!st.empty() and r<=ivs[st.back()][1]) {
            ivs[st.back()][1]=oo;
            st.pop_back();
        }
        st.push_back(i);
    }
    ivs.erase(partition(all(ivs), [&](ar2 c) {return c[1]!=oo;}),ivs.end());
    }
    // remove all intervals that contain a point
    m = ivs.size();
    sort(all(ivs), [&](ar2 c, ar2 d) {return c[1]<d[1];});
    {
        int furthest = -oo;
        for(int i=0,j=0;i<m;++i) {
            while(j<n and a[j]<=ivs[i][1]) {
                furthest = a[j++];
            }
            auto& [l,r] = ivs[i];
            if(l<=furthest) r=oo;
        }
        ivs.erase(stable_partition(all(ivs), [&](ar2 c) {return c[1]!=oo;}),ivs.end());
    }
    // structure of points and intervals left: . ---===__ . ====--- . 
    // dp[i] = minimum cost to reach all segments < i
    // transition from some i to segment right next to point: go left!
    // transition to point: go left and back. (or other way, if that's cheaper. that makes it difficult)
    // dp[i] = dp[j]- ivs[j+1][1]  + ivs[i][0]*2 - a[k]
    // dp[i] = dp[j] - 2*ivs[j+1][1]  + ivs[i][0] + a[k]
    // dp[i] = dp[j*] + ivs[i][0] - a[k]
    // do this at the end:
    // dp[j*]  = dp[j] - ivs[j+1][1] + a[k]
    m = ivs.size();
    if(m==0) {
        cout << "0\n";
        return;
    }
    vector<ll> dp(m+2, oo2),dp1(m+2, oo2),dp2(m+2,oo2); 
    dp[0]=0;
    int jstar = 0, preva=-1;
    int k=0;
    ivs.push_back({oo*2,oo*2});
    for(int i=1;i<=m+1;++i) {
        auto& [l,r] = ivs[i-1];
        while(k<n and a[k]<=l) {
            // now update the whole shebang
            int jnw = i-1;
            // update jstar
            if(k and jstar) cmin(dp[jstar], dp1[jstar-1] + preva);
            for(int o=jstar;o<jnw;++o) {
                if(o) cmin(dp1[o],dp1[o-1]), cmin(dp2[o],dp2[o-1]);
                if(o<m) cmin(dp1[o],dp[o]-ivs[o][1]), cmin(dp2[o],dp[o]-2LL*ivs[o][1]);
            }
            if(jstar!=jnw) preva = a[k];
            jstar = jnw;
            
            ++k;
        }
        if(k) {
            if(jstar) {
                cmin(dp[i], dp1[jstar-1]+l*2LL -preva);
                cmin(dp[i], dp2[jstar-1]+l+preva);
            }
            cmin(dp[i],dp[jstar]+l-a[k-1]);
        }
        // debug(dp[i]);
    }
    k=n;
    while(k>0 and a[k-1]>ivs[m-1][1]) k--;
    if(k!=n) cmin(dp[m],dp1[m-1] + a[k]);
    cout << dp[m] << '\n';

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
}