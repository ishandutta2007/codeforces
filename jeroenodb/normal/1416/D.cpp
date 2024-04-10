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
struct DSU{
    vector<int> sz,parent;
    vector<set<int>> s;
    struct undo {
        int a, b;
    };
    vi checkpoints = {0};
    vector<undo> undos;
    int components;
    DSU(int n) {
        sz.assign(n,1);
        components = n;
        parent.resize(n);
        iota(all(parent),0);
        s.resize(n);
        for(int i=0;i<n;++i) s[i].insert(i);
    }
    int get(int a) {
        auto& ss = s[a];
        if(ss.empty()) return -1;
        auto tmp = prev(ss.end());
        int res = *tmp;
        ss.erase(tmp);
        return res;
    }
    void link(int a, int b) {
        components--;
        if(sz[a]<sz[b]) {
            swap(a,b);
        }
        undo u = {a,b};
        sz[a]+=sz[b];
        parent[b] = a;
        for(auto i : s[b]) s[a].insert(i);
        undos.push_back(u);
    }
    void rollback() {
        auto& u = undos.back();
        vi moved(all(s[u.b]));
        for(auto i : moved) {
            if(s[u.a].count(i)) s[u.a].erase(i);
            else s[u.b].erase(i);
        }
        parent[u.b]=u.b;
        undos.pop_back();
    }
    void tocheck() {
        while((int)undos.size()>checkpoints.back()) {
            rollback();
        }
        checkpoints.pop_back();
    }
    bool unite(int a, int b) {
        int pa = find(a),pb = find(b);
        if(pa!=pb) link(pa,pb);
        checkpoints.push_back(undos.size());
        return pa!=pb;
    }
    int find(int a) {
        while(a!=parent[a]) 
            a=parent[a];
        return a;
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // what do I need? Merging and unmerging
    int n,m,q; cin >> n >> m >> q;
    vi p(n); for(auto& i : p) cin >> i,--i;
    struct query {
        int t,v;
    };
    vector<array<int,2>> es(m);
    for(auto& [a,b] : es) {
        cin >> a >> b,--a,--b;
        a=p[a],b=p[b];
    }
    vector<query> qs(q);
    vector<bool> removed(m);
    for(auto& i : qs) {
        cin >> i.t >> i.v,i.v--;
        if(i.t==2) removed[i.v]=true;
        else i.v = p[i.v];
    }
    DSU dsu(n);
    for(int i=0;i<m;++i) if(!removed[i]){
        auto [a,b] = es[i];
        dsu.unite(a,b);
    } 
    reverse(all(qs));
    for(auto& i : qs) {
        if(i.t==2) {
            auto [a,b] = es[i.v];
            dsu.unite(a,b);
        }
    }
    reverse(all(qs));
    dsu.tocheck();
    for(auto& i : qs) {
        if(i.t==1) {
            auto j = dsu.find(i.v);
            cout << dsu.get(j)+1 << '\n';
        } else dsu.tocheck();
    }
}