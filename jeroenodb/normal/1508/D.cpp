#include "bits/stdc++.h"
// #include "geodeb.h"
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
void read(pt& p) {
    int a,b; cin >> a >> b;
    p = {a,b};
}
bool comp(pt a, pt b) {
    return a.X<b.X or (a.X==b.X and a.Y<b.Y);
}
struct DSU{
    vector<int> sz,parent;
    int components;
    DSU(int n) {
        sz.assign(n,1);
        components = n;
        parent.resize(n);
        iota(all(parent),0);
    }
    void link(int a, int b) {
        components--;
        if(sz[a]<sz[b]) {
            swap(a,b);
        }
        sz[a] = max(sz[a],sz[b]+1);
        parent[b] = a;
    }
    bool unite(int a, int b) {
        int pa = find(a),pb = find(b);
        if(pa!=pb) link(pa,pb);
        return pa!=pb;
    }
    int find(int a) {
        if(a==parent[a]) return a;
        return parent[a] = find(parent[a]);
    }
};
int main() {
    // GD_INIT("d.html");
    int n; cin >> n;
    vector<pt> pts(n);
    vi a(n), cyc(n,-1);
    vector<bool> realcycle(n);
    for(int i=0;i<n;++i) {
        read(pts[i]);
        // GD_POINT(pts[i].X, pts[i].Y);
        cin >> a[i]; a[i]--;
    }
    int numcycle = 0;
    vi order;
    for(int i=0;i<n;++i) {
        int at = i;
        bool gotcyc = false;
        while(cyc[at]==-1) {
            cyc[at] = numcycle;
            at = a[at];
            gotcyc=true;
            if(at!=a[at]) {
                realcycle[numcycle] = true;
            } else {
                // GD_POINT(pts[i].X, pts[i].Y,"red");
                break;
            }
            order.push_back(at);
        }
        numcycle+=gotcyc;
    }
    if(order.empty()) {
        cout << "0\n";
        exit(0);
    }
    sort(all(order),[&](int c,int d) {return comp(pts[c], pts[d]);});
    int pivot = order[0];
    order.erase(order.begin());
    sort(all(order), [&](int c,int d) {return ccw(pts[pivot],pts[c],pts[d])>0;});

    DSU dsu(numcycle);

    vector<pi> ans;
    auto add = [&]( int c, int d) {
        // GD_SEGMENT(pts[c].X, pts[c].Y, pts[d].X, pts[d].Y) << c+1 << ' ' << d+1;
        // GD_PAUSE();
        ans.emplace_back(c+1,d+1);
        swap(a[c],a[d]);
    };
    int prev = order[0];
    for(int i=1;i<(int)order.size();++i) {
        int cur = order[i];
        int c1 = cyc[cur], c2 = cyc[prev];
        if(realcycle[c1] and realcycle[c2]) {
            if(dsu.unite(c1,c2)) {
                add(cur,prev);
            }
        }
        prev = cur;
    }
    // GD_POINT(pts[pivot].X, pts[pivot].Y, "blue");
    // GD_PAUSE() << "Pivoting!";
    while(a[pivot]!=pivot) {
        add(pivot,a[pivot]);
    }
    cout << ans.size() << '\n';
    for(auto& p : ans) {
        cout << p.first << ' ' << p.second << '\n';
    }

}