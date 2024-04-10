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

const int mxN = 2e5+1, oo = 1e9;
struct CD {
    struct edge{
        int to;
        bool w;
    };
    int n=-1,k=-1;
    vector<vector<edge>> adj;
    vi sz,a;
    vector<bool> vis ={};
    void read() {
        cin >> n >> k;
        a.resize(n);
        for(auto& i : a) cin >> i;
        adj.resize(n);
        sz.resize(n);
        vis.resize(n+1);
        for(int i=0;i<n-1;++i) {
            int u,v,w; cin >> u >> v >> w,--u,--v;
            adj[u].push_back({v,(bool)w});
            adj[v].push_back({u,(bool)w});
        }
    }
    void dfsz(int at) {
        vis[at]=true;
        sz[at]=1;
        for(auto e: adj[at]) if(!vis[e.to]) {
            dfsz(e.to);
            sz[at]+=sz[e.to];
        }
        vis[at]=false;
    }
    int centroid(int at) {
        int par=-1, subsz = sz[at];
        while(true) {
            bool good=true;
            for(auto it=adj[at].begin();it!=adj[at].end();++it) {
                auto e = *it;
                if(!vis[e.to] and e.to!=par and sz[e.to]*2>subsz) {
                    par=at;
                    at=e.to;
                    good=false;
                    break;
                }
            }
            if(good) break;
        }
        return at;
    }
    mint ans=0;

    vector<mint> pref[2],cnt[2], npref,ncnt;
    mint lazy[2] = {}, lazycnt[2] = {};
    mint get(int i, int w) {
        if(i<0) return 0;
        if(pref[w].empty()) return 0;
        return pref[w][min((int)pref[w].size()-1,i)]+lazy[w];
    }
    mint getcnt(int i, int w) {
        if(i<0) return 0;
        if(cnt[w].empty()) return 0;
        return lazycnt[w]+cnt[w][min((int)cnt[w].size()-1,i)];
    }
    bool rootW=false;
    mint sm=0, centroidA=0;
    int d=0;
    void add(int i, mint val, vector<mint>& v) {
        while((int)v.size()<=i) v.push_back(0);
        v[i]+=val;
    };
    void dfsdp(int at, bool myw) {
        vis[at]=true;
        sm+=a[at];
        ans+=get(k-d,rootW); // contribution from same-colored other subtrees
        ans+=get(k-1-d,!rootW); // contribution from different-colored other subtrees
        ans+=sm*(getcnt(k-d,rootW)+getcnt(k-1-d,!rootW)); // contribution from my paths
        if(d<=k) ans+=sm; // path to centroid
        add(d,sm-centroidA, npref);
        add(d,1,ncnt);
        for(auto e: adj[at]) if(!vis[e.to]) {
            if(e.w!=myw) d++;
            dfsdp(e.to,e.w);
            if(e.w!=myw) d--;
        }
        sm-=a[at];
        vis[at]=false;
    }
    void decomp(int at=0) {
        dfsz(at);
        int c = centroid(at);
        vis[c]=true;
        for(auto e: adj[c]) if(!vis[e.to]) {
            decomp(e.to);
        }
        // now smart stuff
        pref[0].clear(),pref[1].clear();
        cnt[0].clear(),cnt[1].clear();
        lazy[0]=lazy[1]=lazycnt[0]=lazycnt[1] = 0;
        sm = centroidA = a[c];
        ans+=a[c];
        for(auto& e : adj[c]) if(!vis[e.to]) {
            npref.clear(),ncnt.clear();
            rootW = e.w;
            dfsdp(e.to,e.w);
            for(int j=1;j<(int)npref.size();++j) {
                npref[j]+=npref[j-1];
                ncnt[j]+=ncnt[j-1];
            }
            lazy[e.w]+=npref.back();
            lazycnt[e.w]+=ncnt.back();
            for(int j=0;j<(int)npref.size();++j) {
                add(j,npref[j]-npref.back(), pref[e.w]);
                add(j,ncnt[j]-ncnt.back(),cnt[e.w]);
            }
        }
        vis[c]=false;
    }
};
CD cd;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cd.read();
    cd.decomp(0);
    cout << cd.ans << '\n';

}