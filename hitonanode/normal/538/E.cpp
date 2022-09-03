#include <bits/stdc++.h>
using namespace std;
using pint = pair<int, int>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> bool chmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool chmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;

vector<vector<int>> to;

int dfs1(int now, int depth)
{
    if (to[now].empty()) return 1;

    if (depth % 2)
    {
        int ret = 0;
        for (auto nxt : to[now]) ret += dfs1(nxt, depth + 1);
        return ret;
    }
    else
    {
        int ret = 1e9;
        for (auto nxt : to[now]) chmin(ret, dfs1(nxt, depth + 1));
        return ret;
    }
}

int main()
{
    int N;
    cin >> N;
    to.resize(N + 1);
    REP(_, N - 1)
    {
        int u, v;
        cin >> u >> v;
        to[u].emplace_back(v);
    }

    int M = 0;
    FOR(i, 1, N + 1) M += to[i].empty();

    cout << M + 1 - dfs1(1, 0) << ' ' << dfs1(1, 1) << '\n';
}