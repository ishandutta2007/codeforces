#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<vector<long long>> c(2, vector<long long>(n));
    vector<vector<long long>> d(2, vector<long long>(n-1));
    for (int i = 0; i < 2; i++) {
        for (auto& x : c[i])
            cin >> x;

        for (int j = 0; j < n - 1; j++) {
            d[i][j] = c[i][j+1] - c[i][j];
        }
        sort(d[i].begin(), d[i].end());
    }

    if (d[0] == d[1] && c[0][0] == c[1][0])
        cout << "Yes" << '\n';
    else
        cout << "No" << '\n';
}