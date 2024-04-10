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
const int mxN = 2e5+1, oo = 1e9;
vi adj[mxN];
struct DP {
    int mx=0,free=0;
    bool miss=false;
    int gain() {return mx+free;}
    friend DP root(DP res, bool good) { 
        // given the children's combined DP and if the root is good or not, calculate the root's DP.
        if(!good) return DP{0,0,true};
        res.free++;
        if(!res.miss) return res; // everything stays free to grab
        res.mx+=res.free; // nothing is free to grab
        res.free=0;
        return res;
    }
};
DP comb(DP a, const DP& b) { // combine the DP's of two children
    a.free+=b.free;
    a.mx = max(a.mx,b.mx);
    a.miss=a.miss or b.miss;
    return a;
}
int a[mxN];
bool mygood[mxN];
DP dp[mxN]; // DP for subtree rooted at u
void dfs(int at, int from=-1) { 
    dp[at]=DP();
    for(int to : adj[at]) if(to!=from) {
        dfs(to,at);
        dp[at] = comb(dp[at],dp[to]);
    }
    dp[at] = root(dp[at], mygood[at]);
}
vector<DP> suf[mxN];
DP pref[mxN];
bool found = false;
int n,k;
void dfs2(int at, int from=-1, int id=0) { // second DFS for rerooting DP
    // make suffix sums
    suf[at].clear();
    DP supertree = {};
    if(from!=-1) supertree = root(comb(pref[from],suf[from][id+1]),mygood[from]);
    for(int to : adj[at]) if(to!=from) {
        suf[at].push_back(dp[to]);
    }
    suf[at].push_back(supertree);
    partial_sum(suf[at].rbegin(),suf[at].rend(),suf[at].rbegin(),comb);
    pref[at] = DP();

    int i=0;
    for(int to : adj[at]) if(to!=from) {
        dfs2(to,at,i++);
        pref[at] = comb(pref[at],dp[to]);
    }
    // check for this root the score
    auto rootedtree = root(comb(pref[at],supertree),mygood[at]);
    found |= rootedtree.gain()>=k;
}
bool atleast(int mid) {
    found = false;
    for(int i=0;i<n;++i) mygood[i] = a[i]>=mid;
    dfs(0);
    dfs2(0);
    return found;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    for(int i=0;i<n;++i) {
        cin >> a[i];
    }
    for(int i=1;i<n;++i) {
        int u,v; cin >> u >> v,--u,--v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vi b(a,a+n);
    sort(all(b));
    int lo=0,hi=n-1;
    while(lo<hi) {
        int mid = (lo+hi+1)/2;
        if(atleast(b[mid])) lo = mid;
        else hi = mid-1;
    }
    cout << b[lo];
}