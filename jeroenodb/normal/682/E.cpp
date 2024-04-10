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
auto ccw(pt p1, pt p2, pt p3) {auto u = p2-p1, v = p3-p2;return cross(u,v);}
auto in(pt p1, pt p2) {return (ll)p1.X*p2.X+(ll)p1.Y*p2.Y;}
auto norm(pt p) {return (ll)p.X*p.X+(ll)p.Y*p.Y;}
bool comp(const pt& a, const pt& b) { return a.X<b.X or (a.X==b.X and a.Y < b.Y);}
void read(pt& p) {
    int a,b; cin >> a >> b;
    p = {a,b};
}
auto convexhull(vector<pt>& pts) {
    sort(all(pts),[](pt& a, pt& b) {return a.X < b.X or (a.X==b.X and a.Y<b.Y);});
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
void print(pt p) {
    cout << p.X << ' ' << p.Y << '\n';
}
int main() {
    int n; cin >> n;
    ll s; cin >> s;
    vector<pt> pts(n);
    for(auto& i : pts) read(i);
    pts = convexhull(pts);
    n=pts.size();
    reverse(all(pts));
    for(int i=0;i<n;++i) pts.push_back(pts[i]);
    struct best {
        ll s=-oo;
        array<pt,3> p = {};
        best(){}
        best(pt a, pt b, pt c) {
            s= ccw(a,b,c);
            p = {a,b,c};
        }
        bool operator<(const best& o) const {
            return s<o.s;
        }
    };
    best b;

    for(int i=0;i<n;++i) {
        for(int j=i+1,k=i;j+1<i+n;++j) {
            if(k==j) ++k;
            while(k+1<i+n) {
                if(ccw(pts[i],pts[j],pts[k+1])>=ccw(pts[i],pts[j],pts[k])) {
                    ++k;
                } else break;
            }

            b = max(b, best(pts[i],pts[j],pts[k]));
        }
    }
    auto a = b.p[0]+b.p[1] - b.p[2];
    auto bb = b.p[1]+b.p[2]-b.p[0];
    auto c = b.p[2]+b.p[0]-b.p[1];
    print(a);
    print(bb);
    print(c);
}