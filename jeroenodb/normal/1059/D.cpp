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
void read(pt& p) {
    int a,b; cin >> a >> b;
    p = {a,b};
}
int main() {
    int n; cin >> n;
    vector<pt> pts(n);
    
    for(auto& p: pts) read(p);
    bool pos = pts[0].Y>0;
    int mxY = 0;
    for(int i=0;i<n;++i) {
        auto& p = pts[i];
        if((p.Y > 0) != pos) {
            cout << "-1\n";
            exit(0);
        }
        if(!pos) {
            p = {p.X,-p.Y};
        }
        mxY = max(mxY, p.Y);
    }

    // Binary search on circle radius
    auto can = [&](double mid) {

        double l = -1e8, r = 1e8;
        for(auto& p: pts) {
            auto tmp = p.Y*(2*mid-p.Y); 
            double deltax = tmp<1e-10?0.0:sqrt(tmp);
            l = max(l,p.X-deltax);
            r = min(r, p.X+deltax);
            if(l>r) {
                return false;
            }
        }
        return true;
    };
    double lo = -99, hi = 0.5*mxY;
    bool noiter = true;
    while(!can(hi))  {
        hi*=2;
        noiter = false;
    }
    if(noiter) {
        lo=hi;
    } else lo = hi/2;
    for(int rep=0;rep<60 and hi-lo >= 1e-8;++rep) {
        double mid = 0.5*(lo+hi);
        if(can(mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    cout << setprecision(10) << 0.5*(lo+hi) << endl;

}