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
const int N = 251, oo = 1e9;
int dp[2][N][N] = {};
int main() {
    // 1111|111|11|1111|1111
    // -> decreasing
    int n,m; cin >> n >> m;
    vi a(n); for(auto& i : a) cin >> i;
    // prefix sums?
    partial_sum(all(a),a.begin());
    auto old = dp[0], nw = dp[1];
    fill_n(&(old[0][0]),N*N,oo);
    old[0][m]=0;
    for(int r=0;r<n-1;++r) {
        fill_n(&nw[0][0],N*N,oo);
        for(int j=0;j<=m;++j)
            for(int i=m-1;i>=0;--i)
                old[j][i] = min(old[j][i],old[j][i+1]);
        for(int sm=0;sm<=m;++sm) {
            for(int cur=0;cur<=sm;++cur) {
                nw[sm][cur] = min(oo,old[sm-cur][cur]+abs(a[r]-sm));
            }
        }
        swap(old,nw);
    }
    
    int ans=oo;
    for(int before=0;before<=m;++before) {
        for(int sm=m-before;sm<=m;++sm) {
            ans = min(ans,old[before][sm]);
        }
    }
    cout << ans << '\n';

}