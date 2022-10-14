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
void print(pt p) {
    cout << p.X << ' ' << p.Y;
}
int main() {
    array<int,3> x,y;
    for(int i=0;i<3;++i) cin >> x[i] >> y[i];
    auto sx =x; sort(all(sx));
    int mid = sx[1];
    int lo = *min_element(all(y)),hi = *max_element(all(y));
    vector<pair<pt,pt>> ans;
    if(lo!=hi) ans.push_back({{mid,lo},{mid,hi}});
    for(int i : {0,1,2}) {
        if(x[i]!=mid) ans.push_back({{x[i],y[i]},{mid,y[i]}});
    }
    cout << ans.size() << '\n';
    for(auto [p,q] : ans) {
        print(p); cout << ' ';
        print(q); cout << '\n';
    }



}