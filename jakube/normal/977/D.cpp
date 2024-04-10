#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<long long> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    map<int, vector<long long>> s;
    for (auto x : v) {
        int cnt = 0;
        auto y = x;
        while (y % 3 == 0) {
            cnt++;
            y /= 3;
        }
        s[-cnt].push_back(x);
    }
    for (auto [a, res] : s) {
        sort(res.begin(), res.end());
        for (auto x : res) {
            cout << x << ' ';
        }
    }
    cout << '\n';
}