#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    int start_r, start_c;
    cin >> start_r >> start_c;
    start_r--, start_c--;
    int x, y;
    cin >> x >> y;
    vector<string> board(n);
    for (auto& x : board)
        cin >> x;
    
    int INF = std::numeric_limits<int>::max();
    vector<vector<int>> dp(n, vector<int>(m, INF));

    set<pair<int, pair<int, int>>> queue;
    dp[start_r][start_c] = 0;
    queue.insert({0, {start_r, start_c}});
    auto add_pos = [&](pair<int, int> pos, int cost) {
        auto& old = dp[pos.first][pos.second];
        if (board[pos.first][pos.second] != '*' && cost < old) {
            if (old < INF)
                queue.erase(queue.find({old, pos}));
            old = cost;
            queue.insert({old, pos});
        }
    };
    while (!queue.empty()) {
        auto [cost, pos] = *queue.begin();
        queue.erase(queue.begin());

        auto [r, c] = pos;
        if (r > 0)
            add_pos({r-1, c}, cost);
        if (r < n - 1)
            add_pos({r+1, c}, cost);
        if (c > 0)
            add_pos({r, c-1}, cost+1);
        if (c < m - 1)
            add_pos({r, c+1}, cost);
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int left = dp[i][j];
            int right = left + j - start_c;
            if (left <= x && right <= y)
                cnt++;
        }
    }
    cout << cnt << '\n';
}