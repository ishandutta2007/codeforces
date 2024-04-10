#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first;
    }
    for (int i = 0; i < n; i++) {
        cin >> v[i].second;
    }

    double L = 0, R = 1e9 + 2;
    while (L + 1e-8 < R) {
        double M = (L + R) / 2;

        double upper_bound = 1e9 + 2, lower_bound = 0;
        for (auto p : v) {
            upper_bound = min(upper_bound, p.first + M * p.second);
            lower_bound = max(lower_bound, p.first - M * p.second);
        }

        if (lower_bound < upper_bound) 
            R = M;
        else
            L = M;
    }

    cout << R << endl;
}