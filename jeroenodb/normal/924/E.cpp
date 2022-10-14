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
void cmax(int& a, int b) {a=max(a,b);}
int main() {
    int n,l,r; cin >> n >> l >> r;
    vi a(n),b(n);
    for(auto& i : a) cin >> i;
    for(auto& i : b) cin >> i;
    vi ord(n); iota(all(ord),0);
    sort(all(ord),[&](int i, int j) { 
        return make_pair(b[i],-a[i])<make_pair(b[j],-a[j]);
    });
    vi dp(r+2,-oo),dp2(r+2,-oo);
    dp[0]=0;
    for(auto id : ord) {
        int w = a[id], price = b[id];
        for(int i=r;i>=0;--i) if(dp2[i]!=-oo) {
            cmax(dp2[min(i+w,r+1)],dp2[i]+ (price and i>=l));
        }
        if(price) {
            for(int i=r;i>=0;--i) {
                cmax(dp2[i],dp[i]);
            }
        }
        for(int i=r;i>=0;--i) if(dp[i]!=-oo) {
            cmax(dp[min(i+w,r+1)],dp[i]+ (price and i>=l));
        }


    }
    int ans = max(*max_element(all(dp)),*max_element(all(dp2)));
    for(int i=l;i<=r;++i) {
        ans = max(ans,dp2[i]+1);
    }
    cout << ans;
}