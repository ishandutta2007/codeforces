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
vector<pt> pts;
list<int> ord;
int n;
bool white(int i) {return i<n;}
int mysgn(int i) {return i<n?1:-1;}
vi p;
typedef list<int>::iterator IT;
void connect(IT l, IT r) {
    int a = *l, b = *r;
    // GD_SEGMENT(pts[a].X,pts[a].Y,pts[b].X,pts[b].Y,"orange");
    if(a>b) swap(a,b);
    p[a]=b-n+1; 
}
void solve(IT l, IT r) {
    if(l==r) return;
    // {
    // GD_LAYER();
    // GD_POINT(pts[*l].X,pts[*l].Y,"blue bold");
    // GD_POINT(pts[*prev(r)].X,pts[*prev(r)].Y,"blue bold");
    // }
    if(next(l)==prev(r)) {
        connect(l, prev(r));
        return;
    }
    if(white(*l)==white(*prev(r))) {
        // split step
        auto it = l;
        int balance=mysgn(*it);
        while(balance!=0) {
            balance+=mysgn(*++it);
        }
        ++it;
        solve(l,it);
        solve(it, r);
    } else {
        // find upper hull
        vector<IT> h;
        h = {l, next(l)};
        auto it = next(h.back());
        while(it!=r) {
            while(h.size()>=2 and ccw(pts[*h.end()[-2]], pts[*h.back()] , pts[*it])>0) {
                h.pop_back();
            }
            h.push_back(it++);
        }
        // {
        // GD_LAYER();
        // for(auto i : h) {
        //     GD_POINT(pts[*i].X,pts[*i].Y ,"red bold");
        // }
        // }
        int k = h.size();
        for(int i=0;i+1<k;++i) {
            if(white(*h[i])!=white(*h[i+1])) {
                connect(h[i], h[i+1]);
                if(h[i]==l) ++l;
                if(h[i+1]==l) ++l;
                ord.erase(h[i]);
                ord.erase(h[i+1]);
                ++i;
            }
        }
        solve(l,r);
    }
}
int main() {
    // GD_INIT("guardduty.html");
    cin >> n;
    pts.resize(2*n);
    for(auto& i : pts) read(i);
    // for(int i=0;i<2*n;++i) {
    //     GD_POINT(pts[i].X,pts[i].Y, white(i)?"green":"black");
    // }

    vi o(2*n);iota(all(o),0);
    sort(all(o),[&](int i, int j) {return comp(pts[i],pts[j]);});
    p.resize(n);
    ord  = list<int>(all(o));
    solve(all(ord));
    for(auto& i : p) {
        cout << i << '\n';
    }
}