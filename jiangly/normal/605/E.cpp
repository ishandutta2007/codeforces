#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<double>> p(n, vector<double>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int x;
            cin >> x;
            p[i][j] = x / 100.0;
        }
    }
    vector<double> f(n, 1), pr(n, 1);
    vector<bool> visited(n);
    f[n - 1] = pr[n - 1] = 0;
    for (int i = 0; i < n; ++i) {
        int x = -1;
        if (i == 0) {
            x = n - 1;
        } else {
            for (int j = 0; j < n; ++j)
                if (!visited[j] && (x == -1 || f[j] * (1 - pr[x]) < f[x] * (1 - pr[j])))
                    x = j;
        }
        visited[x] = true;
        f[x] /= 1 - pr[x];
        for (int j = 0; j < n; ++j) {
            if (!visited[j]) {
                f[j] += f[x] * pr[j] * p[j][x];
                pr[j] *= 1 - p[j][x];
            }
        }
    }
    cout << setprecision(10) << fixed << f[0] << endl;
    return 0;
}