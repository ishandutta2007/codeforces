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
const int mxN = 2.5e5+1, oo = 1e9;
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
    #ifdef LOCAL
    GD_POINT(p.X,p.Y,"blue");
    #endif
    cout << p.X << ' ' << p.Y << '\n';
}
int from[mxN];
array<vi,2> solvedp(vi& a) {
    int total=0;
    for(auto& i : a) total+=i;
    bitset<mxN> dp;
    dp[0]=1;
    if(total%2!=0) return {};
    for(int w : a) {
        auto tmp = dp<<w & ~dp;
        for(int i = tmp._Find_first();i<=total/2;i=tmp._Find_next(i)) {
            from[i] = w;
        }
        dp|=tmp;
    }
    if(!dp[total/2]) {
        return {};
    }
    int at = total/2;
    vi res;
    multiset<int> left(all(a));
    while(at) {
        int w = from[at];
        res.push_back(w);
        left.erase(left.find(w));
        at-=w;
    }
    sort(all(res));
    return {res, vi(all(left))};
}
void solve() {

    #ifdef LOCAL
    GD_LAYER();
    #endif
    int n; cin >> n;
    vi a(n); for(auto& i : a) cin >> i;
    int m; cin >> m;
    vi b(m); for(auto& i : b) cin >> i;
    if(n!=m) {
        cout << "No\n";
        return;
    }
    auto c = solvedp(a), d = solvedp(b);
    if(c[0].empty() or d[0].empty()) {
        cout << "No\n";
        return;
    }
    if(c[0].size()>c[1].size()) swap(c[0],c[1]);
    if(d[0].size()<d[1].size()) swap(d[0],d[1]);

    cout << "Yes\n";
    int l = c[0].size(), r = d[0].size();
    auto fixup = [&](array<vi,2> halves) {
        for(auto& i : halves[1]) i=-i;
        halves[0].insert(halves[0].end(),all(halves[1]));
        return halves[0];
    };
    auto hori = fixup(c), vert = fixup(d);
    reverse(hori.begin(),hori.begin()+l);
    reverse(hori.begin()+r,hori.end());
    pt at = {0,0};

    for(int i=0;i<n;++i) {
        at+=pt{hori[i],0}; 
        print(at);
        at+=pt{0,vert[i]};
        print(at);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
    GD_INIT("rectangular.html");
    #endif
    int t; cin >> t;
    while(t--) {
        solve();
    }
}