#include<bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int> (4, 0));
    for (int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
        a[i][3] = i;
    }
    sort(a.begin(), a.end());
    map<int, vector<vector<int>>> b;
    for (int i = 0; i < n; i++) {
        b[a[i][0]].push_back({a[i][1], a[i][2], a[i][3]});
    }
    vector<int> used(n, false);
    for (auto c : b) {
        sort(c.second.begin(), c.second.end());
        int x = c.second.size();
        map<int, vector<vector<int>>> d;
        for (int i = 0; i < x; i++) {
            d[c.second[i][0]].push_back({c.second[i][1], c.second[i][2]});
        }
        for (auto k : d) {
            for (int i = 0; i < k.second.size() - 1; i += 2) {
                cout << k.second[i][1] + 1 << " " << k.second[i + 1][1] + 1 << endl;
                used[k.second[i][1]] = true;
                used[k.second[i + 1][1]] = true;
            }
        }
        int pr = -1;
        for (auto k : d) {
            for (auto x : k.second) {
                if (!used[x[1]]) {
                    if (pr == -1) {
                        pr = x[1];
                    }
                    else {
                        cout << pr + 1 << " " << x[1] + 1 << endl;
                        used[pr] = true;
                        used[x[1]] = true;
                        pr = -1;
                    }
                }
            }
    }
    }
    int pr = -1;
    for (auto c : b) {
        for (auto x : c.second) {
            if (!used[x[2]]) {
                if (pr == -1) {
                    pr = x[2];
                }
                else {
                    cout << pr + 1 << " " << x[2] + 1 << endl;
                    pr = -1;
                }
            }
        }
    }
}