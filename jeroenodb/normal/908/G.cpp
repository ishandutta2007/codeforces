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
const int mxN = 700+1, oo = 1e9;
const long long MD = 1e9+7;
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
pair<mint,mint> dp[2][mxN][mxN];
bitset<mxN> vis[2][mxN];
string n;
int K;
mint pw[mxN];
pair<mint,mint> solve(bool b, int i, int j) {
    if(i==-1) {
        return {0,j==0};
    }
    if(vis[b][i][j]) return dp[b][i][j];
    vis[b][i][j]=true;
    auto& [ans,cnt] = dp[b][i][j];
    ans=0,cnt=0;
    int lim = b?n[i]:9;
    for(int dig=0;dig<=lim;++dig) {
        if(dig>=K and j) {
            auto [toans,tocnt] = solve(b and dig==lim,i-1,j-1);
            ans+=toans*(dig==K?1:10);
            if(dig==K) ans+=tocnt*pw[j-1]*K;
            cnt+=tocnt;
        }
        if(dig<K) {
            auto [toans,tocnt] = solve(b and dig==lim,i-1,j);
            ans+=toans;
            cnt+=tocnt;
        }
    }
    return {ans,cnt};
}
mint calcDig(int k) {
    K = k;
    int m = n.size();
    for(int i=0;i<m;++i) for(int j=0;j<2;++j) vis[j][i].reset();
    mint ans=0;
    for(int i=1;i<=m;++i) 
        ans+=solve(true,m-1,i).first;
    return ans;

}
int main() {
     cin >> n;
    for(auto& i : n) i-='0';
    pw[0]=1;
    for(int i=1;i<=n.size();++i) {
        pw[i] = pw[i-1]*10;
    }
    reverse(all(n));
    mint ans=0;
    for(int k=1;k<=9;++k) {
        ans+=calcDig(k);
    }
    cout << ans;
}