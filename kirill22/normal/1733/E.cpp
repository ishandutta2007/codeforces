#include "bits/stdc++.h"

using namespace std;

const int N = 120;

vector<long long> get(long long t, int s) {
    vector<vector<long long>> a(N, vector<long long> (N));
    a[0][0] = t;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (j + 1 < N) {
                a[i][j + 1] += (a[i][j] + 1) / 2;
            }
            if (i + 1 < N) {
                a[i + 1][j] += a[i][j] / 2;
            }
        }
    }
    vector<long long> res(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i + j == s) {
                res[i] = a[i][j];
            }
        }
    }
    return res;
}

void solve() {
    long long t;
    int x, y;
    cin >> t >> x >> y;
    if (t < x + y) {
        cout << "NO" << '\n';
        return;
    }
    long long cnt = t - x - y + 1;
    auto state1 = get(cnt - 1, x + y);
    auto state2 = get(cnt, x + y);
    cout << (state1[x] != state2[x] ? "YES" : "NO") << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}