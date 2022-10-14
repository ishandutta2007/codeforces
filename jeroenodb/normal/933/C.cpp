#include "bits/stdc++.h"
#ifdef LOCAL
#include "geodeb.h"
#endif
using namespace std;
#define all(x) begin(x),end(x)
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { string sep; for (const T &x : v) os << sep << x, sep = " "; return os; }
#define debug(a) cerr << "(" << #a << ": " << a << ")\n";
typedef long double ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
const int mxN = 1e5+1, oo = 1e9;
typedef complex<long double> pt;
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
typedef pt P;
const double EPS = 1e-10;
vector<pt> circleInter(P a,P b,long double r1,long double r2) {
    if (a == b) {  return {}; }
    P vec = b - a;
    long double d2 = norm(vec), sum = r1+r2, dif = r1-r2,
        p = (d2 + r1*r1 - r2*r2)/(d2*2), h2 = r1*r1 - p*p*d2;
    if (sum*sum < d2 || dif*dif > d2) return {};
    if(h2<EPS) return {a+vec*p};
    P mid = a + vec*p, per = vec*pt{0,1} * sqrtl(fmax(0, h2) / d2);
    return  {mid + per, mid - per};
}
struct mycomp {
    bool operator()(const pt& a, const pt& b) const {
        if(abs(a.X-b.X)<EPS) {
            if(abs(b.Y-a.Y)<EPS) return false;
            return a.Y<b.Y;
        }
        return a.X<b.X;
    }
};
int main() {
    int n; cin >> n;
    int C=0,V=n,E=0;
    vector<pt> ps(n);
    vector<ll> r(n);
    set<pt,mycomp> pts;
    int inter=0;
    // GD_INIT("acolourprosp.html");
    for(int i=0;i<n;++i) {
        read(ps[i]);
        cin >> r[i];
        // GD_CIRC(ps[i].X,ps[i].Y,r[i]);
        for(int j=0;j<i;++j) {
            auto v = circleInter(ps[i],ps[j],r[i],r[j]);
            if(!v.empty()) inter++;
            for(auto q : v) pts.insert(q);
        }
    }
    for(int i=0;i<n;++i) {
        int num=1;
        for(auto q : pts) {
            if(abs(abs(q-ps[i])-r[i])<EPS) {
                num++;
            }
        }
        E+=num;
    }


    
    V+=pts.size();
    if(inter==0) C = n;
    else if(inter==1) C=n-1;
    else C = 1;
    // GD_PAUSE() << "V: " << V;
    // GD_PAUSE() << "E: " << E;
    // GD_PAUSE() << "C: " << C;
    cout << 1+C-V+E;
}