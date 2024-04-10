#include <bits/stdc++.h>
using namespace std;

bool check(vector<string>& board, char ban) {
    for (string& s : board) {
        for (char c : s) {
            if (c == ban) return false;
        }
    }
    return true;
}

void solve(vector<string>& board, vector<pair<int, int>>& answer, char ban) {
    int n = board.size();
    int m = board[0].size();

    while (1) {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < m - 1; j++) {
                if (board[i][j] == 'L' && board[i+1][j] == 'L') {
                    answer.push_back({i, j});
                    board[i][j] = 'U';
                    board[i+1][j] = 'D';
                    board[i][j+1] = 'U';
                    board[i+1][j+1] = 'D';
                }
            }
        }

        if (check(board, ban)) return;

        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < m - 1; j++) {
                if (board[i][j] == 'U' && board[i][j+1] == 'U') {
                    answer.push_back({i, j});
                    board[i][j] = 'L';
                    board[i+1][j] = 'L';
                    board[i][j+1] = 'R';
                    board[i+1][j+1] = 'R';
                }
            }
        }

        if (check(board, ban)) return;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n, m;
    cin >> n >> m;
    
    vector<string> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    vector<pair<int, int>> answer1, answer2;
    char ban = n % 2 ? 'U' : 'L';

    solve(a, answer1, ban);
    solve(b, answer2, ban);
    reverse(answer2.begin(), answer2.end());
    
    cout << answer1.size() + answer2.size() << '\n';
    for (auto p : answer1) cout << p.first + 1 << ' ' << p.second + 1 << '\n';
    for (auto p : answer2) cout << p.first + 1 << ' ' << p.second + 1 << '\n';
}