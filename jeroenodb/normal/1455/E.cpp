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
array<pt,4> pts;
array<int,4> ord = {0,1,2,3};
array<int,4> cs;

ll f(int sz) {
    int dx[] = {0,sz,0,sz};
    int dy[] = {0,0,sz,sz};
    ll ans = 1e18;
    do {
        for(int i=0;i<4;++i) {
            cs[i] = pts[ord[i]].X + dx[i];
        }
        ll cur=0;
        sort(all(cs));
        for(int i : cs) cur+=abs(i-cs[1]);
        for(int i=0;i<4;++i) {
            cs[i] = pts[ord[i]].Y + dy[i];
        }
        sort(all(cs));
        for(int i : cs) cur+=abs(i-cs[1]);
        ans = min(ans,cur);
        // cs[1] is x coord
    } while(next_permutation(all(ord)));
    return ans;
}
void solve() {
    
    for(auto& i : pts) read(i);
    int lo=0,hi = 1.05e9;
    while(lo<hi) {
        int mid = (lo+hi)/2;
        if(f(mid)<=f(mid+1)) {
            hi = mid;
        } else {
            lo = mid+1;
        }
    }
    cout << f(lo) << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        solve();
    }
}