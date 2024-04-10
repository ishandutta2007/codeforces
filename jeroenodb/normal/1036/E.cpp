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
typedef complex<ll> pt;
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
template<class P> bool onSegment(P s, P e, P p) {
return ccw(p,s,e) == 0 && in(s - p,e - p) <= 0;
}
template<class P> vector<P> segInter(P a, P b, P c, P d) {
    auto oa = ccw(c, d, a), ob = ccw(c,d, b),
    oc = ccw(a,b, c), od = ccw(a,b, d);
    // Checks if intersection is single nonendpoint point.
    if(a==c or a==d) return {a};
    if(b==c or b==d) return {b};
    if (sgn(oa) * sgn(ob) < 0 && sgn(oc) * sgn(od) < 0) {
        P nom = (a * ob - b * oa);
        auto denom =  (ob - oa);
        if(nom.X%denom==0 and nom.Y%denom==0) return {nom/denom};
    }
    if (onSegment(c, d, a)) return {a};
    if (onSegment(c, d, b)) return {b};
    if (onSegment(a, b, c)) return {c};
    if (onSegment(a, b, d)) return {d};
    return {};
}
int main() {
    int n; cin >> n;
    vector<array<pt,2>> v(n);
    ll ans=0;
    for(int i=0;i<n;++i) {
        auto& [p,q] = v[i];
        read(p),read(q);
        auto x = (q-p).X, y=(q-p).Y;
        ans+=abs(gcd(x,y))+1;
        set<pi> s;
        for(int j=0;j<i;++j) {
            for(auto is : segInter(p,q,v[j][0],v[j][1])) {
                s.insert({is.X,is.Y});
            }
        }
        ans-=s.size();
    }
    cout << ans << '\n';
}