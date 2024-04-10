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
using namespace std;
typedef long long ll;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(9);
    int n;
    cin >> n;
    vector<int> a_fake(n);
    for (int i = 0; i < n; i++) cin >> a_fake[i];
    vector<double> a(n);
    for (int i = 0; i < n; i++) a[i] = a_fake[i];
    vector<int> best_index(n);
    vector<double> prefix_sums(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefix_sums[i + 1] = prefix_sums[i] + a[i];
    }
    best_index[n - 1] = n;
    for (int i = n - 2; i >= 0; i--) {
        best_index[i] = i + 1;
        while (true) {
            if (best_index[i] == n) break;
            double avg = (prefix_sums[best_index[i]] - prefix_sums[i]) / (best_index[i] - i);
            double next_avg = (prefix_sums[best_index[best_index[i]]] - prefix_sums[best_index[i]]) / (best_index[best_index[i]] - best_index[i]);
            if (avg >= next_avg) {
                best_index[i] = best_index[best_index[i]];
            } else {
                break;
            }
        }
    }

    int curr_index = 0;
    while (true) {
        if (curr_index == n) break;
        double avg = (prefix_sums[best_index[curr_index]] - prefix_sums[curr_index]) / (best_index[curr_index] - curr_index);
        for (int i = curr_index; i < best_index[curr_index]; i++) {
            cout << avg << "\n";
        }
        curr_index = best_index[curr_index];
    }
}