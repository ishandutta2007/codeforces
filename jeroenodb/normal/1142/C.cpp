#include "bits/stdc++.h"
using namespace std;
#define all(x) begin(x),end(x)
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { string sep; for (const T &x : v) os << sep << x, sep = " "; return os; }
#define debug(a) cerr << "(" << #a << ": " << a << ")\n";
typedef __int128 ll;
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
auto convexhull(vector<pt>& pts) {
    sort(all(pts),comp);
    vector<pt> hull = {pts[0]};
    int n = pts.size();
    for(int i=1;i<n;++i) {
        auto& p = pts[i];
        while(hull.size()>=2 and ccw(hull[hull.size()-2], hull.back(),p) >= 0) {
            hull.pop_back();
        }
        hull.push_back(p);
    }
    return hull;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    vector<pt> pts(n); for(auto& i : pts) read(i), i = {i.X,i.Y-i.X*i.X};
    auto h = convexhull(pts);
    long long ans=0;
    n = h.size();
    for(int i=1;i<n;++i) {
        if(h[i].X!=h[i-1].X) {
            ans++;
        }
    }
    cout << ans << '\n';
}