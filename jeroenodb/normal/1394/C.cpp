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
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
template<class I> I rnd(I l,I r){return std::uniform_int_distribution<I>(l,r)(rng);}
map<pi,int> mp;
int main() {
    int n; cin >> n;
    vector<pt> pts(n);
    int xb=0,yb=0;
    for(auto& i : pts) {
        string s; cin >> s;
        i = {count(all(s),'B'), count(all(s),'N')};
        xb = max(xb,i.X), yb = max(yb,i.Y);
    }
    auto g = [&](int x,int y) {
        // if(mp.count({x,y})) return mp[{x,y}];
        int res=0;
        for(auto& i : pts) {
            pt dif = i-pt{x,y};
            if(sgn(dif.X)*sgn(dif.Y)<0) {
                res = max(res,abs(dif.X)+abs(dif.Y));
            } else res=max({res,abs(dif.X),abs(dif.Y)});
        }
        return res;
    };

    int x= xb/2,y = yb/2;
    int myscore = g(x,y);
    double d = 0.5;
    for(int rep=0;rep<min(100000,50000000/n);++rep) {
        int nx = rnd((int)max(x-d*xb-1,0.0),(int)min(x+d*xb+1,(double)xb));
        int ny = rnd((int)max(y-d*yb-1,0.0),(int)min(y+d*yb+1,(double)yb));
        if(nx==0 and ny==0) {
            if(rnd(0,1)==1) nx=1;
            else ny=1;
        }
        int nscore = g(nx,ny);
        if(nscore<=myscore) {
            x=nx,y=ny,myscore=nscore;
        }
        d*=0.95;
    }
    cout << myscore << '\n';
    cout << string(x,'B') << string(y, 'N') << '\n';
}