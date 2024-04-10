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
auto ccw(pt p1, pt p2, pt p3) {auto u = p2-p1, v = p3-p1;return cross(u,v);}
auto in(pt p1, pt p2) {return (ll)p1.X*p2.X+(ll)p1.Y*p2.Y;}
auto norm(pt p) {return (ll)p.X*p.X+(ll)p.Y*p.Y;}
bool comp(const pt& a, const pt& b) { return a.X<b.X or (a.X==b.X and a.Y < b.Y);}
void read(pt& p) {
    int a,b; cin >> a >> b;
    p = {a,b};
}
int dist(pt p) {
    return abs(p.X)+abs(p.Y);
}
pt dir(pt p) {
    p = {sgn(p.X),sgn(p.Y)};
    if(p.X) p = {p.X,0};
    if(p.Y) p = {0,p.Y};
    return p;
}
int main() {
    array<pt,3> pts;
    for(auto& i : pts) read(i);
    array<int,3> ord = {0,1,2};
    array<int,3> ans = {oo,oo,oo};
    for(int i=0;i<=1000;++i) {
        for(int j=0;j<=1000;++j) {
            pt p = {i,j};
            ans = min(ans, {dist(p-pts[0])+dist(p-pts[1])+dist(p-pts[2])+1,i,j});
        }
    }
    cout << ans[0] << '\n';
    cout << ans[1] << ' ' << ans[2] << '\n';
    for(auto to : pts) {
        auto at = pt{ans[1],ans[2]};
        if(at==to) continue;
        do {
            at += dir(to-at);
            cout << at.X << ' ' << at.Y << '\n';

        } while(at!=to);
    }
}