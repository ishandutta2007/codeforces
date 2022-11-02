#include <bits/stdc++.h>
using namespace std;

const int MAXN = 510;
int arr[MAXN][MAXN];
int used[MAXN * MAXN];

main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        fill(used, used + n * m + 1, -1);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> arr[i][j];
            }
            used[arr[i][0]] = i;
        }
        for (int i = 0; i < m; ++i) {
            vector<int> v(n);
            for (int j = 0; j < n; ++j) {
                cin >> v[j];
            }
            if (used[v[0]] != -1) {
                for (auto elem : v) {
                    int ind = used[elem];
                    for (int j = 0; j < m; ++j) {
                        cout << arr[ind][j] << " ";
                    }
                    cout << endl;
                }
            }
        }
    }
    return 0;
}