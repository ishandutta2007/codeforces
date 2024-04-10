#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, r;
    cin >> n >> r;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;

    int border = -1;
    int cnt = 0;
    int last_elem = -1;
    while (border < n - 1) {
        int last = -1;
        for (int i = last_elem + 1; i <= border + r && i < n; i++) {
            if (a[i])
                last = i;
        }

        if (last == -1) {
            cout << -1 << '\n';
            return 0;
        }
        cnt++;
        border = last + r - 1;
        last_elem = last;
    }
    cout << cnt << '\n';
}