#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> ans(n - 1, 1);
    for (int i = 2; i < n; i++) {
        for (int j = 2; j * i <= n; j++) ans[i * j - 2] = i;
    }
    sort(ans.begin(), ans.end());
    for (auto x : ans) cout << x << " ";
}