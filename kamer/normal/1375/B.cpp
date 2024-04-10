#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <set>
#include <unordered_set>
#include <tuple>
#include <map>
#include <unordered_map>
#include <queue>
using namespace std;
typedef long long ll;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        // vector<vector<int>> a(n, vector<int>(m, 0));
        bool pos = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int a;
                cin >> a;
                if ((i == 0 || i == n - 1) && (j == 0 || j == m - 1)) {
                    if (a > 2) pos = false;
                } else if ((i == 0 || i == n - 1) || (j == 0 || j == m - 1)) {
                    if (a > 3) pos = false;
                } else {
                    if (a > 4) pos = false;
                }
            }
        }

        if (!pos) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            cout << "2 ";
            for (int j = 1; j < m - 1; j++) cout << "3 ";
            cout << "2\n";
            for (int i = 1; i < n - 1; i++) {
                cout << "3 ";
                for (int j = 1; j < m - 1; j++) cout << "4 ";
                cout << "3\n";
            }

            cout << "2 ";
            for (int j = 1; j < m - 1; j++) cout << "3 ";
            cout << "2\n";
        }
    }
}