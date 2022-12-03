#include <bits/stdc++.h>
using namespace std;

main() {
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<array<int, 2>> ind(n);
        ind[0] = {1, 1};
        for (int i = 1; i < n; ++i) {
            ind[i][0] = max(ind[i][0], a[i - 1] - a[i]);
            ind[i][1] = i + 1;
        }
        sort(ind.begin(), ind.end());
        for (int i = 0; i < n; ++i) {
            cout << ind[i][1] << " ";
        }
        cout << endl;
    }
    return 0;
}