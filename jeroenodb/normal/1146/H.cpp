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
const int mxN = 300+1, oo = 1e9;
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
bool lexo(pt a, pt b) {
    return a.X<b.X or (a.X==b.X and a.Y > b.Y);
}
const pt o = {0,0};
bool polarcomp(const pt& a, const pt& b) {
    bool lex1 = lexo(o,a), lex2 = lexo(o,b);
    if(lex1!=lex2) return lex1<lex2;
    auto cw = ccw(o,a,b);
    if(cw==0) return norm(a-o)<norm(b-o);
    return cw>0;
}
ll dp[5][mxN];
int main() {
    int n; cin >> n;
    vector<pt> pts(n);
    for(auto& i : pts) read(i);
    vector<array<int,2>> vs;
    for(int i=0;i<n;++i) for(int j=0;j<n;++j) if(i!=j) {
        vs.push_back({i,j});
    }
    sort(all(vs),[&](auto p, auto q) {return polarcomp(pts[p[1]]-pts[p[0]],pts[q[1]]-pts[q[0]]);});
    ll ans=0;
    for(int s=0;s<n;++s) {
        for(int i=0;i<5;++i) 
            fill_n(dp[i],n,0);
        dp[0][s]=1;
        for(auto [f,to] : vs) {
            if(to==s) ans+=dp[4][f];
            for(int k=0;k<4;++k) {
                dp[k+1][to]+=dp[k][f];
            }
        }
    }
    cout << ans << '\n';
}