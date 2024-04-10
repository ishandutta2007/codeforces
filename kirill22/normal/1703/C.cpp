#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            int k;
            string s;
            cin >> k >> s;
            for (auto c : s) {
                a[i] += (c == 'U' ? 9 : 1);
            }
        }
        for (auto x : a) {
            cout << x % 10 << " ";
        }
        cout << '\n';
    }
}