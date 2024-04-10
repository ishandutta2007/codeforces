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
const int K=20;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m; cin >> n >> m;
    vvi adj(n);
    vi deg(n);
    for(int i=0;i<m;++i) {
        int u,v; cin >> u >> v;
        --u,--v;
        adj[u].push_back(v);
        deg[v]++;
    }
    vector<bitset<K>> reaches(n);
    int k=0;
    for(int i=0;i<n;++i) if(adj[i].empty()) {
        reaches[i][k]=true;
        k++;
    }
    auto dfs = [&](auto self, int at) {
        if(reaches[at].any()) return reaches[at];
        for(auto to : adj[at]) {
            reaches[at]|=self(self,to);
        }
        return reaches[at];
    };
    vector<bitset<K>> msks;
    for(int i=0;i<n;++i) if(deg[i]==0) {
        msks.push_back(dfs(dfs,i));
    }
    assert((int)msks.size()==k);
    for(int i=1;i<(1<<k)-1;++i) {
        bitset<K> to;
        for(int j=0;j<k;++j) if(1<<j & i) {
            to|=msks[j];
        }
        if(to.count()==__builtin_popcount(i)) {
            cout << "NO\n";
            exit(0);
        }
    }
    cout << "YES\n";
    


}