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
const int mxN = 1e6+2, oo = 1e9;
struct DS {
    vi p,ip,lb,prf,cnt;
    DS() {}
    DS(int n) {
        p.resize(n),ip.resize(n),lb.assign(n+2,n);
        cnt.assign(n,0);
        iota(all(p),0);
        iota(all(ip),0);
        lb[0]=0;
    }
    void insert(int i) {
        auto j = ip[lb[cnt[i]+1]-1];
        swap(ip[p[i]],ip[p[j]]);
        swap(p[i], p[j]);
        lb[cnt[i]+1]--;
        cnt[i]++;
    }
    void remove(int i) {
        auto j = ip[lb[cnt[i]]];
        swap(p[i],p[j]);
        swap(ip[p[i]],ip[p[j]]);
        lb[cnt[i]]++;
        cnt[i]--;
    }
    int query(int l, int k) {
        int where = lb[l]+ k-1;
        if(where>=(int)p.size()) 
            return -1;
        return ip[where]+1;
    }
};
int head[mxN];
int nxt[mxN],l[mxN],k[mxN],ans[mxN];
vi adj[mxN];
DS ds;
int a[mxN],n;
void dfs(int at) {
    ds.insert(a[at]);
    for(auto to : adj[at]) 
        dfs(to);
    for(int id = head[at];id;id=nxt[id]) {
        ans[id] = ds.query(l[id],k[id]);
    }
    ds.remove(a[at]);
}
void solve() {
    int q; cin >> n >> q;
    ds = DS(n);
    for(int i=0;i<n;++i) adj[i].clear(),head[i]=0;
    for(int i=0;i<n;++i) cin >> a[i],--a[i];
    for(int i=1;i<n;++i) {
        int p; cin >> p,--p;
        adj[p].push_back(i);
    }
    for(int i=1;i<=q;++i) {
        int v;
        cin >> v >> l[i] >> k[i];
        --v;
        nxt[i]=head[v];
        head[v]=i;
    }
    dfs(0);
    for(int i=1;i<=q;++i) {
        cout << ans[i] << ' ';
    } cout << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
}