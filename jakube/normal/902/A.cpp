#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int m;
    cin >> m;
    int cur = 0;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (a > cur) {
            cout << "NO" << '\n';
            return 0;
        }
        cur = max(cur, b);
    }
    if (cur >= m) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
    }
}