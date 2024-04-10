#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n, m;
    cin >> n >> m;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    map<int, int> used;
    int evens = 0, odds = 0;
    for (auto i : v) {
        used[i]++;
        if (i%2) odds++;
        else evens++;
    }
    
    int odd_idx = 1;
    int even_idx = 0;
    used[0] = 1;

    auto replacer = [&used](int& idx, int&val) {
        used[val]--;
        while (used[idx] > 0) {
            idx += 2;
        }
        val = idx;
        used[val]++;
    };

    // get ride of duplicates
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (used[v[i]] > 1) {
            cnt++;
            if (v[i] % 2 == 0) {
                evens--;
            } else {
                odds--;
            }

            if (evens > odds) {
                replacer(odd_idx, v[i]);
                odds++;
            } else {
                replacer(even_idx, v[i]);
                evens++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (odds > evens && v[i] % 2 == 1) {
            replacer(even_idx, v[i]);
            odds--;
            evens++;
            cnt++;
        } else if (evens > odds && v[i] % 2 == 0) {
            replacer(odd_idx, v[i]);
            odds++;
            evens--;
            cnt++;
        }
    }

    if (odds != evens || even_idx > m || odd_idx > m) {
        cout << -1 << endl;
        return 0;
    }
    cout << cnt << endl;
    for (auto i : v) {
        cout << i << ' ';
    }
    cout << endl;

    return 0;
}