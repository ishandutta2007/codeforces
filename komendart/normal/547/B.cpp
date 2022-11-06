#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> h(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    map<int, vector<int> > places;
    for (int i = 0; i < n; i++) {
        if (places.find(h[i]) == places.end()) {
            places.insert(make_pair(h[i], vector<int>()));
        }
        places[h[i]].push_back(i);
    }

    set<int> lessnums;
    vector<int> result(n + 1, -1);
    for (auto &p: places) {
        int v = p.first;
        for (auto i: p.second) {
            int d1, d2;
            auto it = lessnums.upper_bound(i);
            if (it == lessnums.end()) d1 = n - i - 1;
            else d1 = (*it) - i - 1;
            if (lessnums.empty() || it == lessnums.begin()) d2 = i;
            else d2 = i - (*(--it)) - 1;
            result[d1 + d2 + 1] = max(result[d1 + d2 + 1], v);
        }
        for (auto i: p.second) {
            lessnums.insert(i);
        }
    }

    for (int i = n - 1; i > 0; i--) {
        result[i] = max(result[i], result[i + 1]);
    }

    for (int i = 1; i <= n; i++) {
        cout << result[i] << ' ';
    }
}