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
const long long MD = 1e9+7;
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
    int n; cin >> n;
    vi l(n); for(auto& i : l) cin >> i;
    vi r(n); for(auto& i : r) cin >> i;
    auto pSame = [&](int a, int b) {
        int lo=-oo,hi=oo; 
        mint prod=1;
        for(int i=a;i<=b;++i) {
            lo=max(lo,l[i]);
            hi=min(hi,r[i]);
            prod*=r[i]-l[i]+1;
        }
        if(hi<lo) return mint(0);
        return mint(hi-lo+1)/prod;
    };
    vector<mint> p(n-1);
    mint sm=0;
    for(int i=0;i<n-1;++i) {
        p[i] = pSame(i,i+1);
        sm+=p[i];
    }

    mint res=mint(n)*n - sm*2*n;
    for(int i=0;i<n-1;++i) {
        // calculate contribution of all i - j terms
        mint indep = sm;
        for(int j=max(0,i-1);j<min(n-1,i+2);++j) indep-=p[j];
        res+=indep*p[i];
        res+=p[i];
        if(i>0) {
            // chance that three are the same
            res+=pSame(i-1,i+1);
        }
        if(i<n-2) {
            res+=pSame(i,i+2);
        }
    }
    cout << res << '\n';

}