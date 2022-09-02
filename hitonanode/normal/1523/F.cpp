#pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,mmx,avx,avx2")
#include <algorithm>
#include <bitset>
#include <iostream>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template <typename T> bool chmax(T &m, const T q) { return m < q ? (m = q, true) : false; }
template <typename T> bool chmin(T &m, const T q) { return m > q ? (m = q, true) : false; }

int main() {
    cin.tie(nullptr), ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> A(N);
    vector<tuple<int, int, int>> B(M);
    REP(i, N) cin >> A[i].first >> A[i].second;
    for (auto &[t, x, y] : B) cin >> x >> y >> t;
    sort(B.begin(), B.end());
    vector<int> T, Bx, By;
    for (auto [t, x, y] : B) T.push_back(t), Bx.push_back(x), By.push_back(y);

    constexpr int INF = (1 << 30) - 1;
    vector DN(N, vector<int>(N));
    vector<bitset<100>> DMreach(M);
    REP(i, N) REP(j, N) DN[i][j] = abs(A[i].first - A[j].first) + abs(A[i].second - A[j].second);
    REP(i, M) FOR(j, i + 1, M) {
        auto [ti, xi, yi] = B[i];
        auto [tj, xj, yj] = B[j];
        int d = abs(xi - xj) + abs(yi - yj);
        if (tj - ti >= d) DMreach[i].set(j);
    }

    vector dist_s2m(1 << N, vector<int>(M, INF)); // [S][m] S  activate  S  m 
    REP(i, M) REP(j, N) dist_s2m[1 << j][i] = abs(Bx[i] - A[j].first) + abs(By[i] - A[j].second);
    REP(S, 1 << N) REP(m, M) REP(d, N) {
        if ((S >> d) & 1) chmin(dist_s2m[S][m], dist_s2m[S - (1 << d)][m]);
    }

    vector dp_upper(1 << N, vector<int>(1 + M, INF)); // dp_upper[quest][adtivated n's] = 
    vector dp_lower(1 << N, vector<int>(M, -INF));    // dp_lower[questid][adtivated n's] = quest

    REP(n, N) dp_upper[1 << n][0] = 0;
    REP(m, M) dp_lower[0][m] = 1;
    REP(S, 1 << N) {
        vector<int> dn(N, INF);
        REP(i, N) REP(j, N) if ((S >> j) & 1) chmin(dn[i], DN[i][j]);
        auto dist_mn = [&](int m, int n) {
            // S activate  m  n 
            int ret = dn[n];
            chmin(ret, abs(Bx[m] - A[n].first) + abs(By[m] - A[n].second));
            return ret;
        };

        REP(k, M + 1) { // k 
            if (dp_upper[S][k] < INF) {
                REP(n, N) chmin(dp_upper[S | (1 << n)][k], dp_upper[S][k] + dn[n]);
                REP(m, M) if (dp_upper[S][k] + dist_s2m[S][m] <= T[m]) chmax(dp_lower[S][m], k + 1);
            }
        }
        REP(m, M) { // m: last quest
            int know = dp_lower[S][m];
            if (know >= 0) {
                REP(n, N) chmin(dp_upper[S | (1 << n)][know], T[m] + dist_mn(m, n));
                FOR(m2, m + 1, M) {
                    if (DMreach[m][m2] or dist_s2m[S][m2] <= T[m2] - T[m]) chmax(dp_lower[S][m2], dp_lower[S][m] + 1);
                }
            }
        }
    }
    int ret = 0;
    REP(s, dp_upper.size()) REP(k, dp_upper[s].size()) if (dp_upper[s][k] < INF) chmax(ret, k);
    REP(s, dp_lower.size()) REP(m, dp_lower[s].size()) chmax(ret, dp_lower[s][m]);
    cout << ret << '\n';
}