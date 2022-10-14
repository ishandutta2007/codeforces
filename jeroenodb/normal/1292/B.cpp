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
typedef complex<__int128_t> pt;
#define X real()
#define Y imag()
auto cross(pt u, pt v) {return (ll)u.X*v.Y-(ll)u.Y*v.X;}
auto sgn(ll a) {return a==0?0:(a>0?1:-1);}
auto ccw(pt p1, pt p2, pt p3) {auto u = p2-p1, v = p3-p2;return cross(u,v);}
auto in(pt p1, pt p2) {return (ll)p1.X*p2.X+(ll)p1.Y*p2.Y;}
auto abs(__int128_t a) {return a<0?-a:a;}
auto norm(pt p) {return abs(p.X)+abs(p.Y);}
bool comp(const pt& a, const pt& b) { return a.X<b.X or (a.X==b.X and a.Y < b.Y);}
void read(pt& p) {
    ll a,b; cin >> a >> b;
    p = {a,b};
}
pt a,b;
pt nxt(pt p) {
    return pt{p.X*a.X,p.Y*a.Y}+b;
}
int main() {
    vector<pt> pts = {{0,0}}; read(pts[0]);
    read(a), read(b);
    pt st; read(st);
    while(norm(pts.back())<(__int128_t)8.1e20) {
        pts.push_back(nxt(pts.back()));
    }
    ll t; cin >> t;
    int n = pts.size();
    int ans = 0;
    for(int rep=0;rep<2;++rep) {
        for(int i=0;i<n;++i) {
            ll left = t;
            pt at = st;
            int j;
            for(j=i;j<n;++j) {
                if(norm(pts[j]-at)>left) {
                    break;
                }
                left-=norm(at-pts[j]);
                at = pts[j];
            }
            ans = max(ans,j-i);
        }
        reverse(all(pts));
    }
    cout << ans << '\n';
}