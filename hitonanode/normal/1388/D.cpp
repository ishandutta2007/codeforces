#include <bits/stdc++.h>
using namespace std;
using lint = long long;
struct fast_ios { fast_ios(){ cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template <typename T> istream &operator>>(istream &is, vector<T> &vec) { for (auto &v : vec) is >> v; return is; }

int main()
{
    int N;
    cin >> N;
    vector<lint> A(N), B(N);
    cin >> A >> B;
    for (auto &b : B) b--;
    vector<vector<int>> to(N);
    REP(i, N) if (B[i] >= 0) to[B[i]].emplace_back(i);

    lint ret = 0;
    vector<int> qs;
    vector<int> used(N);
    auto dfs = [&](auto &&dfs, int i) -> lint {
        for (auto j : to[i])
        {
            A[i] += dfs(dfs, j);
        }
        if (A[i] > 0)
        {
            ret += A[i];
            qs.emplace_back(i);
            used[i] = 1;
            return A[i];
        }
        else return 0;
    };

    auto dfs2 = [&](auto &&dfs2, int i) -> void {
        if (!used[i]) qs.emplace_back(i), ret += A[i];
        for (auto j : to[i]) dfs2(dfs2, j);
    };
    REP(i, N) if (B[i] < 0)
    {
        dfs(dfs, i);
        dfs2(dfs2, i);
    }
    cout << ret << '\n';
    for (auto x : qs) cout << x + 1 << ' ';
    cout << '\n';
}