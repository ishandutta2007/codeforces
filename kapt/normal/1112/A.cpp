#include <bits/stdc++.h>
using namespace std;

main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> sc[m];
    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    int sch[n];
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        sch[i] = x - 1;
        sc[x - 1].push_back(arr[i]);
    }
    int ans = 0;
    for (int i = 0; i < k; ++i) {
        int ind;
        cin >> ind;
        ind--;
        int s = sch[ind];
        if (arr[ind] != *max_element(sc[s].begin(), sc[s].end())) {
            ans++;
        }
    }
    cout << ans;
    return 0;
}