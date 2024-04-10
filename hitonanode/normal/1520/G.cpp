#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
template <typename T> bool chmin(T &m, const T q) {
    if (m > q) {
        m = q;
        return true;
    } else
        return false;
}
using namespace std;
using lint = long long;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)

constexpr lint INF = 1LL << 60;
const array<int, 4> dx{1, -1, 0, 0};
const array<int, 4> dy{0, 0, 1, -1};

int main() {
    cin.tie(nullptr), ios::sync_with_stdio(false);
    int N, M, W;
    cin >> N >> M >> W;
    vector A(N, vector<int>(M));
    for (auto &v : A) {
        for (auto &x : v) cin >> x;
    }

    using pint = pair<int, int>;
    auto bfs = [&](int gs, int gt) -> vector<vector<lint>> {

        vector<vector<lint>> dist(N, vector<lint>(M, INF));
        dist[gs][gt] = 0;
        queue<pint> q;
        q.emplace(gs, gt);
        while (q.size()) {
            auto [i, j] = q.front();
            q.pop();
            REP(d, 4) {
                int ni = i + dx[d], nj = j + dy[d];
                if (ni >= 0 and ni < N and nj >= 0 and nj < M and A[ni][nj] >= 0) {
                    if (chmin(dist[ni][nj], dist[i][j] + W)) q.emplace(ni, nj);
                }
            }
        }
        return dist;
    };

    auto d1 = bfs(0, 0), d2 = bfs(N - 1, M - 1);
    auto ret = d1[N - 1][M - 1];
    lint afrom = INF, ato = INF;

    REP(i, N) REP(j, M) {
        if (A[i][j] > 0) {
            chmin(afrom, d1[i][j] + A[i][j]);
            chmin(ato, d2[i][j] + A[i][j]);
        }
    }
    chmin(ret, afrom + ato);
    cout << (ret < INF ? ret : -1) << '\n';
}