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
int ans = 0;
struct DSU{
    struct info {
        int cnt[2] = {1,0};
        bool flip=false; // locked
        bool locked=false;
        int cost() {
            if(!locked) return min(cnt[0],cnt[1]);
            return cnt[!flip];
        }
    };
    vector<info> v;
    vector<int> sz,parent;
    int components;
    DSU(int n) {
        sz.assign(n,1);
        components = n;
        parent.resize(n);
        v.resize(n);
        iota(all(parent),0);
    }
    void link(int a, int b, bool flip=false) {
        components--;
        if(sz[a]<sz[b]) {
            swap(a,b);
        }
        ans-=v[a].cost()+v[b].cost();
        if(v[b].locked) {
            v[a].locked=true;
            v[a].flip = flip ^ v[b].flip;
        }
        v[b].flip=flip;
        v[a].cnt[0] += v[b].cnt[flip], v[a].cnt[1] += v[b].cnt[!flip];
        sz[a]+=sz[b];
        parent[b] = a;
        ans+=v[a].cost();
    }
    void lock(int i, bool f) {
        auto [p,pf] = find(i);
        ans-=v[p].cost();
        v[p].locked=true;
        v[p].flip=f^pf;
        ans+=v[p].cost();
    }
    bool unite(int a, int b, bool flip=false) {
        auto [pa,fa] = find(a);
        auto [pb,fb] = find(b);
        if(pa!=pb) link(pa,pb,fa^fb^flip);
        return pa!=pb;
    }
    pair<int,bool> find(int a) {
        bool flip = false;
        while(parent[a]!=a) {
            flip ^= v[a].flip;
            a = parent[a];
        }
        return {a,flip};
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k; cin >> n >> k;
    DSU dsu(k);
    string s; cin >> s;
    vvi subs(n);
    for(int i=0;i<k;++i) {
        int c; cin >> c;
        while(c--) {
            int x; cin >> x,--x;
            subs[x].push_back(i);
        }
    }
    for(int i=0;i<n;++i) {
        
        if(subs[i].size()==1) {
            dsu.lock(subs[i][0], s[i]!='1');
        } else if(!subs[i].empty()) {
            dsu.unite(subs[i][0],subs[i][1],s[i]!='1');
        }
        cout << ans << '\n';
    }

}