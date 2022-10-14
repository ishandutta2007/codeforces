#include "bits/stdc++.h"
using namespace std;
#define all(x) begin(x),end(x)
namespace {
template<class T1, class T2> void prin(const pair<T1,T2>& x);
template<class T> void prin(const vector<T>& x);
template<class T> void prin(const T& x) {cout << x;}
template<class H, class... T> void prin(const H& h, const T&... t) {prin(h); prin(t...); }
template<class T1, class T2> void prin(const pair<T1,T2>& x) {prin(x.first,' ',x.second);}
template<class T> void prin(const vector<T>& x) {for(int i=0;i<(int)x.size();++i) prin(i==0?"":" ",x[i]);}
template<class... T> void print(const T&... t) {prin(t..., "\n"); }
#define debug(x) cout << #x << ": "; print(x)
}
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
const int mxN = 1e5+1, oo = 1e9;
typedef complex<long double> pt;
#define X real()
#define Y imag()
auto cross(pt u, pt v) {return u.X*v.Y-u.Y*v.X;}
auto sgn(ll a) {return a==0?0:(a>0?1:-1);}
auto ccw(pt p1, pt p2, pt p3) {auto u = p2-p1, v = p3-p2;return cross(u,v);}
auto in(pt p1, pt p2) {return p1.X*p2.X+p1.Y*p2.Y;}
struct comp {
    bool operator()(const pt& a, const pt& b) const {
        return a.Y> b.Y;
    }
};
int main() {
    int n,r; cin >>n>> r;
    multiset<pt,comp> circles;
    vector<long double> cs(n);
    for(int i=0;i<n;++i) {
        int x; cin >> x;
        bool found = false;
        cs[i] = r;
        for(auto& p: circles) {
            if(cs[i]>2*r+p.Y) break;
            if(abs((int)p.X-x) <= 2*r) {
                long double lo = p.Y, hi = p.Y+2*r;
                while(hi-lo > 1e-7) {
                    auto mid = 0.5*(lo+hi);
                    pt c = {(double)x,mid};
                    if(norm(c-p)<=4*r*r) {
                        lo = mid;
                    } else {
                        hi = mid;
                    }
                }
                cs[i] = max(cs[i],0.5*(lo+hi));
            }   
        }
        if(!found) {
            pt c = {x,cs[i]};
            circles.insert(c);
        }
    }
    cout << setprecision(12) << fixed;
    print(cs);
}