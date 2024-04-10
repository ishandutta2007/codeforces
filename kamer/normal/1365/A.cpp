#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> nums(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int x; cin >> x;
                nums[i].push_back(x);
            }
        }
        
        int cols = 0, rows = 0;
        for (int i = 0; i < n; i++) {
            bool empty = true;
            for (int j = 0; j < m; j++) {
                if (nums[i][j] == 1) empty = false;
            }
            if (empty) cols++;
        }

        for (int i = 0; i < m; i++) {
            bool empty = true;
            for (int j = 0; j < n; j++) {
                if (nums[j][i] == 1) empty = false;
            }
            if (empty) rows++;
        }

        if (min(rows, cols) % 2 == 0) {
            cout << "Vivek\n";
        } else {
            cout << "Ashish\n";
        }
    }
}