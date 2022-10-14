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
        sz[a]+=sz[b];
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
bool overlap(pt p1,pt p2, pt q1, pt q2) {
    int tmp = sgn(ccw(p1,p2,q1));
    int tmp2 = sgn(ccw(p1,p2,q2));
    return tmp!=tmp2;
}
array<ll,2> get(pt p, pt q, pt v) {
    auto a = in(p,v), b = in(q,v);
    if(a>b) swap(a,b);
    return {a,b};
}
typedef pair<pt,pt> ppt;

bool intersects(pt p1,pt p2, pt q1, pt q2) {
    if(overlap(p1,p2,q1,q2) and overlap(q1,q2,p1,p2)) {
        return true;
    } 
    if(ccw(p1,p2,q2)==0 and ccw(p1,p2,q1)==0) {
        auto v = p2-p1;
        auto ps = get(p1,p2,v), qs = get(q1,q2,v);
        if(ps[0]>qs[0]) swap(ps,qs);
        return ps[1]>=qs[0];
    } else return false;
}
bool intersects(ppt p, ppt q) {
    return intersects(p.first,p.second,q.first,q.second);
}
int main() {
    int n,m; cin >> n >> m;
    vector<pt> b(n),r(m);
    for(auto& i : b) {
        read(i);
    }
    for(auto& i : r) {
        read(i);
    }
    int lo =0,hi = 1e8;
    while(lo<hi) {
        int mid =(lo+hi)/2;
        pt bv = {mid,-mid};
        pt rv = {mid,mid};
        
        DSU dsu(n+m);
        auto get = [&](int i) {
            if(i<n) return make_pair(b[i]-bv,b[i]+bv);
            else return make_pair(r[i-n]-rv,r[i-n]+rv);
        };
        for(int i=0;i<n;++i) {
            for(int j=i+1;j<n;++j) {
                if(intersects(get(i),get(j))) {
                    dsu.unite(i,j);
                }
            }
        }
        for(int i=0;i<m;++i) {
            for(int j=i+1;j<m;++j) {
                if(intersects(get(i+n),get(j+n))) {
                    dsu.unite(i+n,j+n);
                }
            }
        }
        
        vector<pi> es;
        for(int i=0;i<n;++i) for(int j=0;j<m;++j) {
            if(intersects(get(i),get(j+n))) {
                es.emplace_back(dsu.find(i),dsu.find(j+n));
            }
        }
        sort(all(es));
        es.erase(unique(all(es)),es.end());
        bool good=false;
        for(auto [i,j] : es) {
            if(!dsu.unite(i,j)) {
                good=true;
                break;
            }
        }
        if(good) hi = mid;
        else lo = mid+1;
    }
    if(lo>1e7) {
        cout << "Poor Sereja!\n";
    } else cout << lo << '\n';
}