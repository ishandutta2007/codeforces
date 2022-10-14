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
auto ccw(pt p1, pt p2, pt p3) {auto u = p2-p1, v = p3-p2;return cross(u,v);}
auto in(pt p1, pt p2) {return (ll)p1.X*p2.X+(ll)p1.Y*p2.Y;}
auto norm(pt p) {return (ll)p.X*p.X+(ll)p.Y*p.Y;}
bool comp(const pt& a, const pt& b) { return a.X<b.X or (a.X==b.X and a.Y < b.Y);}
void read(pt& p) {
    int a,b; cin >> a >> b;
    p = {a,b};
}
void solve(int n) {
    // two diagonal lines
    debug(n);
    int rect = (n+1)/3;
    vector<pt> res;
    if(n==1 or n==2) {
        cout << "1\n1 1\n";
        return;
    }
    for(int i=0;i<rect-1;++i) {
        res.push_back({i,rect-2-i});
    }
    for(int i=0;i<rect;++i) {
        res.push_back({rect-1+i,rect-2+rect-i});
    }
    int extra = (n+1)%3;
    for(int i=0;i<extra;++i) {
        res.push_back(res.back()+ pt{1,0});
    }
    // vector<string> g(n,string(n,'.'));
    // for(auto i : res) {
    //     g[i.X][i.Y]='Q';
    // }
    // for(auto i : g) cout << i << '\n';
    cout << res.size() << '\n';
    for(auto p : res) cout << p.X+1 << ' ' << p.Y+1 << '\n';
}
int main() {
    // for(int n=1;n<=9;++n) solve(n);
    int n; cin >> n;
    solve(n);
}