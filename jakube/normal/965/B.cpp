#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<string> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    
    vector<vector<int>> v(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j + k <= n; j++) {
            bool bo = true;
            for (int a = 0; a < k; a++) {
                if (b[i][j+a] == '#')
                    bo = false;
            }
            if (bo) {
                for (int a = 0; a < k; a++)
                    v[i][j+a]++;
            }

            if (k == 1)
                continue;

            bo = true;
            for (int a = 0; a < k; a++) {
                if (b[j+a][i] == '#')
                    bo = false;
            }
            if (bo) {
                for (int a = 0; a < k; a++)
                    v[j+a][i]++;
            }
        }
    }

    int x, y;
    int best = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (v[i][j] > best) {
                best = v[i][j];
                x = i;
                y = j;
            }
        }
    }

    cout << x + 1 << " " << y + 1 << '\n';
}