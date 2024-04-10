#include "bits/stdc++.h"
#ifdef LOCAL
#include "geodeb.h"
#endif
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
void print(const pt& p) {
    cout << p.X << ' ' << p.Y << '\n';
}

int main() {
    int n; cin >> n;
    ll s; cin >> s;
    vector<pt> pts(n);
    for(auto& i : pts) read(i);
    sort(all(pts), comp);
    
    vi ord(n); iota(all(ord),0);
    vi rnk = ord;
    vector<pi> vp;
    for(int i=0;i<n;++i) {
        for(int j=i+1;j<n;++j) vp.push_back({i,j});
    }
    sort(all(vp), [&](pi a, pi b) {
        auto v = pts[a.second]-pts[a.first], w = pts[b.second]-pts[b.first];
        auto cw =  cross(v,w);
        return cw<0;
        // return cross(v, pts[b.second]-pts[a.second])<0;
    });
    // GD_INIT("triangle.html");
    // for(auto& i : pts) {
    //     GD_POINT(i.X,i.Y);
    // }
    for(auto [i,j] : vp) {
        // GD_LAYER():
        auto v = pts[j]-pts[i];
        // GD_SEGMENT(0,0,v.X,v.Y);
        int& a = rnk[i],&b = rnk[j];
        assert(abs(a-b)==1);
        swap(a,b);
        swap(ord[a],ord[b]);
        // i,j is leftmost segment
        int lo = max(a,b)+1, hi = n-1;
        while(lo<=hi) {
            int mid = (lo+hi)/2;
            int om = ord[mid];
            ll cur = abs(ccw(pts[i],pts[j], pts[om]));
            if(cur==s*2) {
                cout << "Yes\n";
                print(pts[i]),print(pts[j]),print(pts[om]);
                exit(0);
            } else if(cur>s*2) {
                hi=mid-1;
            } else lo = mid+1;
        }
    }
    cout << "No\n";
}