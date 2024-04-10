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
typedef complex<int> pt;
#define X real()
#define Y imag()
auto cross(pt u, pt v) {return (ll)u.X*v.Y-(ll)u.Y*v.X;}
auto sgn(ll a) {return a==0?0:(a>0?1:-1);}
auto ccw(pt p1, pt p2, pt p3) {auto u = p2-p1, v = p3-p1;return cross(u,v);}
auto in(pt p1, pt p2) {return (ll)p1.X*p2.X+(ll)p1.Y*p2.Y;}
auto norm(pt p) {return (ll)p.X*p.X+(ll)p.Y*p.Y;}
bool comp(const pt& a, const pt& b) { return a.X<b.X or (a.X==b.X and a.Y < b.Y);}
void read(pt& p) {
    int a,b; cin >> a >> b;
    p = {a,b};
}
template<typename T> struct fenwick {
    int n;
    vector<T> fen;
    fenwick(){}
    fenwick(int nn) {
        fen.resize(nn+1);
        n = nn;
    }
    auto sum(int i) {
        T ans = 0;
        while(i) {
            ans+=fen[i];
            i&=i-1;
        }
        return ans;
    }
    auto query(int l, int r) {
        return sum(r+1)-sum(l);
    }
    void update(int i, T val) {
        ++i;
        while(i<=n) {
            fen[i]+=val;
            i+= i&(-i);
        }
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    vi startofpol;
    vector<pi> vs;
    for(int j=0;j<n;++j) {
        int k; cin >> k;
        vector<pt> pts(k);
        for(auto& i : pts) read(i);
        auto prev = pts.back();
        startofpol.push_back(vs.size());
        for(auto i : pts) {
            auto v = i-prev;
            int g = abs(gcd(v.X,v.Y));
            v/=g;
            pi vp = {v.X,v.Y};
            vs.push_back(vp);
            prev=i;
        }
    }
    startofpol.push_back(vs.size());
    int q; cin >> q;
    n = vs.size();
    vi head(n,-1);
    vi nxt(q,-1);
    vi l(q);
    for(int i=0;i<q;++i) {
        int r; cin >> l[i] >> r;
        l[i] = startofpol[l[i]-1], r = startofpol[r]-1;
        nxt[i]=head[r];
        head[r]=i;
    }
    // sweepline
    map<pi,int> last;
    fenwick<int> fen(n);
    vi ans(q);
    for(int i=0;i<n;++i) {
        auto v = vs[i];
        if(last.count(v)) {
            fen.update(last[v],-1);
        }
        fen.update(i,1);
        last[v]=i;
        for(int j=head[i];j!=-1;j=nxt[j]) {
            ans[j] = fen.query(l[j],i);
        }
    }
    for(auto i : ans) {
        cout << i << '\n';
    }
    
}