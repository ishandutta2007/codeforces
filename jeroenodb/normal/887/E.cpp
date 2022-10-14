#include "bits/stdc++.h"
#ifdef LOCAL
#include "geodeb.h"
#endif
using namespace std;
#define all(x) begin(x),end(x)
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { string sep; for (const T &x : v) os << sep << x, sep = " "; return os; }
#define debug(a) cerr << "(" << #a << ": " << a << ")\n";
typedef double ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
const int mxN = 1e5+1, oo = 1e9;
// #define double long double
typedef complex<double> pt;
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
pt a, b;
double INF = 1e11;
template<typename F> double findapproxzero(F f, double lo = -INF,double hi = INF) {
    auto best = [&](double c, double d) {
        if(abs(f(c)) < abs(f(d))) return c;
        return d;
    };
    auto l = sgn(f(lo)), r = sgn(f(hi));
    if(l!=0 and l==r) {
        return best(lo,hi);
    }
    for(int rep=0;rep<100;++rep) {
        auto mid = 0.5*(lo+hi);
        auto mysgn = sgn(f(mid));
        if(mysgn==l) {
            lo = mid;
        } else {
            hi = mid;
        }
    }
    return 0.5*(lo+hi);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    read(a),read(b);
    #ifdef LOCAL
    GD_INIT("littlebro.html");
    GD_POINT(a.X,a.Y,"bold green");
    GD_POINT(b.X,b.Y,"bold green");
    GD_SEGMENT(a.X,a.Y,b.X,b.Y,"blue");
    #endif
    auto midpoint = (a+b)*0.5; 
    auto dir = (b-a)*pt{0,1};
    dir/=abs(dir);
    auto pos = [&](double y) {
        return midpoint+y*dir;
    };
    auto radius = [&](double y) {
        return abs(pos(y)-a);
    };
    vector<pair<double,int>> es;
    int n; cin >> n;
    for(int i=0;i<n;++i) {
        pt p; double r;
        read(p); cin >> r;
        auto f = [&](double y) {
            return radius(y)- abs(pos(y)-p) + r;
        };
        auto g = [&](double y) {
            return radius(y)- abs(pos(y)-p) - r;
        };
        auto c = findapproxzero(f), d = findapproxzero(g);
        if(c>d) swap(c,d);
        #ifdef LOCAL
        GD_CIRCLE(p.X,p.Y,r);
        GD_LAYER();
        
        for(auto j : {c,d}) {
            auto q = pos(j);
            GD_CIRCLE(q.X,q.Y,radius(j),"red");
        }
        #endif
        es.push_back({c,1});
        es.push_back({d,-1});
    }
    es.push_back({0,0});    
    sort(all(es));
    int overlap=0;
    double best = 1e13;
    for(auto [y, sgn] : es) {
        if(sgn<0) overlap+=sgn;
        if(overlap==0) {

            best = min(best,radius(y));
        }
        if(sgn>=0) overlap+=sgn;
    }
    cout << setprecision(15) <<  best << '\n';
}