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
const int mxN = 1e6+10, oo = 1e9;
bitset<11*mxN> good;
const long long MOD = 1e9+7;
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
mint fact[mxN], ifact[mxN];

mint c(int a, int b) {
    return fact[a]*ifact[b]*ifact[a-b];
}
int main() {
    int a,b,n; cin >> a >> b >> n;
    good[0]=true;
    for(int i=0;i<=n;++i) {
        if(good[i]) {
            good[i*10+a]=true;
            good[i*10+b]=true;
        }
    }
    fact[0]=1;
    for(int i=1;i<=n;++i) {
        fact[i]=fact[i-1]*i;
    }
    ifact[n] = mint(1)/fact[n];
    for(int i=n-1;i>=0;--i) {
        ifact[i]=ifact[i+1]*(i+1);
    }
    int sm = a*n;
    mint ans = 0;
    for(int i=0;i<=n;++i) {
        if(good[sm]) {
            ans+=c(n,i);
        }
        sm+=b-a;
    }
    cout << ans.d << '\n';

}