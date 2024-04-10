#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int MAXN = 2e5;
int len[MAXN];

main() {
    int n, m;
    cin >> n >> m;
    int cur = 0;
    int sum = 0;
    for (int i = 0; i < m; ++i) {
        cin >> len[i];
        sum += len[i];
    }
    if (sum < n) {
        cout << -1;
        return 0;
    }
    vector<int> ans;
    for (int i = 0; i < m; ++i) {
        int p = max(n - sum + 1, i + 1);
        ans.push_back(p);
        if (p > n - len[i] + 1) {
            cout << -1;
            return 0;
        }
        sum -= len[i];
    }
    for (auto elem : ans) {
        cout << elem << " ";
    }
    return 0;
}