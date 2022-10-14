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
const long long MD = 998244353;
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
typedef mint F;
F gaussianElim(vector<valarray<F>>& A) {
    int at= 0;
    int n = A.size();
    for(int i=n-1;i>=0;--i) {
        for(int j=at;j<A.size();++j) if(A[j][i]!=0) 
            swap(A[j],A[at]);
        if(A[at][i]==0) 
            continue;
        for(int j=0;j<n;++j) if(j!=at and A[j][i]!=0) {
            A[j]-=A[at]*(A[j][i]/A[at][i]);
        }
        ++at;
    }
    // probability van 0 weten;
    return A[n-1][n]/A[n-1][0];
}
vvi adj;
vi dp;
int dfs(int at) {
    if(dp[at]!=-1) return dp[at];
    dp[at]=0;
    vector<bool> mex;
    for(auto to : adj[at]) {
        auto res = dfs(to);
        while(mex.size()<=res) mex.push_back(0);
        mex[res]=1;
    }
    mex.push_back(0);
    int ans=0;
    while(mex[ans]) ++ans;
    return dp[at] = ans;
}
int main() {
    int n,m; cin >> n >> m;
    adj.resize(n);
    dp.assign(n,-1);
    for(int i=0;i<m;++i) {
        int u,v; cin >> u >> v;
        --u,--v;
        adj[u].push_back(v);
    }
    for(int i=0;i<n;++i) {
        dfs(i);
    }
    int mx=*max_element(all(dp));
    int ptwo=1;
    while(ptwo<=mx) ptwo*=2;
    vector<valarray<F>> A(ptwo,valarray<F>(ptwo+1));
    F prob = F(1)/(n+1);

    for(int i=0;i<ptwo;++i) {
        A[i][i]+=-1;
        for(auto j : dp) {
            A[i][i^j]+=prob;
        }
        if(i==0) A[i][ptwo]=mint(0)-prob;
    }
    // for(auto i : A) {
    //     for(auto j : i) cout << j << ' ';
    //     cout << '\n';
    // }
    cout << F(1)-gaussianElim(A) << '\n';
    // for(auto i : A) {
    //     for(auto j : i) cout << j << ' ';
    //     cout << '\n';
    // }
}