#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first;
        v[i].second = i + 1;
    }
    
    sort(v.begin(), v.end());
    int negative = lower_bound(v.begin(), v.end(), make_pair(0, 0)) - v.begin();
    int positive = v.end() - lower_bound(v.begin(), v.end(), make_pair(1, 0));
    int zeros = n - negative - positive;

    vector<int> remove_indices;
    vector<bool> remaining(n+1, true);
    auto remove2 = [&](int i, int j) {
        for (int idx = i; idx <= j; idx++) {
            int y = v[idx].second;
            remove_indices.push_back(y);
            remaining[y] = false;
        }
    };

    int last_non_positive = negative + zeros - 1;
    int last_negative = negative - 1;
    int first_non_negative = negative;

    if (positive == 0 && negative < 2) {
        remove2(0, n-2);
    } else {
        if (negative % 2)
            remove2(last_negative, last_non_positive);
        else
            remove2(first_non_negative, last_non_positive);
    }

    if (remove_indices.size()) {
        int last = remove_indices.back();
        for (int x : remove_indices) {
            if (x == last)
                cout << "2 " << x << '\n';
            else
                cout << "1 " << x << " " << last << '\n';
        }
    }

    vector<int> others;
    for (int i = 1; i <= n; i++) {
        if (remaining[i])
            others.push_back(i);
    }

    int last = others.back();
    for (int x : others) {
        if (x != last)
            cout << "1 " << x << " " << last << '\n';
    }
}