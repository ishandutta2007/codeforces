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
    int add() {
        int at = parent.size();
        parent.push_back(at);
        sz.push_back(1);
        return at;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    map<int,int> mp;
    DSU dsu(n);
    vi id(n), where(n); iota(all(id),0);
    auto addMp = [&](int w,int i) {
        auto it = mp.find(w);
        if(it!=mp.end()) dsu.unite(it->second,i);
        mp[w]=i;
        where[dsu.find(i)]=w;
    };
    for(int i=0;i<n;++i) {
        int a; cin >> a;
        addMp(a,i);
    }
    int q; cin >> q;
    while(q--) {
        int t; cin >> t;
        if(t==1) {
            int k,w; cin >> k >> w;
            --k;
            where.push_back(w);
            id[k]=dsu.add();
            addMp(w,id[k]);
        } else if(t==2) {
            int k; cin >> k,--k;
            cout << where[dsu.find(id[k])] << '\n';
        } else if(t==3) {
            int l,r; cin >> l >> r;
            int m = (l+r)/2;
            int tomerge=-1;
            for(auto it = mp.lower_bound(l);it!=mp.end() and it->first<=m;it=mp.erase(it)) {
                if(tomerge!=-1) dsu.unite(it->second,tomerge);
                tomerge=it->second;
            }
            if(tomerge!=-1) addMp(l-1,tomerge);
            tomerge=-1;
            for(auto it = mp.upper_bound(m);it!=mp.end() and it->first<=r;it=mp.erase(it)) {
                if(tomerge!=-1) dsu.unite(it->second,tomerge);
                tomerge=it->second;
            }
            if(tomerge!=-1) addMp(r+1,tomerge);
        }
    }
}