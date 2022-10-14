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
typedef complex<double> pt;
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
double darea(const vector<pt>& poly) {
    auto prv= poly.back(),o=poly[0];
    long long ans=0;
    for(auto& p : poly) {
        ans+=cross(p-o,prv-o);
        prv=p;
    }
    return ans;
}
pt centroid(const vector<pt>& poly) {
    auto o = poly[0],prv=poly.back();
    pt ans=0;
    for(auto& p : poly) {
        ans+=cross(p-o,prv-o)*(p+prv-o*2.0);
        prv=p;
    }
    return o+ ans/(3*darea(poly));
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // GD_INIT("hags.html");
    int n,q; cin >> n >> q;
    vector<pt> pts(n);
    for(auto& p : pts) read(p);
    auto cent=centroid(pts);
    vector<pt> vectors(n);
    vector<double> lens(n), angs(n),angs2(n);
    for(int i=0;i<n;++i) vectors[i]=pts[i]-cent, lens[i]=abs(vectors[i]),angs[i]=arg(vectors[i]),angs2[i]=arg(-vectors[i]);
    double angle=0;
    int a=0,b=1;
    auto get = [&](int i) {
        return cent+polar(1.0,angle)*vectors[i];
    };
    for(int i=0;i<n;++i) {
        // GD_POINT(get(i).X,get(i).Y,"green");
    }
    const double PI = 3.141592653589793238462643383279;
    while(q--) {
        int type; cin >> type;
        if(type==1) {
            int f,t; cin >> f >> t,--f,--t;
            if(a!=f) swap(a,b);
            // rotate around b
            cent = get(b)-pt{0,lens[b]};
            angle = -angs[b]+PI/2;
            // for(int i=0;i<n;++i) {
            //     // GD_POINT(get(i).X,get(i).Y,"red");
            // }
            a=t;
        } else {
            int i; cin >> i;
            auto res  =get(i-1);
            cout << setprecision(15) << res.X << ' ' << res.Y << '\n';
        }
    }
}