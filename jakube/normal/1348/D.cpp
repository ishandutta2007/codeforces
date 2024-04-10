#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n;
    cin >> n;
    if (n < 6) {
        if (n == 2) {
            cout << 1 << '\n';
            cout << 0 << '\n';
        } else if (n == 3) {
            cout << 1 << '\n';
            cout << 1 << '\n';
        } else if (n == 4) {
            cout << 2 << '\n';
            cout << "0 1" << '\n';
        } else if (n == 5) {
            cout << 2 << '\n';
            cout << "1 0" << '\n';
        }
        return;
    }

    vector<long long> splits;
    long long cells = 1;
    long long weight = 1;
    while (weight < n) {
        splits.push_back(cells);
        cells *= 2;
        weight += cells;
    }
    if (weight > n) {
        weight -= cells;
        cells /= 2;
        splits.pop_back();
        weight -= cells;
        cells /= 2;
        splits.pop_back();
        assert(weight + cells * 2 < n);
        long long diff = n - weight - cells * 2;
        int tmp = min(diff / 2, cells);
        splits.push_back(tmp);
        cells += tmp;
        weight += cells;
        diff = n - weight - cells;
        assert(0 <= diff && diff <= cells);
        splits.push_back(diff);
    }

    cout << splits.size() << '\n';
    for (auto x : splits) {
        cout << x << ' ';
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int testcase = 1; testcase <= T; testcase++) {
        solve();
    }
}