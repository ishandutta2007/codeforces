#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
using namespace std;

typedef long long ll;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<char>> a(n, vector<char>(n, '0'));
        int rows = k / n;
        int cols = k % n;
        for (int i = 0; i <= rows; i++) {
            int lim = n;
            if (i == rows) lim = cols;
            for (int j = 0; j < lim; j++) {
                a[j][(i + j) % n] = '1';
            }
        }

        if (cols == 0) cout << "0\n";
        else           cout << "2\n";

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << a[i][j];
            }
            cout << "\n";
        }
    }
}