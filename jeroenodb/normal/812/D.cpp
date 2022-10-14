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
vi adj[mxN];
int sz[mxN], in[mxN], out[mxN],cnt=0;
void dfs(int at) {
    sz[at]=1;
    in[at] = cnt++;
    for(int to : adj[at]) {
        dfs(to);
        sz[at]+=sz[to];
    }
    out[at] = cnt;
}
bool insub(int u, int c) {
    return in[u] <= in[c] and in[c] < out[u];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,k,q; cin >> n >> m >> k >> q;
    vi last(m+1),par(n+1);
    for(int i=0;i<k;++i) {
        int x,y; cin >> x >> y;
        if(par[x]) continue;
        par[x] = last[y];
        if(par[x]) adj[par[x]].push_back(x);
        last[y]= x;
    }
    for(int i=1;i<=n;++i) {
        if(par[i]==0) dfs(i);
    }
    for(int i=0;i<q;++i) {
        int x,y; cin >> x >> y;
        if(!last[y]) {
            cout << "0\n";
        } else {
            int to = last[y];
            if(insub(x,to)) {
                cout << sz[x] << '\n';
            } else cout << "0\n";
        }
    }
}