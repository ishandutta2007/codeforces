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
const int mxN = 400, oo = 1e9;
const long long MD = 998244353;
template<long long MOD=MD> struct mdint {
    int d=0;
    mdint () {}
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
const int B = mxN/2 + 10;
mint dp[2][B+1][B+1][3][3];
mint suf[B+2][B+2];
#define rep(i,n) for(int i=0;i<n;++i)
int main() {
    // need to make 3 different DP's
    int n; cin >> n;
    const int C = (n+10)/2;
    int cnt[26] = {};
    for(auto& i : cnt) cin >> i,i=min(i,C);
    rep(i,3) rep(j,3) dp[0][(i==1)+(j==1)][(i==2)+(j==2)][i][j]+=(i==0?24:1)*(j==0?24:1);
    for(int len=3;len<=n;++len) {
        auto nw = dp[len&1];
        auto old = dp[(len^1)&1];
        rep(i,C) rep(j,C) rep(k,3) rep(o,3) 
            nw[i][j][k][o]=0;
        rep(i,C) rep(j,C) rep(x,3) rep(y,3) if(old[i][j][x][y].d) rep(z,3) {
            if(x==z) {
                if(z==0) {
                    nw[i][j][y][z]+=old[i][j][x][y]*23;
                }
            } else nw[i + (z==1)][j + (z==2)][y][z]+=old[i][j][x][y] * (z==0?24:1);
        }
    }
    auto res = dp[n&1];
    mint ans=26*26;
    rep(i,n-2) ans *=25;
    
    for(int i=C;i>=0;--i) for(int j=C;j>=0;--j) {
        suf[i][j]+=suf[i+1][j]+suf[i][j+1]-suf[i+1][j+1];
        rep(x,3) rep(y,3) suf[i][j]+=res[i][j][x][y];
    }
    for(int i=0;i<26;++i) {
        ans-=suf[cnt[i]+1][0];
        for(int j=i+1;j<26;++j) {
            ans+=suf[cnt[i]+1][cnt[j]+1];
        }
    }
    cout << ans << '\n';
    
}