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
const int mxN = 3e5+1, oo = 1e9;
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
vector<pair<int,ll>> adj[mxN];
ll pref[mxN];
bitset<mxN> vis,mark;
struct xorbasis {
    vector<ll> b;
    ll got=0;
    void reset() {
        got=0;
        b.clear();}
    int size() {
        return b.size();
    }
    void add(ll x) {
        for(auto& i: b) {
            if( (i&-i) & x ) x^=i;
        }
        if(x) 
            b.push_back(x);
    }
    void calc() {
        for(auto i : b) got|=i;
    }
} B;
int cnt;
const int LG = 62;
int numon[LG];
void dfs(int at, int from) {
    vis[at]=true;
    mark[at]=true;
    cnt++;
    for(int i=0;i<LG;++i) if((1LL<<i)&pref[at]) {
        numon[i]++;
    }
    for(auto [to,w] : adj[at]) if(to!=from) {
        if(mark[to]) {
            B.add(pref[to]^pref[at]^w);
        } else if(!vis[to]) {
            pref[to]=pref[at]^w;
            dfs(to,at);
        }
    }
    mark[at]=false;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m; cin >> n >> m;
    while(m--) {
        ll w;
        int u,v; cin >> u >> v >> w,--u,--v;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    mint ans=0;
    for(int at=0;at<n;++at) if(!vis[at]) {
        B.reset();
        fill_n(numon,LG,0);
        cnt=0;
        dfs(at,0);
        B.calc();
        mint whole=mint(2)^B.size();
        mint halve;
        if(B.size()==0) 
            halve=0;
        else halve = whole/2;
        for(int i=0;i<LG;++i) {
            if(B.got&(1LL<<i)) {
                ans+=mint((ll)cnt*(cnt-1)/2)*halve*(1LL<<i);
            } else {
                ans+=mint(ll(cnt-numon[i])*numon[i])*whole*(1LL<<i);
            }
        }
    }
    cout << ans << '\n';
}