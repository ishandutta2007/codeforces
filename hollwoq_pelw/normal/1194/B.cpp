#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 5;
int N, M;
vector<string> grid;
vector<int> row_missing, col_missing;

void solve_case() {
    cin >> N >> M;
    grid.resize(N);

    for (string &str : grid)
        cin >> str;

    row_missing.assign(N, 0);
    col_missing.assign(M, 0);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (grid[i][j] == '.') {
                row_missing[i]++;
                col_missing[j]++;
            }

    int best = INF;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            best = min(best, row_missing[i] + col_missing[j] - (grid[i][j] == '.'));

    cout << best << '\n';
}

int main() {
    int Q;
    cin >> Q;

    while (Q--)
        solve_case();
}