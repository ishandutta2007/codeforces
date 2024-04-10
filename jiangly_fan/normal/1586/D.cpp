#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> p(n + 1);
    p[n] = 1;
    for (int i = 2; i <= n; i += 1) {
        cout << "?";
        for (int j = 1; j <= n; j += 1)
            cout << " " << (j < n ? 1 : i);
        cout << endl;
        int res;
        cin >> res;
        if (res == 0) {
            p[n] = n - i + 2;
            break;
        }
    }
    for (int i = 1; i <= n; i += 1) {
        if (i < p[n]) {
            cout << "?";
            for (int j = 1; j < n; j += 1) cout << " " << p[n] - i + 1;
            cout << " 1" << endl;
            int res;
            cin >> res;
            p[res] = i;
        }
        if (i > p[n]) {
            cout << "?";
            for (int j = 1; j < n; j += 1) cout << " 1";
            cout << " " << i - p[n] + 1 << endl;
            int res;
            cin >> res;
            p[res] = i;
        }
    }
    cout << "!";
    for (int i = 1; i <= n; i += 1) cout << " " << p[i];
    return 0;
}