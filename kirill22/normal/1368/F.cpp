#include<bits/stdc++.h>

using namespace std;

#define pb push_back

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    pair<int, int> best = {-1, -1};
    for (int k = 1; k <= n; k++) {
        int res = (n / k) * (k - 1);
        if (n % k) res += n % k - 1;
        res -= k - 1;
        best = max(best, {res, k});
    }
    int k = best.second;
    if (best.first == 0) {
        cout << 0 << endl;
        return 0;
    }
    vector<bool> used(n, false), ban(n, false);
    for (int i = k - 1; i < n; i += k) ban[i] = true;
    if (n % k) ban[n - 1] = true;
    while (true) {
        cout << k;
        int v = 0;
        for (int i = 0; i < n && v < k; i++) {
            if (!used[i] && !ban[i]) {
                cout << " " << i + 1;
                used[i] = true;
                v++;
            }
        }
        cout << endl;
        cin >> v;
        v--;
        for (int j = v; j < v + k; j++) {
            used[j % n] = false;
        }
        v = 0;
        for (auto x : used) v += x;
        if (v == best.first) break;
    }
    cout << 0 << endl;
}