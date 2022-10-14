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
const int mxN = 3e5, oo = 1e9;
const long long MD = 1e9+7;
template<long long MOD=MD> struct mdint {
    int d=0;
    mdint () {}
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
const int M = 1.3e5;
struct distribution {
    mint dp[2][mxN];
    mint* cur=NULL;
    distribution(int k, int t) {
        // calculate (x^(2k+1) -1) / (x-1)
        fill_n(dp[0],mxN,0);
        fill(dp[0]+mxN/2, dp[1]+mxN,1);
        for(int rep=1;rep<=t;++rep) {
            cur = dp[rep%2] + mxN/2;
            fill_n(dp[rep%2],mxN,0);
            auto old = dp[(rep-1)%2]+mxN/2;
            for(int i=-k*rep;i<=k*rep;++i) {
                cur[i] += old[i+k]-old[i-k-1];
                cur[i]+=cur[i-1];
            }
            fill(cur+rep*k,cur+M+400,cur[rep*k]);
        }
        
    }
};
distribution* dist;

int main() {
    int a,b,k,t; cin >> a >> b >> k >> t;
    dist = new distribution(k,t);
    auto memo = dist->cur-a, lexa = dist->cur-b;
    mint res=0;
    for(int i=-M;i<=M;++i) {
        res+=(memo[i]-memo[i-1])*lexa[i-1];
    }
    cout << res << '\n';
}