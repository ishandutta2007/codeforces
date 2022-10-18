#include <bits/stdc++.h>
using namespace std;

enum State { Loosing, Winning, Undecided };

void f(int n, vector<vector<int>> moves) {
    vector<vector<State>> states(2, vector<State>(n, Undecided));
    vector<vector<int>> cnt(2, vector<int>(n, 0));

    states[0][0] = Loosing;
    states[1][0] = Loosing;
    queue<pair<int, int>> q;
    q.push({0, 0});
    q.push({1, 0});

    while (!q.empty()) {
        auto [x,y] = q.front();
        q.pop();

        int X = x^1;
        if (states[x][y] == Loosing) {
            for (int move : moves[X]) {
                int Y = (y - move + n) % n;
                if (states[X][Y] == Undecided) {
                    states[X][Y] = Winning;
                    q.push({X, Y});
                }
            }
        } else {
            for (int move : moves[X]) {
                int Y = (y - move + n) % n;
                if (++cnt[X][Y] == (int)moves[X].size()) {
                    states[X][Y] = Loosing;
                    q.push({X, Y});
                }
            }
        }
    }

    for (int j = 0; j < 2; j++) {
        for (int i = 1; i < n; i++) {
            auto s = states[j][i];
            if (s == Winning)
                cout << "Win" << ' ';
            if (s == Loosing)
                cout << "Lose" << ' ';
            if (s == Undecided)
                cout << "Loop" << ' ';
        }
        cout << '\n';
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int k1;
    cin >> k1;
    vector<int> rick(k1);
    for (int i = 0; i < k1; i++) {
        cin >> rick[i];
    }
    int k2;
    cin >> k2;
    vector<int> morty(k2);
    for (int i = 0; i < k2; i++) {
        cin >> morty[i];
    }

    f(n, {rick, morty});
    // f(n, {morty, rick});
}