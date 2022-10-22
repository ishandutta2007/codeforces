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
        int n;
        cin >> n;

        vector<tuple<int, int>> ab(n);
        vector<tuple<int, int>> ab_sorted(n);
        vector<int> a(n);
        vector<int> b(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }

        for (int i = 0; i < n; i++) {
            ab[i] = { a[i], b[i] };
            ab_sorted[i] = { a[i], b[i] };
        }

        sort(ab_sorted.begin(), ab_sorted.end());

        int prev_b = -1;
        bool is_sorted = true;
        for (auto [a_el, b_el] : ab_sorted) {
            if (b_el < prev_b) {
                is_sorted = false;
                break;
            }

            prev_b = b_el;
        }

        if (!is_sorted) {
            cout << "-1\n";
            continue;
        }

        vector<tuple<int, int>> inversions;
        for (int i = 0; i < n; i++) {
            auto [a_el_0, b_el_0] = ab_sorted[i];

            for (int j = i; j < n; j++) {
                auto [a_el_1, b_el_1] = ab[j];

                if (a_el_0 == a_el_1 && b_el_0 == b_el_1 && i != j) {
                    inversions.emplace_back(i + 1, j + 1);
                    swap(ab[i], ab[j]);
                }
            }
        }

        cout << inversions.size() << "\n";
        for (auto [i, j] : inversions) cout << i << " " << j << "\n";
    }
}