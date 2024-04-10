#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k;
    cin >> k;
    vector<vector<int>> seqs(k);
    for (int i = 0; i < k; i++) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int j = 0; j < n; j++) {
            cin >> v[j];
        }
        seqs[i] = v;
        int sum = accumulate(v.begin(), v.end(), 0);
        for (int &x : seqs[i]) {
            x = sum - x;
        }
    }

    map<int, pair<int, int>> m;
    for (int i = 0; i < k; i++) {
        auto s = seqs[i];
        for (int j = 0; j < (int)s.size(); j++) {
            if (m.count(s[j])) {
                cout << "YES" << '\n';
                cout << m[s[j]].first << " " << m[s[j]].second << '\n';
                cout << i + 1 << " " << j + 1 << '\n';
                
                return 0;
            }
        }
        for (int j = 0; j < (int)s.size(); j++) {
            m[s[j]] = {i+1, j+1};
        }
    }
    cout << "NO" << '\n';
}