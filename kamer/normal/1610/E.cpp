#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <string>
#include <utility>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;
typedef long long ll;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(14);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        ll prev_val = -1;
        int best_count = -1;
        for (int i = 0; i < n - 1; i++) {
            if (a[i] == prev_val) {
                continue;
            }
            prev_val = a[i];
            int j = i;
            while (j < n && a[j] == prev_val) {
                j++;
            }
            if (j == n) {
                best_count = max(best_count, j - i);
                continue;
            }

            int curr_counter = j - i + 1;
            int curr_step = a[j] - prev_val;
            int curr_val = a[j];
            while (true) {
                auto it = lower_bound(a.begin(), a.end(), curr_val + curr_step);
                if (it == a.end()) {
                    break;
                }

                curr_counter++;
                curr_val = *it;
                curr_step = curr_val - prev_val;
            }

            best_count = max(best_count, curr_counter);
        }

        cout << n - best_count << "\n";
    }
}