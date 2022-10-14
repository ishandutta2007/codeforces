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
const int mxN = 1e5+1, oo = 2e9 + 1;
typedef complex<long long> pt;
#define X real()
#define Y imag()
const pt dir4[] = {{1,0},{0,1},{-1,0},{0,-1}};
const pt dir8[] = {{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};
const pt hdir[] = {{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};
bool cmp1(pt p, pt q) {
    return make_pair(p.X,p.Y)<make_pair(q.X,q.Y);
}
bool cmp2(pt p, pt q) {
    return make_pair(p.Y,p.X)<make_pair(q.Y,q.X);
}
int norm(pt p) {
    return abs(p.X)+abs(p.Y);
}
void read(pt& p) {
    int a, b; cin >> a >> b;
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
int main() {
    int n; cin >> n;
    vector<pt> pts(n);
    vi x,y;
    for(auto& i : pts) read(i),x.push_back(i.X),y.push_back(i.Y);
    sort(all(pts),cmp1);
    sort(all(x));
    x.erase(unique(all(x)),x.end());
    sort(all(y));
    y.erase(unique(all(y)),y.end());
    vi yne(n); iota(all(yne),0);
    sort(all(yne),[&](int i, int j) {return cmp1(pts[i],pts[j]);});
    auto xne = yne;
    sort(all(xne),[&](int i, int j){return cmp2(pts[i],pts[j]);});

    vector<array<vi::iterator,2>> cands;
    vector<pt> cs;
    for(auto xx : x) for(auto yy : y) {
        pt p = {xx,yy};
        if(binary_search(all(pts),p,cmp1)) continue;
        cs.push_back(p);
        auto xit = upper_bound(all(xne),p,[&](pt q,int j) {return cmp2(q,pts[j]);});
        auto yit = upper_bound(all(yne),p,[&](pt q,int j) {return cmp1(q,pts[j]);});
        cands.push_back({xit,yit});
    }

    DSU dsu(n);
    
    auto good = [&](int t) {
        auto connected = [&](pt p,pt q) {
            if(p.X!=q.X and p.Y!=q.Y) return false;
            return norm(q-p)<=t;
        };
        dsu = DSU(n);
        for(int i=0;i<n;++i) {
            auto xit = upper_bound(all(xne),i,[&](int ii,int j) {return cmp2(pts[ii],pts[j]);});
            auto yit = upper_bound(all(yne),i,[&](int ii,int j) {return cmp1(pts[ii],pts[j]);});
            // find lower neighbour
            if(xit!=xne.end()) {
                if(connected(pts[*xit],pts[i])) dsu.unite(*xit,i);
            }
            if(yit!=yne.end()) {
                if(connected(pts[*yit],pts[i])) dsu.unite(*yit,i);
            }
        }
        if(dsu.components==1) return true;
        if(dsu.components>4) return false;
        auto check = [&](auto xit, auto yit, pt at) {
            set<int> comps;
            if(xit!=xne.end()) {
                if(connected(pts[*xit],at)) {
                    comps.insert(dsu.find(*xit));
                }
            }
            if(xit!=xne.begin()) {
                if(connected(pts[*prev(xit)],at)) {
                    comps.insert(dsu.find(*prev(xit)));
                }
            }
            if(yit!=yne.end()) {
                if(connected(pts[*yit],at)) {
                    comps.insert(dsu.find(*yit));
                }
            }
            if(yit!=yne.begin()) {
                if(connected(pts[*prev(yit)],at)) {
                    comps.insert(dsu.find(*prev(yit)));
                }
            }
            return (dsu.components==(int)comps.size());
        };
        for(int i=0;i<(int)cands.size();++i) {
            auto [xit,yit] = cands[i];
            if(check(xit,yit,cs[i])) return true;
        }
        for(int i=0;i<n;++i) {
            for(auto d : {pt{0,t},pt{t,0}}) {
                pt p = pts[i]+d;
                auto xit = upper_bound(all(xne),p,[&](pt q,int j) {return cmp2(q,pts[j]);});
                auto yit = upper_bound(all(yne),p,[&](pt q,int j) {return cmp1(q,pts[j]);});
                if(check(xit,yit,p)) return true;
            }
        }
        return false;
    };
    ll lo = 1, hi  = oo;
    while(lo<hi) {
        int mid = (lo+hi)/2;
        if(good(mid)) {
            hi = mid;
        } else lo = mid+1;
    }
    if(lo==oo) lo=-1;
    cout << lo << '\n';

}