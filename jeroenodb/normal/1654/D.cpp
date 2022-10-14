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
const int mxN = 2e5+1, oo = 1e9;
const int store=1e6 + 1;
bitset<store> sieve={};
int factor[store] = {};
void makesieve() {
    for(int i = 2; i < store;++i) {
        if(!sieve[i]) {
            for(int j = i;j<store;j+=i) {
                if(!sieve[j]) {
                    factor[j] = i;
                    sieve[j] = true;
                }
            }
        }
    }
}
map<int,int> getFact(int k) {
    map<int,int> res;
    while(k!=1) {
        int f = factor[k];
        int tmp=0;
        while(k%f==0) k/=f,tmp++;
        res[f]=tmp;
    }
    return res;
}
map<int,int> f;
map<int,int> worst;
struct edge {
    int to,x,y;
    // a[to] = x/y*a[at]
    void add(int sgn=1) {
        auto tmp = getFact(x);
        for(auto& [p,cnt] : tmp) {
            f[p]+=cnt*sgn;
        }
        tmp = getFact(y);
        for(auto& [p,cnt] : tmp) {
            f[p]-=cnt*sgn;
            worst[p] = min(worst[p],f[p]);
        }
    }
};
vector<edge> adj[mxN];
mint sm=0;
void dfs(int at, int from,mint h=1) {
    sm+=h;
    for(auto e : adj[at]) if(e.to!=from) {
        e.add();
        dfs(e.to,at,h*e.x/e.y);
        e.add(-1);
    }
}
int main() {
    makesieve();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        // spanning tree
        for(int i=0;i<n;++i) adj[i].clear();
        for(int i=0;i<n-1;++i) {
            int a,b,x,y; cin >> a >> b >> x >> y;
            --a,--b;
            adj[a].push_back({b,y,x});
            adj[b].push_back({a,x,y});
        }
        worst.clear();
        f.clear();
        sm=0;
        dfs(0,-1);
        mint res=sm;
        for(auto& [p,cnt] : worst) {
            res*=mint(p)^(-cnt);
        }
        cout << res << '\n';

    }
}