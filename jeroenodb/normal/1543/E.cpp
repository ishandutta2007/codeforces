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
void solve() {
    int n; cin >> n;
    vi p(1<<n);
    vvi adj(1<<n);
    for(int i=0;i<n*(1<<n)/2;++i) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    {
    int id=1;
    for(int to : adj[0]) p[to] = id,id*=2;
    }
    vi d(1<<n,oo);
    vi q;
    auto process = [&](int at, int from) {
        auto di = d[from];
        if(d[at]==oo) {
            d[at]=di+1;
            q.push_back(at);
        }
        if(d[at]==d[from]+1) p[at]|=p[from];
    };
    d[0]=0;
    q.push_back(0);
    for(int i =0;i<q.size();++i) {
        auto at = q[i];
        for(auto to : adj[at]) process(to,at);
    }
    vi ip(1<<n);
    for(int i=0;i<1<<n;++i) ip[p[i]]=i;
    cout << ip << '\n';
    int pw=1;
    while(pw<n) pw*=2;
    if(pw!=n) {
        cout << "-1\n";
        return;
    }
    vi ans(1<<n);
    for(int i=0;i< (1<<n);++i) {
        int res=0;
        for(int j=0;j<n;++j) res^=((i>>j)&1)*j;
        ans[ip[i]]=res;
    }
    cout << ans << '\n';
}
int main() {
    int t; cin >> t;
    while(t--) solve();
}