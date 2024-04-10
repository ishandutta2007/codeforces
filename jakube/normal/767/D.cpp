#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n, m, k;
    cin >> n >> m >> k;
    
    vector<int> f(n);
    for (int i = 0; i < n; i++) {
        cin >> f[i];
    }
    vector<pair<int, int>> s(m);
    for (int i = 0; i < m; i++) {
        cin >> s[i].first;
        s[i].second = i + 1;
    }
    
    sort(s.begin(), s.end());
    // reverse(s.begin(), s.end());

    vector<int> cnts(2e6+10, 0);
    for (int x : f) {
        if (x < cnts.size()) {
            cnts[x]++;
        } else {
            cnts.back()++;
        }
    }

    for (int i = cnts.size() - 1; i > 0; i--) {
        if (cnts[i] > k) {
            cnts[i-1] += cnts[i] - k;
            cnts[i] = k;
        }
    }

    if (cnts[0] > k) {
        cout << -1 << endl;
        return 0;
    }

    vector<int> result;

    int idx = 0;
    for (auto p : s) {
        while (cnts[idx] == k) {
            idx++;
        }

        if (p.first >= idx) {
            result.push_back(p.second);
            cnts[idx]++;
        }
    }

    cout << result.size() << endl;
    for (int i : result) {
        cout << i << ' ';
    }
    cout << endl;


    return 0;
}