#include <iostream>
#include <string>
#include <tuple>
#include <utility>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <deque>
using namespace std;
typedef long long ll;

int main(void) {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<ll>> a(n, vector<ll>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }

        ll res = 0;
        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < m / 2; j++) {
                vector<int> super(4, 0);
                super[0] = a[i][j];
                super[1] = a[n - 1 - i][j];
                super[2] = a[n - 1 - i][m - 1 - j];
                super[3] = a[i][m - 1 - j];
                sort(super.begin(), super.end());
                res = res + super[3] + super[2] - super[1] - super[0];
            }
        }

        if (n % 2 == 1) {
            for (int j = 0; j < m / 2; j++) {
                res = res + max(a[n/2][j], a[n/2][m - 1 - j]) - min(a[n/2][j], a[n/2][m - 1- j]);
            }
        }

        if (m % 2 == 1) {
            for (int i = 0; i < n / 2; i++) {
                res = res + max(a[i][m/2], a[n-1-i][m/2]) - min(a[i][m/2],a[n-1-i][m/2]);
            }
        }

        cout << res << "\n";
    }
}