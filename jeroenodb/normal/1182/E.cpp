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
template<long long MOD=(ll)1e9+7>class mint {
public:
    int d=0;
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
    friend istream& operator>>(istream& c, mint& a) {
        return c >> a.d;
    }
};
#define rep(i,n) for(int i=0;i<n;++i)
template<typename T, int N=3> struct matrix {
    T mat[N][N] = {};
    friend matrix operator*(const matrix& a, const matrix& b) {
        matrix res;
        rep(i,N) rep(j,N) rep(k,N) {
            res.mat[i][k]+=a.mat[i][j]*b.mat[j][k];
        }
        return res;
    }
    static matrix eye() {
        matrix res;
        for(int i=0;i<N;++i) res.mat[i][i]=1;
        return res;
    }
    friend matrix pow(matrix& a, ll pwr) {
        matrix res = eye();
        while(pwr) {
            if(pwr&1) res=res*a;
            a=a*a;
            pwr/=2;
        }
        return res;
    }
};
mint<MD> f[4],c;
mint<MD> brute(ll n) {
    if(n<=3) return f[n];
    return (c^(2*n-6))*brute(n-1)*brute(n-2)*brute(n-3);
}

int main() {
    ll n; cin >> n >> f[1] >> f[2] >> f[3] >> c;
    matrix<mint<MD-1>,3> fcounts = {{{0,0,1},{1,0,1},{0,1,1}}};
    fcounts = pow(fcounts,n-3);
    mint<MD> res=1;
    for(int i=1;i<=3;++i) res = res*(f[i]^fcounts.mat[i-1][2].d);
    matrix<mint<MD-1>,6> ccounts = {{{1,1,0,0,2},{0,1,0,0,2},{0,0,0,0,1},{0,0,1,0,1},{0,0,0,1,1}}};
    ccounts = pow(ccounts,n-3);
    mint<MD-1> factorsc = ccounts.mat[0][4];
    res = res * (c ^ factorsc.d);
    cout << res.d << '\n';
}