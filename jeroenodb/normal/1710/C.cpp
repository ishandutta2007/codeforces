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
const long long MD = 998244353;
template<long long MOD=MD> struct mdint {
    int d=0;
    mdint () {d=0;}
    mdint (long long _d) : d(_d%MOD){
        if(d<0) d+=MOD;
    };
    friend mdint& operator+=(mdint& a, const mdint& o) {
        a.d+=o.d; if(a.d>=MOD) a.d-=MOD;
        return a;
    }
    friend mdint& operator-=(mdint& a, const mdint& o) {
        a.d-=o.d; if(a.d<0) a.d+=MOD;
        return a;
    }
    friend mdint& operator*=(mdint& a, const mdint& o) {
        return a = mdint((ll)a.d*o.d);
    }
    mdint operator*(const mdint& o) const {
        mdint res = *this;
        res*=o;
        return res;
    }
    mdint operator+(const mdint& o) const {
        mdint res = *this;
        res+=o;
        return res;
    }
    mdint operator-(const mdint& o) const {
        mdint res = *this;
        res-=o;
        return res;
    }
    mdint operator^(long long b) const {
        mdint tmp = 1;
        mdint power = *this;
        while(b) {
            if(b&1) {
                tmp = tmp*power;
            }
            power = power*power;
            b/=2;
        }
        return tmp;
    }
    friend mdint operator/=(mdint& a, const mdint& o) {
        a *= (o^(MOD-2));
        return a;
    }
    mdint operator/(const mdint& o) {
        mdint res = *this;
        res/=o;
        return res;
    }
    bool operator==(const mdint& o) { return d==o.d;}
    bool operator!=(const mdint& o) { return d!=o.d;}
    friend istream& operator>>(istream& c, mdint& a) {return c >> a.d;}
    friend ostream& operator<<(ostream& c, const mdint& a) {return c << a.d;}
};
using  mint = mdint<MD>;
#define rep(i,n) for(int i=0;i<n;++i)
int main() {
    string n; cin >> n;
    mint dp[2][2][2][2][8] = {};
    // a, b, c, mask
    auto old = dp[0], nw = dp[1];
    old[1][1][1][0]=1;
    for(auto ch : n) {
        ch-='0';
        rep(i,2) rep(j,2) rep(k,2) rep(o,8) nw[i][j][k][o]=0;
        rep(i,2) rep(j,2) rep(k,2) rep(o,8) {
            int lim[3] = {!i or ch, !j or ch, !k or ch};
            auto cur = old[i][j][k][o];
            rep(a,lim[0]+1) rep(b,lim[1]+1) rep(c,lim[2]+1) {
                int g[3] = {b==c and a!=c, a==c and a!=b, a==b and a!=c};
                nw[a==ch and i][b==ch and j][c==ch and k][o|g[0]|(g[1]<<1)|(g[2]<<2)]+=cur;
            }
        }
        swap(old,nw);
    }
    mint ans=0;
    rep(i,2) rep(j,2) rep(k,2) ans+=old[i][j][k][7];
    cout << ans << '\n';

}