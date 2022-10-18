#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n, k, x;
    cin >> n >> k >> x;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    vector<vector<int>> all;

    all.push_back(v);

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j += 2) 
            v[j] ^= x;
        sort(v.begin(), v.end());

        auto it = find(all.begin(), all.end(), v);
        if (it != all.end()) {
            int idx = it - all.begin();
            for (int j = i + 1; j < k; j++) {
                idx++;
                if (idx > i) idx = it - all.begin();
            }
            cout << all[idx].back() << ' ' << all[idx].front() << '\n';
            return 0;
        }

        all.push_back(v);
    }
    
    cout << v.back() << ' ' << v.front() << endl;
}