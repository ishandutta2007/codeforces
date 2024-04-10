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
auto cross(pt u, pt v) {return u.X*v.Y-u.Y*v.X;}
auto sgn(ll a) {return a==0?0:(a>0?1:-1);}
auto ccw(pt p1, pt p2, pt p3) {auto u = p2-p1, v = p3-p2;return cross(u,v);}
auto in(pt p1, pt p2) {return p1.X*p2.X+p1.Y*p2.Y;}
void read(pt& p) {
    int a,b; cin >> a >> b;
    p = {a,b};
}
int main() {
    int n; cin >> n;
    vector<pt> pts(n);
    map<pi,int> m;
    for(auto& i: pts) read(i);
    ll ans = 0;
    for(int i=0;i<n;++i) {
        for(int j=i+1;j<n;++j) {
            pt middle = pts[i]+pts[j];
            ans+=m[{middle.X,middle.Y}]++;
        }
    }
    cout << ans << endl;
}