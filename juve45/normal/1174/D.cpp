#include <bits/stdc++.h>

using namespace std;
int a[500000];
int main() {
    ios_base::sync_with_stdio(false);
    int n, x;
    cin >> n >> x;
    vector<int> ans;
    int prv = 0;
    a[x] = 1;
    for (int i = 1; i < (1 << n); i++) {
        if (a[i]) {
            continue;
        }
        a[i ^ x] = 1;
        ans.push_back(prv ^ i);
        prv = i;
    }
    cout << ans.size() << "\n";
    for (auto it: ans) {
        cout << it << " ";
    }
    cout << "\n";
    return 0;
}