#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        v[i]--;
    }

    for (int i = 0; i < m; i++) {
        int l, r, x;
        cin >> l >> r >> x;
        l--;
        r--;
        x--;

        if (x < l || x > r) {
            cout << "Yes\n";
        } else {
            for (int j = l; j <= r; j++) {
                if (v[j] < v[x])
                    l++;
            }
            if (l == x)
                cout << "Yes\n";
            else
                cout << "No\n";
        }
    }
}