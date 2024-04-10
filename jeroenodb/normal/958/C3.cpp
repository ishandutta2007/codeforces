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
const int mxN = 5e5+10;
const int oo = 1e9,mxP=100;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k,p; cin >> n >> k >> p;
    if(k*p<n) {
        vi dp;
        int pref=0;
        for(int i=0;i<n;++i) {
            int a; cin >> a;
            pref+=a;
            pref%=p;
            int j = upper_bound(all(dp),pref)-dp.begin();
            if(j==(int)dp.size()) {
                dp.push_back(pref);
            } else {
                dp[j]=min(dp[j],pref);
            }
            if(i==n-1) {
                if(j+1>=k) {
                    cout << pref << '\n';
                } else cout << pref+p << '\n';
                exit(0);
            }
        }
    } else {
        // do DP
        vi dp(n+1,oo),pref(n+1,0);
        for(int i=1;i<=n;++i) {
            int a; cin >> a;
            pref[i] = (pref[i-1]+a)%p;
        }
        dp[0]=0;
        int best[mxP];
        for(int rep=0;rep<k;++rep) {
            fill(best,best+mxP,oo);
            for(int i=0;i<=n;++i) {
                int prv = dp[i],pr=pref[i];
                dp[i]=oo;
                for(int j=0;j<p;++j) {
                    int score = best[j]+pr-j;
                    if(j>pr) score+=p;
                    dp[i]=min(dp[i],score);
                }
                best[pr]=min(best[pr],prv);
            }
        }
        cout << dp[n] << '\n';


    }


}