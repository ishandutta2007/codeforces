#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int MAXN = 2e5 + 100;
int prefx[MAXN], prefs[MAXN], arr[MAXN];
int rgh[MAXN], lft[MAXN];

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        prefx[i + 1] = (prefx[i] ^ arr[i]);
        prefs[i + 1] = prefs[i] + arr[i];
    }
    fill(rgh, rgh + n, n + 1);
    unordered_map<int, int> mp;
    for (int i = n; i >= 0; --i) {
        if (mp[prefx[i] * 2 + (i + 1) % 2]) {
            rgh[i] = mp[prefx[i] * 2 + (i + 1) % 2];
        }
        mp[prefx[i] * 2 + i % 2] = i;
    }
    mp.clear();
    for (int i = 0; i <= n; ++i) {
        if (mp[prefx[i] * 2 + (i + 1) % 2]) {
            lft[i] = mp[prefx[i] * 2 + (i + 1) % 2];
        }
        mp[prefx[i] * 2 + i % 2] = i;
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;
        if (prefx[l] != prefx[r]) {
            cout << "-1\n";
            continue;
        }
        if (prefs[l] == prefs[r]) {
            cout << "0\n";
            continue;
        }
        if ((r - l) % 2 == 1) {
            cout << "1\n";
            continue;
        }
        if (rgh[l] < r) {
            if (prefs[l] == prefs[rgh[l]] || prefs[r] == prefs[lft[r]]) {
                cout << "1\n";
            } else {
                cout << "2\n";
            }
            continue;
        }
        cout << "-1\n";
    }
    return 0;
}