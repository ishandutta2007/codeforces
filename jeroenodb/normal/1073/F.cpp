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
typedef size_t sz_t;
template<sz_t N, sz_t M> array<int,2ULL+N+M> join(const array<int,2ULL+N>& a, const array<int,2ULL+M>& b) {
    if constexpr(N<M) {
        return join<M,N>(b,a);
    }
    array<int,2+N+M> res;
    res[0] = a[0]+b[0], res[1] = a[1]+b[1];
    copy(a.begin()+2, a.end(), res.begin()+2);
    copy(b.begin()+2, b.end(), res.begin()+2+N);
    return res;
}
struct DP {
    array<int,6> best4 = {-oo,-oo};
    array<int,5> best3 = {-oo,-oo};
    array<int,4> best2 = {-oo,-oo};
    array<int,3> best1 = {-oo,-oo};
    DP() {}
    void update(int i) {
        if(best1[0]<0) best1 = {0,0,i};
    }
    void up() {
        best3[1]+=2;
        best2[1]+=2,best2[0]+=2;
        best1[1]+=1;
    }
    void merge(const DP& o) {
        best4=max({best4,join<1,3>(best1, o.best3), join<2,2>(best2,o.best2), join<3,1>(best3,o.best1), o.best4 });
        best3 = max({best3,join<1,2>(best1,o.best2), join<2,1>(best2,o.best1),o.best3});
        best2 = max({best2, join<1,1>(best1,o.best1), o.best2});
        best1 = max(best1,o.best1);
    }
};
DP dp[mxN];
void dfs(int at, int from) {
    for(int to : adj[at]) if(to!=from) {
        dfs(to,at);
        dp[to].up();
        dp[at].merge(dp[to]);
    }
    dp[at].update(at);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    for(int i=0;i<n-1;++i) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }   
    dfs(1,0);
    auto v = dp[1].best4;
    swap(v[2],v[4]);
    cout << v[2] << ' ' << v[3] << '\n';
    cout << v[4] << ' ' << v[5] << '\n';
}