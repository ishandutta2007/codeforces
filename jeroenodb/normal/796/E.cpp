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
const int mxN = 2e3, oo = 1e9;
int dp[2][mxN][2][51];
void cmax(int& a, int b) {a=max(a,b);}
int main() {
    int n,p,k; cin >> n >> p >> k;
    n = (n+k-1)/k * k;
    p = min(2 * (n/k),p);
    vi pra(n+1), prb(n+1), prab(n+1);
    for(int rep=0;rep<2;++rep) {
        int r; cin >> r;
        while(r--) {
            int a; cin >> a;
            prb[a]=true;
        }
        swap(pra,prb);
    }
    for(int i=1;i<=n;++i) {
        prab[i] = pra[i] and prb[i];
        pra[i]+=pra[i-1],prb[i]+=prb[i-1],prab[i]+=prab[i-1];
    }
    #define rep(i,n) for(int i=0;i<n;++i)
    auto clean = [&](int top) {
        rep(i,n+1) rep(j,2) fill_n(dp[top][i][j], k+1,-oo);
    };
    clean(1);
    dp[1][0][0][0]=dp[1][0][1][0]=0;
    int ans = 0;
    for(int looks=0;looks<p;++looks) {
        clean(looks%2);
        auto nw  = dp[looks%2], old = dp[(looks+1)%2];
        rep(i,n-k+1) rep(fr,k+1) {
            auto cur = old[i][0][fr];
            if(cur!=-oo) {
                int place = pra[i+k]-pra[i] - (prab[i+fr]-prab[i]);
                // place a 0
                cmax(old[i+1][0][fr - (fr!=0)],cur);
                if(fr==1) cmax(old[i+1][1][fr - (fr!=0)],cur);
                cmax(nw[i+fr][1][k-fr],cur+place);
                if(k-fr==0) cmax(nw[i+fr][0][k-fr],cur+place);
                cmax(ans,cur+place);
            }
            cur = old[i][1][fr];
            if(cur!=-oo) {
                int place = prb[i+k]-prb[i] - (prab[i+fr]-prab[i]);
                // place a 1, or not
                cmax(old[i+1][1][fr - (fr!=0)],cur);
                if(fr==1) cmax(old[i+1][0][fr - (fr!=0)],cur);
                cmax(nw[i+fr][0][k-fr],cur+place);
                if(k-fr==0) cmax(nw[i+fr][1][k-fr],cur+place);
                cmax(ans,cur+place);
            }
        }
    }
    cout << ans << '\n';


}