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
const int mxN = 1e1+1, oo = 1e9;
#else
const int mxN = 1.5e5+1, oo = 1e9;
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
template<typename T> struct fenwick {
    // range update, point query
    int n;
    vector<T> fen;
    fenwick(){}
    fenwick(int nn) {
        fen.resize(nn+1);
        n = nn;
    }
    auto query(int i) {
        T ans = 0;
        ++i;
        while(i) {
            ans+=fen[i];
            i&=i-1;
        }
        return ans;
    }
    void update(int l, int r, T val) {
        if(l>r) return;
        update(r+1,T(0)-val);
        update(max(0,l),val);
    }
    void update(int i, T val) {
        ++i;
        while(i<=n) {
            fen[i]+=val;
            i+= i&(-i);
        }
    }
};
vi adj[mxN];
int sz[mxN], in[mxN],out[mxN], cnt=1, bigc[mxN], par[mxN], chain[mxN];
void dfs(int at,int from=0) {
    if(from) adj[at].erase(find(all(adj[at]),from));
    in[at]=cnt++;
    sz[at]=1;
    for(int to : adj[at]) {
        dfs(to,at);
        par[to]=at;
        sz[at]+=sz[to];
        if(!bigc[at] or sz[to]>sz[bigc[at]]) bigc[at]=to;
    }
    out[at] = cnt-1;
}
void dfs2(int at) {
    if(!chain[at]) chain[at]=at;
    chain[bigc[at]]=chain[at];
    for(int to : adj[at]) {
        dfs2(to);
    }
}
mint lazy[mxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q; cin >> n >> q;
    for(int i=0;i<n-1;++i) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1); dfs2(1);
    fenwick<mint> fen(n+6);
    mint ivn = mint(1)/n;
    while(q--) {
        int t,v; cin >> t >> v;
        if(t==1) {
            mint d; cin >> d;
            d*=ivn;
            mint paradd = d*sz[v];
            fen.update(in[v],in[v],d*n);
            if(par[v]) fen.update(1,in[v]-1,paradd), fen.update(out[v]+1,n,paradd);
            if(bigc[v]) {
                int bg = bigc[v];
                fen.update(in[bg],out[bg],d*(n-sz[bg]));
            }
            lazy[v]+=d;
        } else {
            mint res = fen.query(in[v]);
            for(int f=chain[v];f!=1;f=chain[par[f]]) {
                // now add contribution from this
                res+=lazy[par[f]]*(n-sz[f]);
            }
            cout << res << '\n';
        }
    }
}