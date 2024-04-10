#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    int n = s.size();
    
    vector<vector<int>> v;
    queue<int> missing;
    queue<int> non_missing;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            if (missing.empty()) {
                v.push_back(vector<int>(1, i));
                non_missing.push(v.size() - 1);
            } else {
                int j = missing.front();
                missing.pop();
                v[j].push_back(i);
                non_missing.push(j);
            }
        } else {
            if (non_missing.empty()) {
                cout << -1 << '\n';
                return 0;
            } else {
                int j = non_missing.front();
                non_missing.pop();
                v[j].push_back(i);
                missing.push(j);
            }
        }
    }

    if (missing.empty()) {
        cout << v.size() << endl;
        for (auto& vv : v) {
            cout << vv.size();
            for (int x : vv)
                cout << " " << x + 1;
            cout << '\n';
        }
    } else {
        cout << -1 << '\n';
    }
}