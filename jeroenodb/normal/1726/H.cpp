#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
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
typedef complex<double> pt;
#define X real()
#define Y imag()
auto cross(pt u, pt v) {return (ll)u.X*v.Y-(ll)u.Y*v.X;}
auto sgn(ll a) {return a==0?0:(a>0?1:-1);}
auto ccw(pt p1, pt p2, pt p3) {auto u = p2-p1, v = p3-p2;return cross(u,v);}
auto in(pt p1, pt p2) {return (ll)p1.X*p2.X+(ll)p1.Y*p2.Y;}
bool comp(const pt& a, const pt& b) { return a.X<b.X or (a.X==b.X and a.Y < b.Y);}
void read(pt& p) {
    int a,b; cin >> a >> b;
    p = {a,b};
}
typedef pt P;
const double eps = 1./9133;
const double PI = acos(-1);
auto getLine(double ang) {
    vector<pair<double,double>> line;
    auto sinang = sin(ang);
    auto cosoang = -cos(ang);
    line.reserve(7000);
    line.push_back({0,0});
    
    for(double i = eps;i<0.74;i+=eps) {
        // pt p = circleLine( cur,1., pt{0,0},polar(1.,ang))[0];
        auto theta = i*sinang;
        auto slope = theta/sqrt(1-theta*theta);
        line.push_back({-slope, (slope*cosoang + sinang)*i});
    }
    line.push_back({tan(ang),0});

    
    return line;
};
double eval(pair<double,double> p, double x) {
    return p.first*x + p.second;
}
#define rep(i,a,b) for(int i=a;i<b;++i)
template<class F>
double quad(double a, double b, F f, const int n = 5201) {
	double h = (b - a) / 2 / n, v = f(a);
	rep(i,1,n*2)
		v += f(a + i*h) * (i&1 ? 4 : 2);
    v+=f(b);
	return v * h / 3;
}

int main() {
    int n; cin >> n;
    vector<pt> pts(n);
    double mn[2] = {oo,oo},mx[2] = {-oo,-oo};
    for(auto&  i : pts) {
        read(i);
        mn[0] = min(mn[0],i.X);
        mn[1] = min(mn[1],i.Y);
        mx[0] = max(mx[0],i.X);
        mx[1] = max(mx[1],i.Y);
    }
    if(mx[1]-mn[1]==1 or mx[0]-mn[0]==1) {
        cout << max(mx[1]-mn[1],mx[0]-mn[0]) << '\n';
        exit(0);
    }
    for(int i=0;i<n;++i) pts.push_back(pts[i]);
    

    struct calc {
        double ang;
        vector<pair<double,double>> ls;
        calc(double a) : ang(PI- a),ls(move(getLine(a))) {
        }
        
        double operator() (double x) {
            auto minimize = [&](double xx) {
                // if(ang>PI*(1-1e-11)) return 10000.;
                return xx*tan(ang/2); 
            };
            while(ls.size()>=2 and eval(ls.back(),x)<eval(ls[ls.size()-2],x)) {
                ls.pop_back();
            }

            return min(minimize(x),eval(ls.back(),x));
        }
    };
    double ans=0;
    map<double,double> cache;
    for(int i=1;i<=n;++i) {
        auto p = pts[i]-pts[i-1];
        auto q = pts[i+1]-pts[i];
        auto r = pts[i+2]-pts[i+1];
        auto getAng = [&](pt u, pt v) {
            return atan2(cross(u,v), in(u,v));
        };
        auto pqa = getAng(p,q), qra = getAng(q,r);
        auto dist = abs(q);
        if(dist<2) {
            auto f1 = calc(pqa);
            auto f2 = calc(qra);
            reverse(all(f2.ls));
            auto f = [&](double x) {
                return max(f1(x),f2(dist-x));
            };
            ans+=quad(0,dist,f);
        } else {
            auto get = [&](double ag) {
                auto it = cache.lower_bound(ag*(1-1e-5));
                if(it!=cache.end() and it->first<ag*(1+1e-5)) {
                    return it->second;
                } else return cache[ag]=quad(0.,1.,calc(ag));
            };
            ans+=get(pqa);
            ans+=get(qra);
        }
    }
    cout << setprecision(15) << fixed << ans << '\n';
    
}