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
const int mxF = 2e6+2;
mint fact[mxF], ifact[mxF], pw3[mxF];
mint ncr(int a, int b) {
    if(b>a or a<0) return 0;
    return fact[a]*ifact[b]*ifact[a-b];
}
void precomp() {
    fact[0]=pw3[0]=1;
    for(int i=1;i<mxF;++i) {
        fact[i]=fact[i-1]*i;
        pw3[i]=pw3[i-1]*3;
    }
    ifact[mxF-1] = mint(1)/fact[mxF-1];
    for(int i=mxF-2;i>=0;--i) {
        ifact[i]=ifact[i+1]*(i+1);
    }
}
mint brute(int n) {
    mint res=0;
    for(int i=0;i<=n;++i) {
        for(int j=0;j<=n;++j) {
            if(i==0 and j==0 ) continue;
            mint cur;
            if(i==0 or j==0) {
                int total = i+j;
                cur=(mint(3)^(total + (ll)n*(n-total)));
            } else {
                ll left = (ll)(n-i)*(n-j);
                cur = (mint(3)^left)*3;
            }
            mint binom = ncr(n,i)*ncr(n,j);
            cur*=binom;
            if((i+j)%2==1) {
                res+=cur;
            } else res-=cur;
        }
    }
    return res;
}
int main() {
    precomp();
    int n; cin >> n;
    mint thr = 3;
    mint res=(thr^(ll(n)*n)) - ((pw3[n]-3)^n);
    for(int i=1;i<=n;++i) {
        mint cur = (pw3[i]-3)*(thr^(ll(n)*(n-i))); // different colors
        cur+=((pw3[n-i]-1)^n)*3;
        cur*=ncr(n,i);
        if(i%2==1) {
            res+=cur;
        } else res-=cur;
    }
    debug(res); 
    cout << res << '\n';
}