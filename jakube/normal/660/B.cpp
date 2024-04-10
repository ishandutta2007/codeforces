#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> left(n, {-1, -1}), right(n, {-1, -1});
    bool first_pass = true;
    int idx = 0;
    for (int i = 0; i < m; i++) {
        if (i % 2 == 0) {
            if (first_pass) {
                left[idx].first = i;
            } else {
                left[idx].second = i;
            }
        } else {
            if (first_pass) {
                right[idx].first = i;
            } else {
                right[idx].second = i;
            }
            idx++;
            if (idx == n) {
                first_pass = false;
                idx = 0;
            }
        }
    }

    for (int idx = 0; idx < n; idx++) {
        if (left[idx].second != -1) {
            cout << left[idx].second + 1 << " ";
        }
        if (left[idx].first != -1) {
            cout << left[idx].first + 1 << " ";
        }
        if (right[idx].second != -1) {
            cout << right[idx].second + 1 << " ";
        }
        if (right[idx].first != -1) {
            cout << right[idx].first + 1 << " ";
        }
    }
    // 2 6    3
    // 0 4   5 1
}