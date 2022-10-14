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
double contribution(pt p, pt q) {
    auto v = q-p;
    long double res = -abs(gcd(v.X,v.Y));
    res+=cross(p,q);
    return res*0.5L;
}
const int PREC = 250;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long double ptwo[PREC+2] = {};
    ptwo[0]=1;
    for(int i=1;i<=PREC+1;++i) ptwo[i]=ptwo[i-1]*0.5;
    int n; cin >> n;
    
    vector<pt> pts(n);
    for(auto& i : pts) read(i);
    long double ans=0;
    for(int i=0;i<n;++i) {
        for(int j = 1;j<min(n,PREC);++j) {
            int o = n-1-j;
            long double bad = o>PREC?0:ptwo[o];
            ans+=(1-bad)*ptwo[j+1]*contribution(pts[i],pts[(i+j)%n]);
        }
    }
    long double bad = ((ll)n*(n-1)/2 + n+1)*ptwo[min(PREC,n)];
    ans/= 1.L - bad;
    ans+=1;
    cout << setprecision(15) << ans << '\n';

}