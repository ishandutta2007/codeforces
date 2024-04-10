#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> countZero(n + m - 1, 0);
        vector<int> countOne(n + m - 1, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int s;
                cin >> s;
                if (s == 0) countZero[i + j]++;
                else        countOne[i + j]++;
            }
        }
        int diff = 0;
        for (int i = 0; i < ((n + m - 1) / 2); i++) {
            int zero = countZero[i] + countZero[n + m - 2 - i];
            int one = countOne[i] + countOne[n + m - 2 - i];
            diff += min(zero, one);
        }
        cout << diff << "\n";
    }
}