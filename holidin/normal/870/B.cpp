#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, k, m[400000], j, i;
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (i = 0; i < n; ++i)
        cin >> m[i];
    if (k == 1) {
        j = m[0];
        for (i = 0; i < n; ++i)
            j = min(j, m[i]);
        cout << j;
        return 0;
    }
    if (k == 2) {
        cout << max(m[0], m[n - 1]);
        return 0;
    }
    j = m[0];
    for (i = 0; i < n; ++i)
        j = max(j, m[i]);
    cout << j;
}