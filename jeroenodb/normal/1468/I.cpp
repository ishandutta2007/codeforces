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
auto norm(pt p) {return abs(p.X)+abs(p.Y);}
auto dir(pt p) {return pt{sgn(p.X),sgn(p.Y)};}
bool comp(const pt& a, const pt& b) { return a.X<b.X or (a.X==b.X and a.Y < b.Y);}
void read(pt& p) {
    int a,b; cin >> a >> b;
    p = {a,b};
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    pt p,q; read(p),read(q);
    if(cross(p,q)==0) {
        cout << "NO\n";
        exit(0);
    }
    if(p.X<0) p = -p;
    if(q.X<0) q = -q;
    if(cross(p,q)<0) swap(p,q);
    pt far = p+q;

    auto inside = [&](pt at) {
        if(cross(at,p)>0) return -1;
        if(cross(q,at)>=0) return 1;
        // now the tests from far
        if(ccw(p,far,at)<0) return -1;
        if(ccw(far,q,at)<=0) return 1;
        return 0;
    };
    // now binary search for each x
    int mxX = far.X;
    ll ans=0;
    vector<pi> iv;
    for(int i=0;i<=mxX;++i) {
        // bin search for all good
        int lo = -1e7, hi = 1e7;
        while(lo<hi) {
            int mid = lo+ (hi-lo)/2;
            if(inside({i,mid})==-1) {
                lo = mid+1;
            } else  hi = mid;
        }
        int under = lo;
        lo = -1e7, hi = 1e7;
        while(lo<hi) {
            int mid = lo+ (hi-lo+1)/2;
            if(inside({i,mid})==1) {
                hi = mid-1;
            } else lo = mid;
        }
        iv.push_back({under,lo});
        ans+=lo-under+1;
    }
    if(ans==n) {
        cout << "YES\n";
        for(int i=0;i<=mxX;++i) {
            for(int j=iv[i].first;j<=iv[i].second;++j) {
                cout << i << ' ' << j << '\n';
            }
        }
    } else {
        cout << "NO\n";
    }





}