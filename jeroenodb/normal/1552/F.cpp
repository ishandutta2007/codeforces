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
    mint operator/(const mint& o) {
        return *this * (o^(MOD-2));
    }
    bool operator==(const mint& o) {
        return d==o.d;
    }
    friend mint& operator+=(mint& a, const mint& o) {
        a.d+=o.d;
        if(a.d>=MOD) a.d-=MOD;
        return a;
    }
};
int main() {
    int n; cin >> n;
    vi x(n), y(n), s(n);
    for(int i=0;i<n;++i) {
        cin >> x[i] >> y[i] >> s[i];
    }
    x.insert(x.begin(),0);
    y.insert(y.begin(),0);
    s.insert(s.begin(),0);
    vector<mint> dpon(n+1), dp(n+1);
    for(int i=1;i<=n;++i) {
        dpon[i] = dpon[i-1]+x[i]-x[i-1];
        int j = upper_bound(all(x),y[i])-x.begin()-1;
        mint extra = dpon[i-1]-dpon[j]+x[i]-x[i-1]-(y[i]-x[j]);
        dpon[i]+=extra;
        dp[i] = dp[i-1]+x[i]-x[i-1];
        if(s[i]) {
            // teleport back
            dp[i]+=extra;
        }
    }
    cout << (dp[n]+1).d << '\n';

}