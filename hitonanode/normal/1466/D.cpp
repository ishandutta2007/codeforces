#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)

void solve() {
    int N;
    cin >> N;
    long long cum = 0;
    priority_queue<pair<int, int>> pq;
    REP(i, N) {
        int w;
        cin >> w;
        cum += w;
        pq.emplace(w, i);
    }

    vector<int> deg(N, -1);
    REP(i, N * 2 - 2) {
        int u;
        cin >> u;
        deg[u - 1]++;
    }

    REP(i, N - 2) {
        cout << cum << ' ';
        while (!deg[pq.top().second]) pq.pop();
        deg[pq.top().second]--;
        cum += pq.top().first;
    }
    cout << cum << '\n';
}

int main() {
    cin.tie(nullptr), ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) solve();
}