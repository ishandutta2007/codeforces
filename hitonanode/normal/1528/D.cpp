#include <iostream>
#include <vector>
using namespace std;
using pint = pair<int, int>;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template <typename T> bool chmin(T &m, const T q) { return m > q ? (m = q, true) : false; }


int main() {
    cin.tie(nullptr), ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    vector<vector<pair<int, int>>> to(N);
    REP(e, M) {
        int a, b, c;
        cin >> a >> b >> c;
        to[a].emplace_back(b, c);
    }
    REP(st, N) {
        vector<unsigned> dist(N * 2, 1 << 30);
        dist[st] = 0;
        vector<int> visited(dist.size());
        REP(iter, N * 2) {
            int now = -1;
            REP(k, dist.size()) {
                if (!visited[k]) {
                    if (now == -1 or dist[k] < dist[now]) now = k;
                }
            }
            visited[now] = 1;
            if (now >= N) {
                int nxt = now + 1;
                if (nxt == N * 2) nxt = N;
                chmin(dist[nxt], dist[now] + 1);
                chmin(dist[now - N], dist[now]);
            } else {
                for (auto [nxt0, w] : to[now]) {
                    int nxt = (nxt0 + dist[now]) % N;
                    chmin(dist[nxt + N], dist[now] + w);
                }
            }
        }
        REP(i, N) cout << dist[i] << ' ';
        cout << '\n';
    }
}