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
    mdint (long long _d) : d(_d%MOD){};
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
int main() {
    string x,y; cin >> x >> y;
    int n=x.size(),m=y.size();
    x='?'+x,y = '?'+y;
    vector<array<mint,4>> dp(m+1);
    mint ans=0;
    for(int i=0;i<=n;++i) {
        vector<array<mint,4>> ndp(m+1);
        for(int j=0;j<=m;++j) {
            if(i) {
                ndp[j][2]=1;

                if(x[i]!=x[i-1]) ndp[j][0]+=dp[j][0], ndp[j][2]+=dp[j][2];
                if(x[i]!=y[j]) ndp[j][0]+=dp[j][1]+dp[j][3];
            }
            if(j) {
                ndp[j][3]=1;
                if(y[j]!=y[j-1]) ndp[j][1]+=ndp[j-1][1], ndp[j][3]+=ndp[j-1][3];
                if(y[j]!=x[i]) ndp[j][1]+=ndp[j-1][0]+ndp[j-1][2];
                
            }
        }
        // debug(ndp);
        if(i!=0) for(int j=1;j<=m;++j) for(auto f : {0,1}) 
            ans+=ndp[j][f];
        swap(ndp,dp);
    }
    // for(int i=1;i<=n;++i) {
    //     ans-=1;
    //     for(int j=i+1;j<=n;++j) {
    //         if(x[j-1]==x[j]) break;
    //         ans-=1;
    //     }
    // }
    // for(int i=1;i<=m;++i) {
    //     ans-=1;
    //     for(int j=i+1;j<=m;++j) {
    //         if(y[j-1]==y[j]) break;
    //         ans-=1;
    //     }
    // }
    cout << ans;
}