#include "bits/stdc++.h"
using namespace std;
// #define all(x) begin(x),end(x)
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { string sep; for (const T &x : v) os << sep << x, sep = " "; return os; }
#define debug(a) cerr << "(" << #a << ": " << a << ")\n";
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
const int mxK = 61, oo = 1e9;
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
const mint mat[3][3] = {{0,2,2},{2,0,2},{2,2,0}};
const string colors[] = {"white", "yellow", "green", "blue", "red", "orange"};
int getColID(string s) {
    return find(colors,colors+6,s)-colors;
}
typedef array<mint,3> DP;
DP dp[mxK];
#define rep(i,n) for(int i=0;i<n;++i)
void precomp() {
    dp[0] = {2,2,2};
    for(int i=1;i<mxK;++i) {

        rep(j,3) rep(j2,3) rep(k,3) {
            if(k!=j and k!=j2) {
                dp[i][k]+=dp[i-1][j]*dp[i-1][j2]*2;
            }
        }
    }
}
map<ll,short> adj;
DP dfs(ll at, int d) {
    auto& bs = adj[at];
    if(d==0) {
        if(bs==-1) return {2,2,2};
        else return {bs==0,bs==1,bs==2};
    }
    DP res = {};
    vector<DP> cs;
    for(auto to : {at*2,at*2+1}) {
        if(adj.count(to)) cs.push_back(dfs(to,d-1));
        else cs.push_back(dp[d-1]);
    }
    for(int i=0;i<3;++i) {
        if(bs==i) {
            rep(j,3) rep(j2,3) {
                if(i!=j and i!=j2) {
                    res[i]+=cs[0][j]*cs[1][j2];
                }
            }
        } else if(bs==-1) {
            rep(j,3) rep(j2,3) {
                if(i!=j and i!=j2) {
                    res[i]+=cs[0][j]*cs[1][j2]*2;
                }
            }
        }
    }
    return res;
}
int main() {
    precomp();
    int k,n; cin >> k >> n;
    for(int i=0;i<n;++i) {
        ll a; cin >> a;
        string s; cin >> s;
        adj[a] = getColID(s)/2;
        while(a>1) {
            a/=2;
            if(adj.count(a)) break;
            adj[a]=-1;
        }
    }
    if(!adj.count(1)) adj[1]=0;
    auto ans = dfs(1,k-1);
    cout << accumulate(ans.begin(),ans.end(),mint(0));



}