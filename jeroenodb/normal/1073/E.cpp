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
const int M=1<<10, mxN = 1e5+1, oo = 1e9;
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
pair<ll,mint> dp[2][19][M];
int digs[19],k;
mint pw[20];
int countb(int i) {
    return bitset<10>(i).count();
}
pair<ll,mint> solve(bool big, int i, int msk) {
    if(i==-1) {
        return {countb(msk)<=k, 0};
    }
    auto& [mycnt,mydp] = dp[big][i][msk];
    if(mycnt!=-1) return {mycnt,mydp};
    mycnt=0;
    int lim = big?digs[i]:9;
    for(int dig=0;dig<=lim;++dig) {
        int toadd = (msk==0 and dig==0)?0:1<<dig;
        auto [tocnt,tod] = solve(big and dig==lim, i-1, msk|toadd);
        mydp+=mint(dig)*tocnt*pw[i] + tod;
        mycnt+=tocnt;
    }
    return {mycnt,mydp};
}
mint get(ll r) {
    int len=0;
    pw[0]=1;
    while(r) {
        for(int i=0;i<2;++i) {
            fill_n(dp[i][len],M,pair<ll,mint>{-1,mint(0)});
        }
        pw[len+1]=pw[len]*10;
        digs[len++] = r%10;
        r/=10;
    }
    auto [mcnt,res] = solve(true,len-1,0);
    return res;
}
int main() {
    ll l,r; cin >> l >> r >> k;
    auto ans = get(r) - get(l-1);
    cout << ans << '\n';
}