#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;

    int cnt = (n-1) + (m-1) + n*m;
    cout << cnt << endl;

        // then n + m <= n*m
        for (int i = 0; i < n-1; i++) {
            cout << 'U';
        }
        for (int j = 0; j < m-1; j++) {
            cout << 'L';
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m-1; j++) {
                if (i % 2 == 0) cout << 'R';
                else cout << 'L';
            }
            cout << 'D';
        }
        cout << endl;

}