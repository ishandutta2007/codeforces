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
vvi adj;
vi h,a;
ll ans;
pair<ll,ll> dfs(int at, int from=-1) {
    int bal=0;
    ll start=0;
    vector<ll> changes;
    for(auto to : adj[at]) if(to!=from) {
        auto [cf,cto] = dfs(to,at);
        if(h[to]<h[at]) {
            // only can go to:
            bal--;
            start+=cto;
        } else if(h[to]>h[at]) {
            // only can go from:
            bal++;
            start+=cf;
        } else {
            // both directions are fine:
            bal++;
            start+=cf;
            changes.push_back(cto-cf);
        }
    }
    sort(all(changes));
    ll cf=1e18,cto = 1e18;
    ans=1e18; // 0 balance at the end
    auto consider = [&]() {
        cf = min(cf,start+a[at]*ll(  (adj[at].size()+abs(bal-1))/2)); // add -1 balance, because of extra outgoing edge
        cto = min(cto,start+a[at]*ll(  (adj[at].size()+abs(bal+1))/2)); // add +1 balance
        ans = min(ans,start+a[at]*ll(  (adj[at].size()+abs(bal))/2)); // If this were the root of the tree
    };
    for(auto& ch : changes) {
        consider();
        start+=ch;
        bal-=2;
    }
    consider();
    return {cf,cto};
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    adj.resize(n),h.resize(n),a.resize(n);
    for(auto& i : a) cin >> i;
    for(auto& i : h) cin >> i;
    for(int i=1;i<n;++i) {
        int u,v; cin >> u >> v,--u,--v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0);
    cout << ans << '\n';

}