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
const int mxN = 500+1, oo = 1e9;
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
};
mint& operator+=(mint& a, const mint& o) {
    a.d+=o.d;
    if(a.d>=MOD) a.d-=MOD;
    return a;
}
mint dp[mxN][mxN];
int c[mxN];
mint solve(int i, int j) {
    // find minimum
    if(i>j) return 1;
    if(dp[i][j].d!=-1) return dp[i][j];
    int mn = i;
    for(int k=i;k<=j;++k) mn = c[mn]<c[k]?mn:k;
    // solve 

    mint left=0,right=0;
    for(int a=i;a<=mn;++a) left+=solve(i,a-1)*solve(a,mn-1);
    for(int b=mn;b<=j;++b) right+=solve(mn+1,b)*solve(b+1,j);
    return dp[i][j]=left*right;
}
int main() {
    for(int i=0;i<mxN;++i) {
        for(int j=0;j<mxN;++j) dp[i][j].d=-1;
    }
    int n,m; cin >> n >> m;
    assert(n==m);
    for(int i=0;i<n;++i) cin >> c[i];
    cout << solve(0,n-1).d << '\n';
}