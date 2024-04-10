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


struct segtree {
    int a=0,b=3e5;
    segtree *l = NULL, *r = NULL;
    
    int sz=0,best=oo+1;
    void pull() {
        sz=l->sz+r->sz;
        best = min(l->best,r->best-l->sz);
    }
    void prepare() {
        if(!l) {
            int mid = (a+b)/2;
            l = new segtree{a,mid}, r = new segtree{mid+1,b};

        }
    }
    void update(int x) {
        if(x<a or b<x) return;
        if(x==a and x==b) {
            best=a-sz++;
            return;
        }
        l->update(x);
        r->update(x);
    }
};
int main() {
    int n,m; cin >> n >> m;
    vvi rev(n);
    vi deg(n);
    for(int i=0;i<m;++i) {
        int u,v; cin >> u >> v;
        --u,--v;
        rev[v].push_back(u);
        deg[u]++;
    }
    vi d(n,oo);
    struct el {
        int at,d;
        bool operator<(const el& o) const {
            return d>o.d;
        };
    };
    priority_queue<el> pq;
    pq.push({n-1,0});
    d[n-1]=0;
    while(!pq.empty()) {
        auto e = pq.top(); pq.pop();
        if(e.d!=d[e.at]) continue;
        for(auto to : rev[e.at]) {
            int tmp = e.d + deg[to]--;
            if(tmp<d[to]) {
                d[to]=tmp;
                pq.push({to,tmp});
            }
        }
    }
    cout << d[0] << '\n';


}