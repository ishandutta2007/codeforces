#include "bits/stdc++.h"
#ifdef LOCAL
#include "geodeb.h"
#endif
using namespace std;
#define all(x) begin(x),end(x)
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { string sep; for (const T &x : v) os << sep << x, sep = " "; return os; }
#define debug(a) cerr << "(" << #a << ": " << a << ")\n";
typedef double ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
const int mxN = 1e5+1, oo = 1e9;
typedef complex<double> pt;
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

struct event {
    pt p;
    int i; // id of segment
    bool start=true;
    bool operator<(const event& o) const {
        if(comp(p,{0,0})!=comp(o.p,{0,0})) {
            return comp(p,o.p);
        }
        auto tmp = cross(p,o.p);
        if(tmp) return tmp>0;
        return start<o.start;
    }
};
vector<pair<pt,pt>> segs;
struct cmp {
    bool operator()(int i, int j) const {
        auto [p,q] = segs[i];
        auto [a,b] = segs[j];
        ll tmp;
        if(a==p) {
            tmp = ccw(q,p,b);
        } else if(q==b) {
            tmp = -ccw(p,q,a);
        } else {
            if(cross(p,a)>0) {
                // use p as reference point
                tmp= ccw(q,p,a);
            } else tmp= ccw(p,a,b);
        }
        if(tmp==0) return i<j;
        return tmp>0;
        
    }
};
template<class P>
P lineInter(P s1, P e1, P s2, P e2) {
    auto d = cross(e1 - s1,e2 - s2);
    auto p = ccw(s2,e1, e2), q = ccw(s2,e2, s1);
    return (s1 * p + e1 * q) / d;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
    GD_INIT("warehouse.html");
    GD_LOG_TO_STDERR(false);
    #endif
    int n; cin >> n;
    vector<event> es;
    while(n--) {
        int c; cin >> c;
        vector<pt> pts(c);
        for(auto& i : pts) read(i);
        auto prv = pts.back();
        for(auto p : pts) {
            auto a = p, b = prv;
            #ifdef LOCAL
            GD_SEGMENT(a.X,a.Y,b.X,b.Y);
            #endif
            if(cross(a,b)!=0) {
                if(cross(a,b)<0) swap(a,b);
                es.push_back({a,(int)segs.size(),true});
                es.push_back({b,(int)segs.size(),false});
                segs.push_back({a,b});
            }
            prv=p;
        }
    }
    sort(all(es));
    n = es.size();
    multiset<int,cmp> s;
    { // prepare set
    vector<bool> vis(n);
    for(auto& e : es) {
        if(e.start and vis[e.i]) {
            s.insert(e.i);
        }
        vis[e.i]=true;
    }
    }
    long double ans=0;
    pt prv = es.back().p;

    for(auto& e : es) {
        { // update ans
        if(s.size()>=2 and cross(prv,e.p)>0) {
            auto [p,q] = segs[*s.begin()];
            auto [a,b] = segs[*next(s.begin())];
            #ifdef LOCAL
            GD_PAUSE();
            #endif
            
            // now add/subtract triangles
            auto add = [&](pt c, pt d, bool sgn=true) {
                auto f = lineInter(pt{0,0},e.p,c,d);
                auto e = lineInter(pt{0,0},prv,c,d);
                #ifdef LOCAL
                GD_TRIANGLE(e.X,e.Y,f.X,f.Y,0.,0.,sgn?"black:green":"black:red");
                #endif
                return cross(e,f)/2.;
            };
            ans+=add(a,b);
            ans-=add(p,q,false);
        }
        
        }
        if(e.start) {
            s.insert(e.i);
        } else {
            s.erase(e.i);
        }
        prv=e.p;
    }
    cout << setprecision(15) << ans << '\n';


}