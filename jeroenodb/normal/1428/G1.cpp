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
int main() {
    int k; cin >> k;
    vector<pair<int,ll>> items;
    auto construct = [&](int w, int num, ll f) {
        if(num==0) return;
        int pw=1;
        while(pw<num) {
            items.push_back({w*pw,f*pw});
            num-=pw;
            pw*=2;
        }
        items.push_back({w*num,f*num});
    };
    array<ll,6> f;
    for(auto& i : f) cin >> i;
    const int S = 999999;
    
    {
    int w = 1;
    
    for(int i=0;i<6;++i) {
        construct(w*3,min(3*(k-1),S/w),f[i]);
        w*=10;
    }
    }
    vector<ll> dp(S+1,-1e18);
    dp[0]=0;
    for(auto [w,c] : items) {
        for(int i=S-w;i>=0;--i) {
            dp[i+w] = max(dp[i]+c,dp[i+w]);
        }
    }
    int q; cin >> q;
    int pw=1;

    for(int j=0;j<6;++j) {
        ll mygain[10] = {};
        for(int i=3;i<10;i+=3) {
            mygain[i] = f[j]*(i/3);
        }
        for(int i=S;i>=pw;--i) {
            for(int dig=0;dig<10;++dig) {
                int w = pw*dig;
                if(i>=w) dp[i] = max(dp[i-w]+mygain[dig],dp[i]);
            }
        }
        pw*=10;
    }
    while(q--) {
        int n; cin >> n;
        cout << dp[n] << '\n';
    }
}