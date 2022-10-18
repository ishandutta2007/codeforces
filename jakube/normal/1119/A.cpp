#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> c(n);
    for (auto& x : c) {
        cin >> x;
        x--;
    }

    int m = 0;
    for (int i = 1; i < n; i++) {
        if (c[i] != c[0])
            m = max(i - 0, m);
    }
    for (int i = 0; i + 1 < n; i++) {
        if (c[i] != c[n-1])
            m = max(n-1 - i, m);
    }
    cout << m << '\n';
}