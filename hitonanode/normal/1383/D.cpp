#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template <typename T> bool chmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template <typename T> bool chmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template <typename T> istream &operator>>(istream &is, vector<T> &vec) { for (auto &v : vec) is >> v; return is; }


int main()
{
    int N, M;
    cin >> N >> M;
    vector A(N, vector<int>(M));
    cin >> A;

    vector<int> R(N), C(M);
    REP(i, N) REP(j, M)
    {
        chmax(R[i], A[i][j]);
        chmax(C[j], A[i][j]);
    }

    vector<int> used(N * M + 1);
    for (auto x : R) used[x] += 1;
    for (auto x : C) used[x] += 2;

    vector<int> both, xonly, yonly;
    FOR(x, 1, used.size())
    {
        if (used[x] == 1) xonly.emplace_back(x);
        if (used[x] == 2) yonly.emplace_back(x);
        if (used[x] == 3) both.emplace_back(x);
    }

    vector ret(N, vector<int>(M));

    sort(both.begin(), both.end());
    sort(xonly.rbegin(), xonly.rend());
    sort(yonly.rbegin(), yonly.rend());
    REP(i, both.size()) ret[i][i] = both[i];
    int K = both.size() - 1;
    REP(i, xonly.size()) ret[K + 1 + i][K] = xonly[i];
    REP(i, yonly.size()) ret[K][K + 1 + i] = yonly[i];

    set<int> se;
    FOR(i, 1, used.size()) if (!used[i]) se.insert(i);

    auto alloc = [&](int i, int j) -> void {
        if (ret[i][j]) return;
        int lo = 1e9;
        if (i and ret[i - 1][j]) chmin(lo, ret[i - 1][j]);
        if (j and ret[i][j - 1]) chmin(lo, ret[i][j - 1]);
        if (i + 1 < N and ret[i + 1][j]) chmin(lo, ret[i + 1][j]);
        if (j + 1 < M and ret[i][j + 1]) chmin(lo, ret[i][j + 1]);
        auto itr = prev(se.lower_bound(lo));
        ret[i][j] = *itr;
        se.erase(itr);
    };

    FOR(i, K + 1, N) FOR(j, K + 1, M) alloc(i, j);
    IREP(d, K)
    {
        FOR(i, d, N) alloc(i, d);
        FOR(j, d, M) alloc(d, j);
    }

    for (auto vec : ret)
    {
        REP(i, M) cout << vec[i] << (i + 1 == M ? '\n' : ' ');
    }
}