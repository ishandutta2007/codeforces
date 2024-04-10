#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;

int N, K;
vector<vector<int>> to;
vector<vector<lint>> dp;
vector<lint> depth;
void dfs1(int now, int prv)
{
    dp[now].resize(K);
    depth[now] = 0;
    if (prv >= 0) depth[now] = depth[prv] + 1;
    for (auto nxt : to[now]) if (nxt != prv)
    {
        dfs1(nxt, now);
        REP(i, K) dp[now][(i + 1) % K] += dp[nxt][i];
    }
    dp[now][0]++;
}

lint ltot;
lint ret;
void dfs2(int now, int prv, array<lint, 5> cnt)
{
    ret += ltot;
    for (auto nxt : to[now]) if (nxt != prv)
    {
        array<lint, 5> cm;
        REP(i, K) cm[i] = cnt[i];
        REP(i, K)
        {
            cm[(i + 1) % K] -= dp[nxt][i];
        }
        ltot -= dp[nxt][0];
        array<lint, 5> c2;
        REP(i, K) c2[(i + 1) % K] = cm[i];
        ltot += cm[0];
        REP(i, K) c2[i] += dp[nxt][i];
        dfs2(nxt, now, c2);
        ltot -= cm[0];
        ltot += dp[nxt][0];
    }
}

int main()
{
    cin >> N >> K;
    to.resize(N);
    REP(e, N - 1)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        REP(_, 2) to[u].push_back(v), swap(u, v);
    }
    dp.resize(N);
    depth.resize(N);
    dfs1(0, -1);

    ltot = 0;
    REP(i, N) ltot += (depth[i] + K - 1) / K;
    array<lint, 5> arr;
    REP(i, K) arr[i] = dp[0][i];
    dfs2(0, -1, arr);
    cout << ret / 2 << '\n';
}