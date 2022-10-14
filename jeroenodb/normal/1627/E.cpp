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
void cmax(ll& a, ll b) {a=max(a,b);}
void solve() {
    int n,m,k; cin >> n >> m >> k;
    vi x(n); for(auto& i : x) cin >> i;
    // coordinate compress?
    vvi coords(n);
    coords[0].push_back(0);
    coords[n-1].push_back(m-1);
    struct lad {
        pt s,e;
        int h;
        void mread() {
            read(s), read(e);
            s-=pt{1,1}, e-=pt{1,1};
            cin >> h;
        }
        void cc(vvi& c) {
            c[s.X].push_back(s.Y);
            c[e.X].push_back(e.Y);
        }
        bool operator<(const lad& o) {
            return comp(s,o.s);
        }
    };
    vector<lad> ls(k);
    for(auto& i : ls) i.mread(),i.cc(coords);
    vector<vector<ll>> dp; dp.reserve(n);
    for(auto& v : coords) {
        sort(all(v));
        v.erase(unique(all(v)),v.end());
        dp.push_back(vector<ll>(v.size(),-ll(oo)*oo));
    }
    auto get = [&](int i, int j) -> ll& {
        int id = lower_bound(all(coords[i]),j)-coords[i].begin();
        return dp[i][id];
    };
    dp[0][0]=0;
    sort(all(ls));
    auto it = ls.begin();
    for(int i=0;i<n;++i) {
        int o = dp[i].size();
        for(int j=1;j<o;++j) cmax(dp[i][j],dp[i][j-1]-x[i]*ll(coords[i][j]-coords[i][j-1]));
        for(int j=o-2;j>=0;--j) cmax(dp[i][j],dp[i][j+1]-x[i]*ll(coords[i][j+1]-coords[i][j]));

        while(it!=ls.end() and it->s.X==i) {
            auto& l = *it;
            auto from =  get(l.s.X,l.s.Y);
            if(from!=-ll(oo)*oo) {
                cmax(get(l.e.X,l.e.Y),from+l.h);
            }
            ++it;
        }
    }
    if(dp.back().back()==-ll(oo)*oo) {
        cout << "NO ESCAPE\n";
    } else cout << -dp.back().back() << '\n';


}
int main() {
    int t; cin >> t;
    while(t--) solve();
}