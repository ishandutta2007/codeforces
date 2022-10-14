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
const int mxT = 2501, mxN = 27;
typedef array<char,3> state;
map<state,mint> dp[mxT];
mint combi[mxN][mxN][mxN][3], fact[mxN*2];

mint solve(const state& st, int i) {
    auto& c = combi[st[0]][st[1]][st[2]][i];
    if(c.d!=-1) return c;
    if(!st[i]) return c=0;
    c=0;
    state nw=st;    nw[i]--;
    for(int j=0;j<3;++j) if(j!=i) 
        c+=solve(nw,j);
    return c;
}
int main() {
    int n,T; cin >> n >> T;
    int nh=(n+1)/2;
    dp[0][state{0,0,0}]=1;
    for(int i=0;i<n;++i) {
        int t,g; cin >> t >> g,--g;
        for(int j=T-t;j>=0;--j) {
            for(auto [st, cnt] : dp[j]) {
                if(st[g]<nh) {
                    auto nw = st;
                    nw[g]++;
                    dp[j+t][nw]+=cnt;
                }
            }
        }
    }
    #define rep(i,n) for(int i=0;i<=n;++i)
    rep(i,nh) rep(j,nh) rep(k,nh) rep(last,3) combi[i][j][k][last].d=-1;
    rep(i,2) combi[i==0][i==1][i==2][i]=1;
    fact[0]=1;
    rep(i,nh) fact[i+1]=fact[i]*(i+1);
    mint ans=0;
    for(auto& [st, cnt] : dp[T]) {
        mint res=0;
        for(int i=0;i<3;++i) 
            res+=solve(st,i);
        res *= cnt;
        for(int i=0;i<3;++i) res*=fact[st[i]];
        ans+=res;
    }
    cout << ans << '\n';
}