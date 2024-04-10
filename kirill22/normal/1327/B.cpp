#include<bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        vector<vector<int>> g(n);
        vector<bool> used(n, false), used2(n, false);
        for (int i = 0; i < n; i++) {
            int k; cin >> k;
            for (int j = 0; j < k; j++) {
                int x; cin >> x; x--;
                if (!used[i] && !used2[x]) {
                    used[i] = used2[x] = true;
                }
            }
        }
        int j = -1, j2 = -1;
        for (int i = 0; i < n; i++) {
            if (!used[i]) j = i;
            if (!used2[i]) j2 = i;
        }
        if (j == -1) {
            cout << "OPTIMAL" << endl;
        }
        else {
            cout << "IMPROVE" << endl;
            cout << j + 1 << " " << j2  + 1 << endl;
        }
    }
}