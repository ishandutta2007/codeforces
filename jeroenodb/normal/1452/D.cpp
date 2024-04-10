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
const long long MOD = 998244353;
class mint {
public:
    int d;
    mint () {d=0;}
    mint (long long _d) : d(_d%MOD){};
    mint operator*(const mint& o) const {
        return ((ll)d*o.d)%MOD;
    }
    mint operator+(const mint& o) const {
        long long tmp = d+o.d;
        if(tmp>=MOD) tmp-=MOD;
        return tmp;
    }
    mint operator-(const mint& o) const {
        long long tmp = d-o.d;
        if(tmp<0) tmp+=MOD;
        return tmp;
    }
    mint operator^(long long b) const {
        mint tmp = 1;
        mint power = *this;
        while(b) {
            if(b&1) {
                tmp = tmp*power;
            }
            power = power*power;
            b/=2;
        }
        return tmp;
    }
};
const mint halve = ((mint)2)^(MOD-2);
mint& operator+=(mint& a, const mint& o) {
    a.d+=o.d;
    if(a.d>=MOD) a.d-=MOD;
    return a;
}
int main() {
    int n; cin >> n;
    vector<mint> dp(n+1),pref(n+1);
    dp[0] = 1;
    pref[0] = 1;
    for(int i=1;i<=n;++i) {
        dp[i] = 0;
        // for(int j=0;j<=(i-1)/2;++j) {
        //     dp[i]+=dp[i-2*j-1];
        // }
        dp[i]+=pref[i-1];
        pref[i]=(i>1?pref[i-2]:0)+dp[i];
    }
    // debug(dp[n].d);
    // debug(((mint)(2)^n).d);
    cout << (dp[n]*(halve^n)).d << endl;
}