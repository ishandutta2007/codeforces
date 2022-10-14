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
const int mxN = 5e5+1, oo = 1e9;
struct DS {
    list<int> layerxor; 
    int mex=0;
    vector<bool> have;
    void clear() {
        layerxor.clear(),have.clear(),mex=0;
        have.shrink_to_fit();
    }
    void updatemex() {
        // calculate mex
        while(have[mex]) mex++;
    }
    void extend(int i) {
        layerxor.push_front(i);
        have.push_back(false),have.push_back(false);
        have[i]=true;
    }
    void merge(DS& o) {
        while(layerxor.size()>o.layerxor.size()) 
            layerxor.pop_back();
        // xor layer

        auto it2 = o.layerxor.cbegin();
        for(auto it = layerxor.begin();it!=layerxor.end();++it,++it2) {
            *it ^= *it2;
        }
        if(have.size()<o.have.size()) {
            swap(have,o.have);
            for(auto i : o.layerxor) have[i]=false;
        } else fill(all(have),0);
        for(auto i : layerxor) have[i]=true;
        mex=0;
    }
};
vi adj[mxN];
DS dp[mxN];
void dfs(int at) {
    dp[at].clear();
    bool firstchild=true;
    for(int to : adj[at]) {
        dfs(to);
        if(firstchild) swap(dp[at],dp[to]);
        else {
            dp[at].merge(dp[to]);
        }
        firstchild=false;
    }
    for(auto to : adj[at]) {
        dp[to].clear();
    }
    if(firstchild) dp[at].extend(0);
    dp[at].updatemex();
    dp[at].extend(dp[at].mex);
}
void solve() {
    int n; cin >> n;
    for(int i=0;i<=n;++i) adj[i].clear();
    for(int i=1;i<=n;++i) {
        int p; cin >> p;
        adj[p].push_back(i);
    }
    int ans=0;
    for(auto root : adj[0]) {
        dfs(root);
        ans^=*dp[root].layerxor.begin();
    }
    if(ans==0) cout << "NO\n";
    else cout << "YES\n";

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; 
    while(t--) solve();
}