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
    struct agg {
        int mx=-1,mx2=-1,es=0;
    };
    vector<agg> ags;
    int components;
    DSU(int n) {
        sz.assign(n,1);
        components = n;
        parent.resize(n);
        iota(all(parent),0);
        ags.resize(n);
        for(int i=0;i<n;++i) {
            ags[i].mx=i;
        }

    }
    void update(int i, int m) {
        if(m>=ags[i].mx) {
            ags[i].mx2=ags[i].mx;
            ags[i].mx=m;
        } else ags[i].mx2=max(ags[i].mx2,m);
    }
    void link(int a, int b) {
        components--;
        if(sz[a]<sz[b]) {
            swap(a,b);
        }
        sz[a] +=sz[b];
        update(a,ags[b].mx);
        update(a,ags[b].mx2);
        ags[a].es+=ags[b].es+1;
        parent[b] = a;
    }
    bool unite(int a, int b) {
        int pa = find(a),pb = find(b);
        if(pa!=pb) link(pa,pb);
        else ags[pa].es++;
        return pa!=pb;
    }
    int find(int a) {
        if(a==parent[a]) return a;
        return parent[a] = find(parent[a]);
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    vi coords; coords.reserve(2*n);
    vector<pi> es(n);
    for(auto& [a,b] : es) {
        cin >> a >> b;
        coords.push_back(a);
        coords.push_back(b);
    }
    sort(all(coords));
    coords.erase(unique(all(coords)),coords.end());
    DSU dsu(coords.size());
    for(auto& [a,b] : es) {
        a=lower_bound(all(coords),a)-coords.begin();
        b=lower_bound(all(coords),b)-coords.begin();
        dsu.unite(a,b);
    }
    bool good=true;
    int ans = 0;
    for(int i=0;i<coords.size();++i) {
        if(dsu.find(i)==i) {
            if(dsu.ags[i].es>dsu.sz[i]) {
                good=false;
                break;
            } else if(dsu.ags[i].es==dsu.sz[i]) {
                ans = max(ans,coords[dsu.ags[i].mx]);
            } else ans = max(ans,coords[dsu.ags[i].mx2]);
        }
    }
    if(good) cout << ans << '\n';
    else cout << "-1\n";
}