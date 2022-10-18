#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    
    int last = 0;
    for (auto doctor : v) {
        // last < s + i*d
        // (last - s) < i*d
        // (last - s) / d < i
        int i = floor((last - doctor.first) / (double)doctor.second) + 1;
        last = doctor.first + max(i, 0) * doctor.second;
    }

    cout << last << endl;
}