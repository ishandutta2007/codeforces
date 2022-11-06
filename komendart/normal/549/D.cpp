#include <bits/stdc++.h>

using namespace std;

vector<int> sums(105, 0);

int main() {
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector< vector<int> > needed(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            if (s[j] == 'W') needed[i][j] = 1;
            else needed[i][j] = -1;
        }
    }

    int result = 0;
    for (int i = n - 1; i >= 0; i--) {
        int v = 0;
        for (int j = m - 1; j >= 0; j--) {
            v += sums[j];
            if (v != needed[i][j]) {
                result++;
                sums[j] += needed[i][j] - v;
                v = needed[i][j];
            }
        }
    }

    cout << result << endl;
}