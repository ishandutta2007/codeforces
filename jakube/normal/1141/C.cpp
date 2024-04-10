#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> q(n-1);
    for (auto& x : q)
        cin >> x;
    vector<int> t(n);
    t[0] = 0;
    for (int i = 1; i < n; i++) {
        t[i] = t[i-1] + q[i-1];
    }
    int mi = *min_element(t.begin(), t.end());
    for (auto& x : t) {
        x -= mi;
        x++;
    }

    auto tmp = t;
    sort(tmp.begin(), tmp.end());
    for (int i = 0; i < n; i++) {
        if (tmp[i] != i + 1) {
            cout << -1 << '\n';
            return 0;
        }
    }

    for (auto x : t) {
        cout << x << ' ';
    }
    cout << '\n';
}