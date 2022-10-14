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
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q,s,d;
    cin >> n >> q >> s >> d;
    --s;
    vi a(n); for(auto& i: a) cin >> i;
    struct el {
        int need,to;
        bool operator<(const el& o) const {
            return need>o.need;
        }
    };
    priority_queue<el> pq;
    map<int,int> alive;
    alive[-oo]=-1;
    alive[oo]=-2;
    for(int i=0;i<n;++i) alive[a[i]]=i;

    auto fix = [&](int i, bool special=false, int extra=0) {
        for(int x : {a[i]+d,a[i]-d, a[i]}) if( (a[i]==x)==special) {
            
            auto it = alive.lower_bound(x);
            pq.push( {it->first-x + extra,it->second});
            --it;
            pq.push({x-it->first + extra,it->second});
        }
    };
    
    pq.push({0,s});
    struct query {
        int i,k,id;
        bool operator<(const query& o) {
            return k<o.k;
        }
    };
    vector<query> qs(q);
    for(int i=0;i<q;++i) {
        cin >> qs[i].i >> qs[i].k;
        qs[i].i--;
        qs[i].id=i;
    }
    sort(all(qs));
    
    vector<bool> vis(n);
    vector<bool> ans(q);
    for(auto& qu : qs) {
        while(!pq.empty() and pq.top().need<=qu.k) {
            auto e = pq.top(); pq.pop();
            if(!vis[e.to]) {
                vis[e.to]=true;
                alive.erase(a[e.to]);
                fix(e.to);
                if(e.to!=s) fix(e.to,true,e.need);
            }
        }
        ans[qu.id]=vis[qu.i];
    }
    for(auto i : ans)  {
        if(i) cout << "Yes\n";
        else cout << "No\n";
    }
    
}