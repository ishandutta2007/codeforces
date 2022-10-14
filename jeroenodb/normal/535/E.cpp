#include "bits/stdc++.h"
using namespace std;
#define all(x) begin(x),end(x)
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { string sep; for (const T &x : v) os << sep << x, sep = " "; return os; }
#define debug(a) cerr << "(" << #a << ": " << a << ")\n";
typedef long double ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
const int mxN = 1e5+1, oo = 1e9;
typedef complex<ll> pt;
#define X real()
#define Y imag()
auto cross(pt u, pt v) {return (ll)u.X*v.Y-(ll)u.Y*v.X;}
auto sgn(ll a) {return a==0?0:(a>0?1:-1);}
auto ccw(pt p1, pt p2, pt p3) {auto u = p2-p1, v = p3-p2;return cross(u,v);}
auto in(pt p1, pt p2) {return (ll)p1.X*p2.X+(ll)p1.Y*p2.Y;}
auto norm(pt p) {return (ll)p.X*p.X+(ll)p.Y*p.Y;}
bool comp(const pt& a, const pt& b) { return a.X<b.X or (a.X==b.X and a.Y < b.Y);}
int main() {
    int n; cin >> n;
    // -1/r_i + =C/s_i > -1/r_j + -C/s_j
    // transform all points to -1/r_i and -1/s_i
    // Then point is good if on convex hull of 
    vector<pi> c(n);
    for(auto& [r,s] : c) cin >> r >> s;
    vi ord(n); iota(all(ord),0);
    sort(all(ord),[&](int i, int j) {return c[i]>c[j];});
    int mx = 0;
    vector<pt> h;
    vector<pi> h2;
    for(auto id : ord) {
        auto [r,s] = c[id];
        pt p = {-1.0/r,-1.0/s};
        if(s<=mx) continue;
        while(h.size()>1 and ccw(h[h.size()-2],h[h.size()-1], p)<-1e-17) {
            // debug(ccw(h[h.size()-2],h[h.size()-1], p));
            h.pop_back();
            h2.pop_back();
        }
        h.push_back(p);
        h2.push_back(c[id]);
        mx = max(mx,s);
    }
    sort(all(h2));
    for(int i=1;i<=n;++i) {
        if(binary_search(all(h2),c[i-1])) cout << i << ' ';
    }
    

}