#include <iostream>
#include <complex>
#include <vector>
#include <cmath>
#include <iomanip>
#include <set>
#include <algorithm>
#include <cassert>
// #include "geodeb.h"
#include <string>
using namespace std;
typedef long double ld;
typedef complex<ld> pt;
#define X real()
#define Y imag()
const int mxN = 1e5;
auto in(pt a, pt b) {
    return a.X*b.X+a.Y*b.Y;
}
template <typename T> int sgn(T val) {
    return (T(0) < val) - (val < T(0));
}
ld sweep;
struct car {
    pt pos, d,sg1,sg2;
    ld intersect() {
        auto v = (sg2-sg1);
        assert(v.X>0);
        return sg1.Y+v.Y*(sweep-sg1.X)/v.X;
    }
    void printseg(string s) {
        // GD_SEGMENT(sg1.X,sg1.Y,sg2.X,sg2.Y,s);
    }
};
vector<car> cars;
bool onSegment(pt p, pt q, pt r) 
{ 
    if (q.X <= max(p.X, r.X) && q.X >= min(p.X, r.X) && 
        q.Y <= max(p.Y, r.Y) && q.Y >= min(p.Y, r.Y)) 
       return true; 
  
    return false; 
} 
  
// To find orientation of ordered triplet (p, q, r). 
// The function returns following values 
// 0 --> p, q and r are colinear 
// 1 --> Clockwise 
// 2 --> Counterclockwise 
const ld epsilon = 1e-9;
int orientation(pt p, pt q, pt r) 
{ 
    // See https://www.geeksforgeeks.org/orientation-3-ordered-points/ 
    // for details of below formula. 
    auto val = (q.Y - p.Y) * (r.X - q.X) - 
              (q.X - p.X) * (r.Y - q.Y); 
  
    if (abs(val) <= epsilon) return 0;  // colinear 
  
    return (val > 0)? 1: -1; // clock or counterclock wise 
} 
  
// The main function that returns true if line segment 'p1q1' 
// and 'p2q2' intersect. 
bool doIntersect(pt p1, pt q1, pt p2, pt q2) 
{ 
    // Find the four orientations needed for general and 
    // special cases 
    int o1 = orientation(p1, q1, p2); 
    int o2 = orientation(p1, q1, q2); 
    int o3 = orientation(p2, q2, p1); 
    int o4 = orientation(p2, q2, q1); 
  
    // General case 
    if (o1 != o2 && o3 != o4) 
        return true; 
  
    // Special Cases 
    // p1, q1 and p2 are colinear and p2 lies on segment p1q1 
    if (o1 == 0 && onSegment(p1, p2, q1)) return true; 
  
    // p1, q1 and q2 are colinear and q2 lies on segment p1q1 
    if (o2 == 0 && onSegment(p1, q2, q1)) return true; 
  
    // p2, q2 and p1 are colinear and p1 lies on segment p2q2 
    if (o3 == 0 && onSegment(p2, p1, q2)) return true; 
  
     // p2, q2 and q1 are colinear and q1 lies on segment p2q2 
    if (o4 == 0 && onSegment(p2, q1, q2)) return true; 
  
    return false; // Doesn't fall in any of the above cases 
} 
bool intersect(car& a, car& b) {
    return doIntersect(a.sg1,a.sg2,b.sg1,b.sg2);
};

struct event {
    ld x;    int i;
    bool operator<(event& o) {
        return x<o.x or (x==o.x and i>o.i);
    }

};

struct comp {
    bool operator()(int a, int b) const {
        return cars[a].intersect() < cars[b].intersect();
    }
};
int n;
bool test(ld t) {
    // GD_LAYER();
    multiset<int,comp> active;
    vector<event> events(2*n);
    for(int i =0;i<n;++i) {
        auto& c = cars[i];
        c.sg1 = c.pos;
        c.sg2 = c.pos+c.d*t;
        if(c.sg1.X>c.sg2.X) swap(c.sg1,c.sg2);
        c.printseg("blue");
        events[2*i] = {c.sg1.X,i+1};
        events[2*i+1] = {c.sg2.X,-(i+1)};
    }
    sort(events.begin(),events.end());
    for(auto& e: events) {
        // GD_LAYER() << "NOW event " << e.i;
        sweep = e.x;
        // GD_LINE(sweep,0,sweep,1,"purple") << "active lines = " << active.size();
        // for(auto i: active) // GD_POINT(sweep, cars[i].intersect(),"blue bold");
        if(e.i<0) {
            e.i = -e.i -1;
            active.erase(e.i);
        } else {
            e.i--;
            auto iter = active.insert(e.i);
            cars[e.i].printseg("red bold");
            bool found = false;
            if(iter!=active.begin()) {
                found = true;
                --iter;
                
                if(intersect(cars[e.i],cars[*iter])) {
                    cars[*iter].printseg("green bold");
                    return false;
                }
                cars[*iter].printseg("purple bold");
                
                iter++;
            } 
            assert(e.i==*iter);
            iter++;
            if(iter!=active.end()) {
                found = true;
                if(intersect(cars[e.i],cars[*iter])) {
                    cars[*iter].printseg("green bold");
                    return false;
                }
                cars[*iter].printseg("purple bold");
            }
            assert(found or active.size()==1);
        }
    }
    return true;

}
int main() {
    cin >> n;
    cars.resize(n);
    // GD_INIT("kaboom.html");
    for(int i=0;i<n;++i) {
        int x,y,dx,dy,v; cin >> x >> y >> dx >> dy >> v;
        cars[i] = {{x,y},{dx,dy}};
        // GD_POINT(x,y);
        cars[i].d *= v/abs(cars[i].d);
    }
    ld l = 0, r = 1e13;
    while(r-l > 0.2e-6L) {
        auto mid = (l+r)/2;
        if(!test(mid)) {
            r=mid;
        }else {
            l= mid;
        }
    }
    if(r==1e13) {
        cout << "No show :(\n";
    } else cout << setprecision(15) << (r+l)/2 << endl;
}