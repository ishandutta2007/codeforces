// #pragma GCC optimize "Ofast"
// #pragma GCC optimize "unroll-loops"
#include <iostream>
#include <complex>
#include <vector>
#include <cmath>
#include <iomanip>
// #include "geodeb.h"
using namespace std;
// typedef complex<double> coord;
// #define X real()
// #define Y imag()
struct coord {
    double X, Y;
    coord operator-(const coord& o) const {
        return {X-o.X,Y-o.Y};
    }
    coord operator+(const coord& o) const {
        return {X+o.X,Y+o.Y};
    }
};
coord operator*(double d, coord c) {
    return {d*c.X, d*c.Y};
}
double norm(const coord& c) {
    return c.X*c.X+c.Y*c.Y;
}
double abs(const coord& c) {
    return sqrt(norm(c));
}
const int mxN = 1e6+1;
auto in(coord a, coord b) {
    return a.X*b.X+a.Y*b.Y;
}
template <typename T> int sgn(T val) {
    return (T(0) < val) - (val < T(0));
}
double distancepointlineseg(coord p, coord sg1, coord sg2) {
    auto v = p-sg1, u = sg2-sg1;
    auto inp = in(v, u);
    if(inp<=0) {
        // // GD_SEGMENT(p.X,p.Y,sg1.X,sg1.Y,"orange");
        return norm(v);
    } else if(inp>=norm(u)) {
        // // GD_SEGMENT(p.X,p.Y,sg2.X,sg2.Y,"orange");
        return norm(p-sg2);
    }
    // // GD_SEGMENT(p.X,p.Y,sg1.X,sg1.Y,"purple");
    auto inp2 = in(v, {u.Y,-u.X});
    return inp2*inp2/norm(u);
}

// bool rayup(coord sg1, coord sg2) {
//     if(sg1.X==0 or sgn(sg1.X)==-sgn(sg2.X)) {
//         if(sg1.X==sg2.X) {
//             return sg1.Y>=0 or sg2.Y>0;
//         }
//         if(sg1.X==0) {
//             if(sg1.Y==0) onseg = true;
//             return sg1.Y>=0;
//         }
//         if(max(sg1.Y,sg2.Y)<0) return false;
//         if(min(sg1.Y,sg2.Y)>=0) return true;
//         auto v = sg2-sg1;
//         auto tmp = sg1.Y+v.Y*v.X/sg1.X;
//         if(tmp==0) onseg = true;
//         return tmp>=0;
//     }
//     return false;
// }
typedef coord pt;
typedef long long ll;
auto cross(pt u, pt v) {return u.X*v.Y-u.Y*v.X;}
auto ccw(pt p1, pt p2, pt p3) {auto u = p2-p1, v = p3-p2;return cross(u,v);}
int quadrant(pt p) {
    if(p.X==0 and p.Y==0) return -1;
    if(p.X>=0 and p.Y>0) return 0;
    if(p.X<0 and p.Y>=0) return 1;
    if(p.X<=0 and p.Y<0) return 2;
    return 3;
}
int inpoly(int n,const vector<coord>& poly, coord p) {
    
    int winding = 0;
    int q = quadrant(poly[0]-p);
    for(int i=1;i<=n;++i) {
        int j = (i==n?0:i);
        int nq = quadrant(poly[j]-p);
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
        int tmp = sgn(ccw(poly[j],poly[i-1],p));
        if(tmp==0) return 0;
        winding-=2*tmp;
        q = nq;
    }
    // assert(winding%4==0);
    // if(winding%4!=0) {
    //     cout << "Whoops!\n";
    //     // GD_PAUSE() << "Winding wrong Floating Point error?\n";
    // }
    return winding/4==0?-1:1;
}
// struct boundingbox {
//     pt a, b;
//     double dist(pt p) {
//         for(int rep=0;rep<2;++rep) {

//         }
//     }
// };
const double oo = 1e18;

struct polygon {

    vector<coord> pts;

    pt m={0,0};
    double furthest=0, A=0;
    int n;
    bool optimization=false;
    auto area() {
        auto ans=(pts[0].Y-pts[n-1].Y)*(pts[0].X+pts[n-1].X);
        for(int i=1;i<n;++i) {
            ans+=(pts[i].Y-pts[i-1].Y)*(pts[i].X+pts[i-1].X);
        }
        return abs(ans)*0.5;
    }
    void init(bool optimize) {
        if(optimize) {
            optimization=true;
            double mnx=oo, mxx=-oo, mny=oo, mxy=-oo;
            for(int i=0;i<n;++i) {
                auto& p = pts[i];
                mnx = min(mnx,p.X);
                mxx = max(mxx,p.X);
                mny = min(mny,p.Y);
                mxy = max(mxy,p.Y);
            }
            m = 0.5*(pt{mnx,mny}+pt{mxx,mxy});
            furthest = 0.5*abs({mxx-mnx,mxy-mny});
        }
        A=area();
    }
    bool inside(coord c) {
        // GD_LAYER();
        return inpoly(n,pts,c)>=0;
    }
    bool inside(coord c, double rr) {
        if(optimization) {
            if(abs(c-m)>sqrt(rr)+furthest) {
                return false;
            }
        }
        for(int i=1;i<=n;++i) {
            // // GD_LAYER();
            int j = (i==n?0:i);
            auto sg1 = pts[i-1], sg2 = pts[j];
            auto tmp = distancepointlineseg(c,sg1,sg2);
            // GD_SEGMENT(sg1.X,sg1.Y,sg2.X,sg2.Y,"blue bold") << tmp << " distance to midpoint, r = " << r ;
            // GD_PAUSE();
            if(tmp<=rr) {
                return true;
            }
        }
        return inside(c);

    }
};

polygon props[mxN];
int main() {
    // GD_INIT("debug.html");
    // GD_LOG_TO_STDERR(false);
    double w,h; int n;
    scanf("%lf%lf%d",&w,&h,&n);
    bool nsmall = n<1e5;
    for(int i=0;i<n;++i) {
        int v; 
        scanf("%d",&v);
        props[i].n=v;
        props[i].pts.resize(v);
        for(int j=0;j<v;++j) {
            double x,y; 
            scanf("%lf%lf",&x,&y);
            props[i].pts[j] = {x,y};
        }; 
        props[i].init(true);
        // GD_POLYGON("black:salmon",
        //     for (int j = 0; j < v; ++j) {
        //       // GD_POLYPOINT(props[i].pts[j].X, props[i].pts[j].Y);
        //     }
        // );   
    }
    int q; scanf("%d",&q);
    while(q--) {
        double x, y, rr;
        scanf("%lf%lf%lf",&x,&y,&rr);
        double ans = 0;
        vector<int> cand;
        // GD_LAYER();
        // GD_CIRCLE(x,y,r);
        rr = rr*rr;
        for(int i=0;i<n;++i) {
            auto& p = props[i];
            if(p.inside({x,y},rr)) {
                ans+=p.A;
                cand.push_back(i);
            }
        }
        cout << setprecision(9) << ans << ' ' << cand.size();
        string s;
        for(int id: cand) {
            s+=' '+to_string(id);
        }
        cout << s << '\n';
    }
}