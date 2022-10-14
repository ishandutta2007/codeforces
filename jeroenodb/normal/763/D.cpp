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
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
template<class I> I rnd(I l,I r){return std::uniform_int_distribution<I>(l,r)(rng);}
const uint64_t RANDOM = rnd(0ULL,-1ULL);
constexpr uint64_t splitmix64(uint64_t x) {
    x^=RANDOM;
    // http://xorshift.di.unimi.it/splitmix64.c
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
}
typedef uint64_t DP;

DP up(DP d) {
    return splitmix64(d);  
}
vvi adj;

vector<DP> dp;
unordered_map<DP,int> subs;
int cur=0;
void add(DP v) {
    cur+=!(subs[v]++);
}
void rem(DP v) {
    cur-=!(--subs[v]);
}
void dfs(int at=0,int from=-1) {
    for(int to : adj[at]) if(to!=from) {
        dfs(to,at);
        dp[at]+=up(dp[to]);
    }
    
    add(dp[at]);
}

pi ans= {-1,-1};
void dfs2(int at=0,int from=-1) {
    // change parent DP
    if(from!=-1) {
        rem(dp[from]);
        dp[from]-=up(dp[at]);
        add(dp[from]);
        rem(dp[at]);
        dp[at]+=up(dp[from]);
        add(dp[at]);
    }
    ans = max(ans,{cur,at});

    for(auto to : adj[at]) if(to!=from) {
        dfs2(to,at);
    }
    if(from!=-1) {
        rem(dp[at]);
        dp[at]-=up(dp[from]);
        add(dp[at]);
        rem(dp[from]);
        dp[from]+=up(dp[at]);
        add(dp[from]);
    }
}
int main() {
    int n; cin >> n;
    adj.resize(n);
    for(int i=0;i<n-1;++i) {
        int u,v; cin >> u >> v;
        --u,--v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dp.resize(n);
    dfs(0);
    dfs2(0);
    cout << ans.second+1 << '\n';
}