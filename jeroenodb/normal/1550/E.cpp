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
const int mxN = 1e5+1, oo = 1e9;
string s;
vi same[17],nxt[17];
int dp[1<<17],n,k;
bool good(int f) {
    int ss= 1<<k;

    for(int j=0;j<k;++j) {
        auto& myn = nxt[j], &sm = same[j];
        for(int i=n-1;i>=0;--i) {

            if(sm[i]>=f) {
                myn[i]=i+f;
            } else myn[i]=myn[i+1];
        }
    }
    fill(dp,dp+ss,oo);
    dp[0]=0;
    for(int i=0;i<ss;++i) if(dp[i]!=oo) {
        for(int j=0;j<k;++j) if(!(1<<j&i)) {
            dp[i|(1<<j)] = min(dp[i|1<<j], nxt[j][dp[i]]);
        }
    }
    return dp[ss-1]<=n;
}
int main() {
    cin >> n >> k;
    cin >> s;
    s.push_back('#');
    for(int j=0;j<k;++j) same[j].assign(n+1,0),nxt[j].assign(n+1,oo);
    for(int j=0;j<k;++j) {
        auto goodc = [&](char c) {
            return c=='?' or c=='a'+j;
        };
        for(int i=n-1;i>=0;--i) {
            auto& sm = same[j];
            if(goodc(s[i])) {
                sm[i] = 1+(goodc(s[i+1])?sm[i+1]:0);
            }
        }
    }
    int lo=0,hi=n/k;

    while(lo<hi) {
        int mid = (lo+hi+1)/2;
        if(good(mid)) {
            lo=mid;
        } else hi=mid-1;
    }
    cout << lo << '\n';
}