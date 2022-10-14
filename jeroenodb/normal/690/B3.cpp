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
const int mxN = 2e5+1, oo = 1e9;
typedef complex<int> pt;
#define X real()
#define Y imag()
const pt dir4[] = {{1,0},{0,1},{-1,0},{0,-1}};
const pt dir8[] = {{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};
const pt hdir[] = {{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};
int n;
bool inside(pt p) {
    return 0<=p.X and p.X<n and 0<=p.Y and p.Y<n;
}
void read(pt& p) {
    int a,b; cin >> a >> b;
    p = {a,b};
}
auto cross(pt u, pt v) {return (ll)u.X*v.Y-(ll)u.Y*v.X;}
auto sgn(ll a) {return a==0?0:(a>0?1:-1);}
auto ccw(pt p1, pt p2, pt p3) {auto u = p2-p1, v = p3-p1;return cross(u,v);}
auto in(pt p1, pt p2) {return (ll)p1.X*p2.X+(ll)p1.Y*p2.Y;}
auto norm(pt p) {return (ll)p.X*p.X+(ll)p.Y*p.Y;}
bool comp(const pt& a, const pt& b) { return a.X<b.X or (a.X==b.X and a.Y < b.Y);}
auto convexhull(vector<pt>& pts) {
    sort(all(pts),comp);
    vector<pt> hull = {pts[0]};
    // GD_POINT(pts[0].X,pts[0].Y, "bold red");
    int n = pts.size();
    for(int phase = 0;phase <2;++phase) {
        // GD_LAYER();
        int last = hull.size();
        for(int i=1;i<n;++i) {
            auto& p = pts[i];
            // GD_POINT(p.X,p.Y, "bold red");
            while(hull.size()>=2 and hull.size()!=last and ccw(hull[hull.size()-2], hull.back(),p) >= 0) {
                // GD_POINT(hull.back().X,hull.back().Y, "bold blue");
                // GD_LAYER();
                auto& b = hull[hull.size()-2];
                // GD_SEGMENT(b.X, b.Y, hull.back().X, hull.back().Y);
                // GD_SEGMENT(hull.back().X, hull.back().Y, p.X,p.Y);
                hull.pop_back();
            }
            hull.push_back(p);
        }
        if(phase==0) reverse(all(pts));
    }
    assert(hull.front() == hull.back());
    hull.pop_back();
    return hull;
}
// vi rows[mxN];
// bitset<mxN> vis;
void solve() {
    int m;
    cin >> n >> m;
    if(n==0) 
        exit(0);
    vector<pt> pts(m);

    for(auto& i : pts) read(i);
    vector<pt> cand;
    sort(all(pts),comp);
    for(auto at : pts) {
        auto zero = [&](const pt& p) {
            auto it = lower_bound(all(pts),p,comp);
            if(it==pts.end()) return true;
            if(*it==p) return false;
            if(it->X!=p.X) return true;
            if(it==pts.begin()) return true;
            --it;
            return it->X!=p.X;
        };
        for(auto d : dir4) {
            auto to1 = d+at;
            auto to2 = at+d*pt{0,1};
            if(zero(to1) and zero(to2)) {
                // good
                cand.push_back((2*at+pt{-1,-1}-d*pt{1,1})/2);
            }
        }
    }
    auto h = convexhull(cand);
    cout << h.size() << '\n';
    for(auto& i : h) {
        cout << i.X << ' ' << i.Y << '\n';
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(true) solve();
}