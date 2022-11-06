#include <bits/stdc++.h>

using namespace std;

vector<int> block[1001][1001];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        block[x / 1000][y / 1000].push_back(i + 1);
    }

    for (int i = 0; i <= 1000; i++) {
        for (int j = 0; j <= 1000; j++) {
            random_shuffle(block[i][j].begin(), block[i][j].end());
        }
    }

    int prev = -1;
    for (int i = 0; i <= 1000; i++) {
        for (int j = 0; j <= 1000; j++) {
            int t = (i & 1) ? j: 1000 - j;
            for (auto k: block[i][t]) {
                cout << k << ' ';
            }
        }
    }
}