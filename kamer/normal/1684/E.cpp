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
using namespace std;
typedef long long ll;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(14);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        vector<bool> small_exists(n, false);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] < n) {
                small_exists[a[i]] = true;
            }
        }

        int not_exists_count = 0;
        int largest_mex = n;
        for (int i = 0; i < n; i++) {
            if (!small_exists[i]) {
                not_exists_count++;
            }

            if (not_exists_count > k) {
                largest_mex = i;
                break;
            }
        }

        unordered_map<int, int> large_counts;
        for (auto a_el : a) {
            if (a_el >= largest_mex) {
                large_counts[a_el]++;
            }
        }

        vector<int> counts;
        for (auto& it : large_counts) {
            counts.emplace_back(it.second);
        }

        sort(counts.begin(), counts.end());

        int curr_displaced = 0;
        int best_score = 0;
        for (int i = 0; i < counts.size(); i++) {
            if (curr_displaced + counts[i] > k) {
                best_score = counts.size() - i;
                break;
            }

            curr_displaced += counts[i];
        }

        cout << best_score << "\n";
    }
}