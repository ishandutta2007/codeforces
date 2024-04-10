#include <bits/stdc++.h>
using namespace std;
using i64 = int_fast64_t;
using pii = pair<int,int>;
template <class T> constexpr T inf = numeric_limits<T>::max() / 2;
#define fir first
#define sec second
#define all(v) begin(v),end(v)

i64 n,ans;
vector<int> g[500050];
i64 sz[500050];
i64 dp[500050];
i64 pat[500050];

template <class K>
struct CHT {
    struct line {
        K slop,incp;
        line(K a, K b) : slop(a),incp(b) {}
        K get(int_fast64_t x) const { return slop * x + incp; }
    };
    struct node {
        line ln;
        node *left,*right;
        node(line l) : ln(l),left(nullptr),right(nullptr) {}
        ~node() { delete left; delete right; }
        K get(int_fast64_t x) const { return ln.get(x); }
    };

    const K x_min,x_max;
    size_t node_cnt;
    node *root;
    CHT(int_fast64_t x_min_ = -1, int_fast64_t x_max_ = 10001) : x_min(x_min_),x_max(x_max_),root() {}
    ~CHT() { delete root; }
    size_t size() const { return node_cnt; }
    bool empty() const { return !root; }

    node *insert(node *p, int_fast64_t low, int_fast64_t high, line l) {
        if(!p) return ++node_cnt, new node(l);
        if (p->get(low) <= l.get(low) && p->get(high) <= l.get(high)) return p;
        if (p->get(low) >= l.get(low) && p->get(high) >= l.get(high)) {
            p->ln = l;
            return p;
        }
        int_fast64_t mid = (low + high) / 2;
        if (p->get(mid) > l.get(mid)) swap(p->ln,l);
        if (p->get(low) >= l.get(low)) p->left = insert(p->left,low,mid,l);
        else p->right = insert(p->right,mid + 1,high,l);
        return p;
    }

    void insert(K a, K b) { root = insert(root,x_min,x_max,line(a,b)); }

    K query(node *p, int_fast64_t low, int_fast64_t high, int_fast64_t x) {
        if(!p) return inf<K>;
        if(low == high) return p->get(x);
        int_fast64_t mid = (low + high) / 2;
        if (x <= mid) return min(p->get(x), query(p->left,low,mid,x));
        return min(p->get(x),query(p->right,mid + 1,high,x));
    }

    K query(int_fast64_t x) { return query(root,x_min,x_max,x); }
};

void dfs(int v,int p) {
    sz[v]=1;
    for(int u:g[v]) {
        if(u!=p) {
            dfs(u,v);
            pat[v]+=sz[v]*sz[u];
            pat[v]+=pat[u];
            sz[v]+=sz[u];
        }
    }

    for(int u:g[v]) {
        if(u==p) continue;
        i64 k=sz[v]-sz[u];
        dp[v]=min(dp[v],dp[u]+k*(k-1));
    }

    if(sz[v]==1) {
        dp[v]=0;
    }

    // sort(all(g[v]),[](int a,int b)->bool{return sz[a]<sz[b];});
    CHT<i64> _cht(-1,5e5+1);

    for(int u:g[v]) {
        if(u==p) continue;
        i64 x=n-sz[u];
        if(!_cht.empty()) ans=min(ans,_cht.query(x)+dp[u]+x*(x-1));
        _cht.insert(-sz[u]*2,dp[u]+sz[u]*(sz[u]+1));
    }

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n;
    for(int i=1; i<n; ++i) {
        int u,v; cin>>u>>v;
        u--,v--;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    fill(all(dp),1e18);
    ans=1e18;
    dfs(0,-1);
    // for(int i=0; i<n; ++i) cerr<<i<<" "<<dp[i]<<endl;
    ans=min(ans,dp[0]);
    ans=pat[0]+(n*(n-1)-ans)/2;
    cout<<ans<<endl;
}