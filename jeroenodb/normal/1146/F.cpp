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
#ifdef DEBUG
const int mxN = 10+1, oo = 1e9;
#else
const int mxN = 2e5+1, oo = 1e9;
#endif
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
mint dead[mxN],alive[mxN], meh[mxN];
int sz[mxN];
vi adj[mxN];
void dfs(int at) {
    alive[at]=dead[at]=sz[at]=1;
    if(adj[at].empty()) {
        dead[at]=0;
        return;
    }
    vector<mint> pref;
    for(int to : adj[at]) {
        dfs(to);
        sz[at]+=sz[to];
        alive[at]*=(meh[to]+alive[to]*2+dead[to]);
        pref.push_back(dead[to]+alive[to]);
        dead[at]*=(dead[to]+alive[to]);
    }
    auto suf = pref;
    int k = pref.size();
    pref.insert(pref.begin(),1);
    for(int i=1;i<=k;++i) pref[i]*=pref[i-1];
    for(int i=k-2;i>=0;--i) suf[i]*=suf[i+1];
    suf.push_back(1);
    for(int i=0;i<k;++i) {
        auto cur = pref[i]*suf[i+1]*(meh[adj[at][i]]+alive[adj[at][i]]);
        alive[at]-=cur;
        meh[at]+=cur;
    }
    alive[at]-=pref.back();
}
int main() {
    int n; cin >> n;
    for(int i=1;i<n;++i) {
        int p; cin >> p,--p;
        adj[p].push_back(i);
    }
    dfs(0);
    cout << (dead[0]+alive[0]) << '\n';
}