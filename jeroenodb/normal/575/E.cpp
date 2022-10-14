#include "bits/stdc++.h"
#ifdef LOCAL
#include "geodeb.h"
#endif
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
const pt dir4[] = {{1,0},{0,1},{-1,0},{0,-1}};
const pt dir8[] = {{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};
const pt hdir[] = {{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};
const int N = 1e5;
bool inside(pt p) {
    return 0<=p.X and p.X<N and 0<=p.Y and p.Y<N;
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
    pts=hull;
}
long double circumcircle(pt a, pt b, pt c) {
    auto num = sqrt((long double)norm(a-b)*norm(b-c)*norm(c-a));
    auto denom = 2*abs(ccw(a,b,c));
    return num/denom;
}
auto print(pt p) {
    cout << p.X <<  ' ' << p.Y << '\n' ;
    #ifdef LOCAL
    GD_POINT(p.X,p.Y,"red bold");
    #endif
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<pt> cands;
    int n; cin >> n;
    auto moveinside = [&](pt p) {
        return pt{clamp(p.X,0,N),clamp(p.Y,0,N)};
    };
    auto updatecand = [&](pt p) {
        if(inside(p)) {
            cands.push_back(p);
            return;
        }
        if(p.X<0) {
            cands.push_back(moveinside({0,p.Y-p.X}));
            cands.push_back(moveinside({0,p.Y+p.X}));
        } else if(p.X>N) {
            cands.push_back(moveinside({N,p.Y-(p.X-N)}));
            cands.push_back(moveinside({N,p.Y+(p.X-N)}));
        } else if(p.Y<0) {
            cands.push_back(moveinside({p.X+p.Y,0}));
            cands.push_back(moveinside({p.X-p.Y,0}));
        } else if(p.Y>N) {
            cands.push_back(moveinside({p.X+(p.Y-N),N}));
            cands.push_back(moveinside({p.X-(p.Y-N),N}));
        }
    };
    for(int i=0;i<n;++i) {
        pt p;read(p);
        int v; cin >> v;
        for(auto j : dir4) {
            updatecand(p+j*v);
        }
    }
    // pick leftmost and rightmost candidates?
    convexhull(cands);
    #ifdef LOCAL
    GD_INIT("camera.html");
    for(auto i : cands) GD_POINT(i.X,i.Y);
    # endif
    // now just find triple with largest circumcircle
    n = cands.size();
    struct best {
        long double rad=-1;
        pt a, b,c;
        best() {}
        best(pt d,pt e,pt f) {
            a=d,b=e,c=f;
            rad = circumcircle(a,b,c);
        }
        bool operator<(const best& o) const {
            return rad<o.rad;
        }
    } b;
    for(int i=0;i<n;++i) {
        b = max(b,best(cands[i],cands[(i+1)%n], cands[(i+2)%n]));
    }
    print(b.a),print(b.b),print(b.c);
    
}