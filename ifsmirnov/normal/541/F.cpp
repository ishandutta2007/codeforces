#include <bits/stdc++.h>

using namespace std;

const int M = 1010;

int n, t;
vector<int> w[M], s[M];
int d[M][M];

void read() {
    cin >> n >> t;
    for (int i = 0; i < n; ++i) {
        int tim, q;
        cin >> tim >> q;
        w[t - tim].push_back(q);
    }
    for (int i = 0; i < t; ++i) {
        sort(w[i].begin(), w[i].end());
        reverse(w[i].begin(), w[i].end());
        s[i].push_back(0);
        for (auto x : w[i])
            s[i].push_back(s[i].back() + x);
    }
}

void runDin() {
    for (int i = t - 1; i >= 0; --i)
        for (int sum = 0; sum <= n; ++sum) {
            for (int j = 0; j < s[i].size() && j <= sum; ++j)
                d[i][sum] = max(d[i][sum], s[i][j] + d[i + 1][min(n, 2 * (sum - j))]);
        }
    cout << d[0][1] << "\n";
}

int main() {
    read();
    runDin();
    return 0;
}