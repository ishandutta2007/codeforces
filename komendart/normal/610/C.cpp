#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int k;
    cin >> k;
    vector< vector<int> > result(1 << k, vector<int>(1 << k));
    for (int q = 0; q < k; q++) {
        int t = 1 << q;
        for (int i = 0; i < 2 * t; i++) {
            for (int j = 0; j < 2 * t; j++) {
                result[i][j] = result[i % t][j % t];
                if (i >= t && j >= t) {
                    result[i][j] ^= 1;
                }
            }
        }
    }

    for (auto i: result) {
        for (auto j: i) cout << "+*"[j];
        cout << '\n';
    }
}