#include "bits/stdc++.h"
// #include "geodeb.h"
using namespace std;
#define all(x) begin(x),end(x)
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { string sep; for (const T &x : v) os << sep << x, sep = " "; return os; }
#define debug(a) cerr << "(" << #a << ": " << a << ")\n";
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
const int mxN = 1e5+1;
const ll oo = 1e18;
typedef complex<int> pt;
#define X real()
#define Y imag()
auto cross(pt u, pt v) {return (ll)u.X*v.Y-(ll)u.Y*v.X;}
auto sgn(ll a) {return a==0?0:(a>0?1:-1);}
auto ccw(pt p1, pt p2, pt p3) {auto u = p2-p1, v = p3-p2;return cross(u,v);}
auto in(pt p1, pt p2) {return (ll)p1.X*p2.X+(ll)p1.Y*p2.Y;}
auto norm(pt p) {return (ll)p.X*p.X+(ll)p.Y*p.Y;}
void read(pt& p) {
    int a,b; cin >> a >> b;
    p = {a,b};
}
int quadrant(pt p) {
    if(p.X==0 and p.Y==0) return -1;
    if(p.X>=0 and p.Y>0) return 0;
    if(p.X<0 and p.Y>=0) return 1;
    if(p.X<=0 and p.Y<0) return 2;
    return 3;
}
int inpoly(const vector<pt>& poly, pt p) {
    int n = poly.size();
    int winding = 0;
    int q = quadrant(poly[0]-p);
    for(int i=1;i<n;++i) {
        int nq = quadrant(poly[i]-p);
        if(nq==-1) return 0;
        if(nq==q) continue;
        if(nq%2!=q%2) {
            if((q+1)%4==nq) {
                winding++;
            } else {
                winding--;
            }
            q = nq;
            continue;
        }
        int tmp = sgn(ccw(poly[i],poly[i-1],p));
        if(tmp==0) return 0;
        winding-=2*tmp;
        q = nq;
    }
    assert(winding%4==0);
    return winding/4==0?-1:1;
}
long double distancepointlineseg(pt p, pt sg1, pt sg2) {
    auto v = p-sg1, u = sg2-sg1;
    auto inp = in(v, u);
    if(inp<=0) {
        // // GD_SEGMENT(p.X,p.Y,sg1.X,sg1.Y,"orange");
        return norm(v);
    } else if(inp>=norm(u)) {
        // // GD_SEGMENT(p.X,p.Y,sg2.X,sg2.Y,"orange");
        return norm(sg2-p);
    }
    // // GD_SEGMENT(p.X,p.Y,sg1.X,sg1.Y,"purple");
    auto inp2 = cross(v, u);
    return (long double)inp2*inp2/norm(u);
}
int main() {
    // GD_INIT("snowblower.html");
    int n; cin >> n;
    pt anchor; read(anchor);
    vector<pt> polygon(n);
    for(auto& p: polygon) {
        read(p);
        p-=anchor;
    }
    // GD_POLYGON("black:salmon",
        // for (int j = 0; j < n; ++j) {
        //     // GD_POLYPOINT((polygon[j].X),(polygon[j].Y));
        // }
    // );
    ll mx=0;
    for(auto& p: polygon) {
        mx = max(mx,norm(p));
    }
    long double mn = oo;
    polygon.push_back(polygon[0]);
    if(inpoly(polygon,{0,0})==-1) {
        for(int i=1;i<n+1;++i) {
            // GD_LAYER();
            mn = min(mn,distancepointlineseg({0,0}, polygon[i],polygon[i-1]));
            // GD_SEGMENT(polygon[i].X, polygon[i].Y, polygon[i-1].X, polygon[i-1].Y, "bold green");
            // GD_CIRCLE(0.0,0.0,sqrt(mn));
        }
    } else {
        mn = 0;
    }
    // GD_CIRCLE(0.0,0.0,sqrt(mx));
    
    cout << setprecision(12) << acos(-1.0L)*(mx-mn) << endl;

}