#include "bits/stdc++.h"
using namespace std;
#define all(x) begin(x),end(x)
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { string sep; for (const T &x : v) os << sep << x, sep = " "; return os; }
#define debug(a) cerr << "(" << #a << ": " << a << ")\n";
typedef __int128_t ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
const int mxN = 1e5+1, oo = 1e9;

typedef complex<long long> pt;
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
long long read() {
    long long x; cin >> x;
    return x;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // need a stack
    long long lazy=0, lazy2 = 0,sz= read();
    vector<pt> pts = {{0,0}};
    int m; cin >> m;
    auto real = [&](pt p) {
        return pt{p.X,lazy+p.Y + p.X * lazy2};
    };
    while(m--) {
        int t; cin >> t;
        auto k = read();
        if(t==1) {
            sz+=k;
            pts = {{0,0}};
            lazy=0,lazy2=0;
        } else if(t==2) {
            // add to convex hull
            pt p = {sz,-lazy-lazy2*sz};
            pts.push_back(p);
            sz+=k;
        } else {
            auto s = read();
            lazy+=k;
            lazy2+=s;
        }
        while(pts.size()>1 and real(pts.back()).Y>=real(pts[pts.size()-2]).Y)
            pts.pop_back();
        while(pts.size()>2 and ccw(real(pts.end()[-3]),real(pts.end()[-2]),real(pts.back()))<=0) {
            pts.erase(pts.end()-2);
        }
        cout << pts.back().X+1 << ' ' << real(pts.back()).Y << '\n';
    }

}