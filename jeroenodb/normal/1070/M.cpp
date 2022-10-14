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
vector<pt> pts;
vector<bool> col;
vi conn;
vector<pi> es;
auto convexhull(vi ord) {
    vi hull = {ord[0]};
    int n = ord.size();
    for(int phase = 0;phase <2;++phase) {
        int last = hull.size();
        for(int i=1;i<n;++i) {
            auto& p = pts[ord[i]];
            while(hull.size()>=2 and (int)hull.size()!=last and ccw(pts[hull[hull.size()-2]], pts[hull.back()],p) >= 0) {
                hull.pop_back();
            }
            hull.push_back(ord[i]);
        }
        if(phase==0) reverse(all(ord));
    }
    assert(hull.front() == hull.back());
    hull.pop_back();
    return hull;
}
void rec(vi ord) { 
    // this function is correct by induction on a+b.
    // makes a correct spanning tree of the points in ord
    // precondition: ord is sorted with comp() and all conditions from statement hold
    if(ord.size()==1) return;
    if(col[ord[0]]!=col[ord.back()]) {
        // two different colors on the convex hull
        // make a connection between two opposite colored points on the hull
        auto h = convexhull(ord);
        for(int i=0;i+1<(int)h.size();++i) {
            if(col[h[i]]!=col[h[i+1]]) {
                int a = h[i], b = h[i+1];
                if(a>b) swap(a,b);
                es.push_back({a,b});
                if(conn[b]==1) {
                    // delete b
                    ord.erase(find(all(ord),b));
                    rec(ord);
                } else {
                    ord.erase(find(all(ord),a));
                    conn[b]--;
                    rec(ord);
                    conn[b]++;
                }
                return;
            }
        }
    } else if(!col[ord[0]] and !col[ord.back()]) {
        // two berland points on the edges
        int pref=0, n = ord.size();
        for(int i=0;i<n;++i) {
            if(col[ord[i]]) pref--;
            if(!col[ord[i]]) pref+=conn[ord[i]]-1;
            if(pref<0) {
                vi ord2(ord.begin(),ord.begin()+i+1);
                rec(ord2);
                ord2 = vi(ord.begin()+i,ord.end());
                rec(ord2);
                return;
            }
        }
    } else {
        assert(col[ord[0]] and col[ord.back()]);
        // A points on edges, do an intermediate value argument
        int pref=0;
        int n = ord.size();
        for(int i=0;i<n;++i) {
            if(col[ord[i]]) pref--;
            if(!col[ord[i]]) pref+=conn[ord[i]]-1;
            if(pref>=0) {
                int ori = conn[ord[i]];
                // want to make pref =-1
                conn[ord[i]]-=pref+1;
                vi ord2(ord.begin(),ord.begin()+i+1);
                rec(ord2);
                conn[ord[i]] = ori-conn[ord[i]];
                ord2 = vi(ord.begin()+i,ord.end());
                rec(ord2);
                return;
            }
        }
    }
}
void solve() {
    int a,b; cin >> a >> b;
    int n = a+b;
    pts.assign(a+b,{});
    col.assign(n,0);
    conn.assign(n,-1);
    for(int i=a;i<n;++i) cin >> conn[i];
    for(int i=0;i<n;++i) {
        read(pts[i]);
    }
    for(int i=0;i<a;++i) col[i]=1;
    
    vi ord(n);
    iota(all(ord),0);
    sort(all(ord),[&](int i, int j) {return comp(pts[i],pts[j]);});
    es.clear();
    rec(ord);
    cout << "YES\n";
    for(auto [i,j] : es) {
        i++,j+=1-a;
        cout << j << ' ' << i << '\n';
    }
    
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
}