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
typedef complex<double> pt;
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
const double PI = 3.14159265359;
auto rotate(pt v, int a) {
    return v*= -polar(1.0,PI*a/180);
}
int main() {
    // GD_INIT("floodlight.html");
    int n; cin >> n;
    int l,r; cin >> l >> r;
    // GD_SEGMENT(l,0,r,0, "red bold");
    struct light {
        pt p;
        int a;
        void read() {
            using ::read;
            read(p);
            p = {p.X,abs(p.Y)};
            // GD_POINT(p.X,p.Y);
            cin >> a;
        }
    };

    vector<light> ls(n);
    for(auto& i: ls) i.read();
    vector<double> dp(1<<n,l);
    bool found = false;
    for(int i=0; i < (1<<n);++i) {
        // if(dp[i]==r) {
        //     found = true;
        //     cout << r-l << endl;
        //     break;
        // }
        auto u = pt{dp[i],0};
        for(int j=0;j<n;++j) {
            if(!(i&(1<<j))) {
                auto& p = ls[j].p;
                auto v = p-u;
                v = rotate(v,ls[j].a);

                pt b = p+v;
                // GD_SEGMENT(p.X, p.Y, u.X, u.Y);
                // GD_SEGMENT(p.X, p.Y, b.X, b.Y) << v.X << ' ' << v.Y;
                int dy = ls[j].p.Y;
                auto cmax = [](double& a, const double& b) {
                    a = max(a,b);
                };
                if(v.Y>=-1e-8) {
                    dp[i|(1<<j)] = r;
                } else {
                    cmax(dp[i|(1<<j)], min((double)r,p.X-v.X*dy/v.Y));
                }
            }
        }
    }
    if(!found) {
        cout << setprecision(10) << dp.back()-l << endl;
    }

}