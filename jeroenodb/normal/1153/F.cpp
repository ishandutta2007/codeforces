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
const int mxF=3e5;
const mint two = 2, halve = mint(1)/two;
mint fact[mxF], ifact[mxF], pw[mxF];
mint c(int a, int b) {
    if(b>a or a<0) return 0;
    return fact[a]*ifact[b]*ifact[a-b];
}
mint c2(int a, int b) {
    return fact[a]*ifact[b];
}
void precomp() {
    fact[0]=1;
    mint inv2 = mint(1)/mint(2);
    pw[0]=1;
    for(int i=1;i<mxF;++i) {
        fact[i]=fact[i-1]*i;
        pw[i] = pw[i-1]*inv2;
    }
    ifact[mxF-1] = mint(1)/fact[mxF-1];
    for(int i=mxF-2;i>=0;--i) {
        ifact[i]=ifact[i+1]*(i+1);
    }
}
int main() {
    precomp();
    int n,k,l; cin >> n >> k >> l;
    mint res=0;
    for(int i=1;i<2*n;++i) {
        int a= i, b = 2*n-i;
        int kk = k;
        mint cur=0;
        while(a>=kk and b>=kk) {
            if((a-kk)%2==0 and (b-kk)%2==0) {
                mint c = c2(a,a-kk)*c2(b,b-kk)*ifact[kk];
                int p = (a-kk)/2;
                c = c*fact[a-kk]*pw[p]*ifact[p];
                p= (b-kk)/2;
                c = c*fact[b-kk]*pw[p]*ifact[p];
                cur+=c;
            }
            
            kk++;
        }

        res+=cur;
    }
    mint total = fact[2*n]/(mint(2)^n)*ifact[n];
    res = res/total;
    res = res*l/(2*n+1);
    cout << res.d << '\n';


}