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
const int C = 1e4+1, oo = 1e9;
double dp[101][C];
int main() {
    int n,x; cin >> n >> x;
    dp[0][0]=1;
    int total=0;
    vi c(n);
    for(auto& i : c) cin >> i,total+=i;
    for(auto w : c) {
        for(int k=n-1;k>=0;--k) {
            double factor = double(k+1)/(n-k);
            for(int j=0;j+w<=total;++j) {
                dp[k+1][j+w]+=dp[k][j]*factor;
            }
        }
    }
    double ans=0;
    for(int i=0;i<n;++i) {
        for(int j=0;j<=total;++j) if(dp[i][j]!=0) {
            ans+=dp[i][j]*min(double(total-j)/(n-i), (1 + double(n)/(n-i))*0.5*x);
        }
        // debug(cur);
    }
    cout << setprecision(15) << fixed << ans << '\n';
}