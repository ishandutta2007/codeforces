#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int idx = 0; idx < n; idx++)
        cin >> v[idx].first >> v[idx].second;
    int m;
    cin >> m;
    vector<pair<int, int>> w(m);
    for (int idx = 0; idx < m; idx++)
        cin >> w[idx].first >> w[idx].second;
    
    sort(v.begin(), v.end());
    sort(w.begin(), w.end());
    
    int best = 0;
    for (auto p : v) {
        best = max(best, w.back().first - p.second);
    }

    for (auto p : w) {
        best = max(best, v.back().first - p.second);
    }

    cout << best << endl;
}