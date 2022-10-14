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
const int mxN = 1e5+1, oo = 1e9;
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
struct line {
    double a,b; // y=ax+b
    line(const pt& online,const pt& v)  {
        a = (double)v.Y/v.X;
        b = online.Y-online.X*a;
    }
    complex<double> intersect(const line& o) {
        // assumes lines are not parallel
        double x = (b-o.b)/(o.a-a);
        return {x,a*x+b};
    }
};
int main() {
    // GD_INIT("hobbit.html");
    int n,h; cin >> n >> h;
    vector<pt> pts(n); for(auto& p: pts) { read(p); 
    //     GD_POINT(p.X,p.Y);
    }
    pt eye = pts[n-1] + pt{0,h};
    // GD_POINT(eye.X,eye.Y,"bold red");
    pt highest = pts[n-1]-eye;
    double ans = 0;
    for(int i=n-1;i>0;--i) {
        pt lo = pts[i], hi = pts[i-1];
        auto tmp1 = cross(lo-eye,highest), tmp2 = cross(hi-eye,highest);
        if(tmp2 >= 0 and tmp1 >=0) {
            ans+= sqrt(norm(hi-lo));
        } else if(tmp2>0 and tmp1 < 0) {
            // Difficult case: Intersect line segments
            line a = line(eye,highest), b = line(hi, lo-hi);
            auto tmp = a.intersect(b);
            // GD_POINT(tmp.X,tmp.Y,"blue");
            ans+=abs(complex<double>(hi.X,hi.Y)-tmp);
        }
        if(tmp2 > 0) {
            highest = hi-eye;

        }
    }
    cout << setprecision(10) << ans << endl;
}