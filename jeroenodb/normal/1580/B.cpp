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
long long MOD = 1e9+7;
struct mdint {
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
using  mint = mdint;
const int N=101;
mint dp[N][N][N],ncr[N][N], fact[N];
int n,m,k;
void solve(int s, int len, int good) {
    auto& c = dp[s][len][good];
    if(len==0) {
        c = good==0;
        return;
    }
    if(s==0) {
        if(good==0) c = fact[len];
        return;
    }
    if(s==1) good--;
    if(good<0 or good>=len) return;
    for(int l=0;l<len;++l) {
        int r = len-1-l;
        mint cur=0;
        int gr=min(good,r);
        for(int gl=good-gr;gl<=l and gr>=0;++gl,--gr) {
            cur+=dp[s-1][l][gl]*dp[s-1][r][gr];
        }
        c+=cur*ncr[len-1][l];
    }
}
int main() {
    cin >> n >> m >> k >> MOD;
    #define rep(i,n) for(int i=0;i<=n;++i)
    fact[0]=1;
    rep(i,n) rep(j,n) {
        if(i) fact[i]=fact[i-1]*i;
        if(i>=j) {
            if(j==0 or j==i) ncr[i][j]=1;
            else ncr[i][j]=ncr[i-1][j]+ncr[i-1][j-1];
        }
    }
    rep(i,m) rep(j,n) if(m-i<= (n-j)) rep(o,min(k,j))  {
            solve(i,j,o);
    }
    cout << dp[m][n][k];
}