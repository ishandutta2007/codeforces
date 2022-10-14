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
const int mxN = 1e5+10, oo = 1e9;
ll dp[mxN][2];
int l[mxN],r[mxN];
vi adj[mxN];
void dfs(int at, int from=-1) {
    auto c = dp[at];
    c[0]=c[1]=0;
    for(int to: adj[at]) if(to!=from) {
        dfs(to,at);
        auto t = dp[to];
        c[0]+=max(t[0]+abs(l[at]-l[to]),t[1]+abs(l[at]-r[to]));
        c[1]+=max(t[0]+abs(r[at]-l[to]),t[1]+abs(r[at]-r[to]));
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        
        for(int i=0;i<n;++i) {
            cin >> l[i] >> r[i];
            adj[i].clear();
        }
        for(int i=0;i<n-1;++i) {
            int a,b; cin >> a >> b,--a,--b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        dfs(0);
        cout << max(dp[0][0],dp[0][1]) << '\n';
        // tree dp?
    }
}