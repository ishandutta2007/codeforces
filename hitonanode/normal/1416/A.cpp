#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template <typename T> bool chmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template <typename T> bool chmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template <typename T> istream &operator>>(istream &is, vector<T> &vec) { for (auto &v : vec) is >> v; return is; }


constexpr int INF = 1e9 + 10;
void solve()
{
    int N;
    cin >> N;
    vector<int> A(N);
    cin >> A;
    vector<vector<int>> val2i(N + 1);
    REP(i, N) val2i[A[i]].emplace_back(i);
    vector<int> ret(N + 1, INF);

    REP(v, val2i.size()) if (val2i[v].size())
    {
        const vector<int> &vec = val2i[v];
        int diff = max(vec[0] + 1, N - vec.back());
        REP(i, vec.size() - 1) chmax(diff, vec[i + 1] - vec[i]);
        chmin(ret[diff], v);
    }
    REP(i, N) chmin(ret[i + 1], ret[i]);

    FOR(i, 1, N + 1) cout << (ret[i] == INF ? -1 : ret[i]) << ' ';
    cout << '\n';
}
int main()
{
    int T;
    cin >> T;
    while (T--) solve();
}