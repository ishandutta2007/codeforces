#include "bits/stdc++.h"
using namespace std;
#define all(x) begin(x),end(x)
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { string sep; for (const T &x : v) os << sep << x, sep = " "; return os; }
#define debug(a) cerr << "(" << #a << ": " << a << ")\n";
typedef __int128_t ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
const int mxN = 1e5+1, oo = 1e9;
typedef complex<long long> pt;
#define X real()
#define Y imag()
auto cross(pt u, pt v) {return (ll)u.X*v.Y-(ll)u.Y*v.X;}
auto sgn(ll a) {return a==0?0:(a>0?1:-1);}
auto ccw(pt p1, pt p2, pt p3) {auto u = p2-p1, v = p3-p2;return cross(u,v);}
auto in(pt p1, pt p2) {return (ll)p1.X*p2.X+(ll)p1.Y*p2.Y;}
auto norm(pt p) {return (ll)p.X*p.X+(ll)p.Y*p.Y;}
bool comp(const pt& a, const pt& b) { return a.X<b.X or (a.X==b.X and a.Y < b.Y);}
void read(pt& p) {
    int a,b; cin >> a >> b;
    p = {a,b};
}
int main() {
    int n; cin >> n;
    pt sm=0;
    vector<pt> pts(n);
    for(auto& i : pts) read(i),sm+=i,i*=n;
    for(auto& i : pts) i-=sm;
    sort(all(pts),comp);
    vector<pt> p;
    for(int i=0;i<n;++i) {
        if(!binary_search(all(pts),-pts[i],comp)) {
            p.push_back(pts[i]);
        }
    }
    if(p.empty()) {
        cout << "-1\n";
        exit(0);
    }
    for(auto& i : p) i*=2;
    vector<pt> cands;
    n =p.size();
    for(int i=0;i<n;++i) {
        pt mid = (p[0]+p[i])/2LL;
        ll g = gcd(abs(mid.X),abs(mid.Y));
        assert(g!=0);
        mid/=g;
        if(comp(mid,pt{0,0})) mid = -mid;
        mid*=pt{0,1};
        cands.push_back(mid);
    }
    sort(all(cands),comp);
    cands.erase(unique(all(cands)),cands.end());
    int ans=0;
    for(auto vec : cands) {
        vector<ll> a; a.reserve(n);
        for(auto& i : p) a.push_back(in(i,vec));
        sort(all(a));
        auto b = a;
        reverse(all(b));
        for(auto& i : b) i=-i;
        if(a==b) {
            ans++;
        }
    }
    cout << ans << '\n';
    
}