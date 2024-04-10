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
struct DSU{
    vector<int> sz,parent;
    int components;
    DSU(int n) {
        sz.assign(n,1);
        components = n;
        parent.resize(n);
        iota(all(parent),0);
    }
    void link(int a, int b) {
        components--;
        if(sz[a]<sz[b]) {
            swap(a,b);
        }
        sz[a]+=sz[b];
        parent[b] = a;
    }
    bool unite(int a, int b) {
        int pa = find(a),pb = find(b);
        if(pa!=pb) link(pa,pb);
        return pa!=pb;
    }
    int find(int a) {
        if(a==parent[a]) return a;
        return parent[a] = find(parent[a]);
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,k; cin >> n >> m >> k;
    vvi a(n);
    DSU dsu(k);
    vi to(k,-1);
    vector<bool> root(k,1);
    for(auto& v : a) {
        int k; cin >> k;
        v.resize(k);
        for(auto& i : v) cin >> i,--i;
        for(int i=1;i<k;++i) dsu.unite(v[i],v[i-1]),to[v[i-1]]=v[i],root[v[i]]=false;
    }
    vector<vi> ids(k);
    {
        int id=0;
        for(auto& v : a) {
            ids[dsu.find(v[0])].push_back(id++);
        }
    }
    map<int,int> cnts;
    vector<bool> vis(k);
    auto processGroup = [&](int g) {
        auto& is = ids[g];
        // make a graph
        int at=-1;
        for(auto i : is) {
            auto& v = a[i];
            if(root[v[0]]) at=v[0];
        }
        int len=0;
        while(!vis[at] and at!=-1) {
            vis[at]=true;
            len++;
            at = to[at];
        }
        for(auto i : is) {
            auto& v = a[i];
            for(auto j : v) if(!vis[j]) return;
        }
        if(!len) len++;
        cnts[len]++;

    };
    for(int g=0;g<k;++g) {
        if(g==dsu.find(g))
            processGroup(g);
    }
    vector<pi> v(all(cnts));
    vector<mint> dp(m+1);
    dp[0]=1;
    for(int i=1;i<=m;++i) {
        for(auto [len,cnt] : v) if(len<=i) {
            dp[i]+=dp[i-len]*cnt;
        }
    }
    cout << dp[m] << '\n';

}