#include <bits/stdc++.h>
using namespace std;
int a[10000], b[10000];
int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        if (c == 'B')
            a[i] = 0;
        else
            a[i] = 1;
    }
    vector<int> ans;
    for (int i = 0; i < 2; i++) {
        ans.clear();
        for (int j = 0; j < n; j++) b[j] = a[j];
        for (int j = 0; j < n - 1; j++) {
            if (b[j] != i) {
                ans.push_back(j + 1);
                b[j] ^= 1;
                b[j + 1] ^= 1;
            }
        }
        if (n == 0 || b[n - 1] == i) {
            cout << ans.size() << endl;
            for (auto x : ans) {
                cout << x << ' ';
            }
            return 0;
        }
    }
    cout << -1;
}