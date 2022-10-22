#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>
#include <utility>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <complex>
using namespace std;
typedef long long ll;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(14);
    int t;
    cin >> t;

    vector<vector<bool>> force_even(102, vector<bool>(102, true));
    vector<vector<bool>> force_odd(102, vector<bool>(102, true));

    for (int i = 0; i < 101; i++) {
        force_even[i + 1][1] = true;
        force_odd[i + 1][1] = false;

        force_even[1][i + 1] = ((i + 1) / 2 % 2 == 0);
        force_odd[1][i + 1] = ((i + 1) / 2 % 2 == 1);
    }

    for (int i = 2; i < 102; i++) {
        for (int j = 2; j < 102; j++) {
            force_even[i][j] = false;
            force_odd[i][j] = false;
            // Alice picks even
            if (force_even[i - 2][j] && force_even[i - 1][j - 1]) {
                force_even[i][j] = true;
            }

            if (force_odd[i - 2][j] && force_odd[i - 1][j - 1]) {
                force_odd[i][j] = true;
            }

            // Alice pciks odd
            if (force_odd[i - 1][j - 1] && force_odd[i][j - 2]) {
                force_even[i][j] = true;
            }

            if (force_even[i - 1][j - 1] && force_even[i][j - 2]) {
                force_odd[i][j] = true;
            }
        }
    }

    while (t--) {
        int n;
        cin >> n;
        int num_even = 0;
        int num_odd = 0;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            if (a % 2 == 0) {
                num_even++;
            } else {
                num_odd++;
            }
        }

        if (force_even[num_even + 1][num_odd + 1]) {
            cout << "Alice\n";
        } else {
            cout << "Bob\n";
        }
    }
}