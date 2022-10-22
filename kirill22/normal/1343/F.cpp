#include<bits/stdc++.h>

using namespace std;

#define int long long

vector<int> ans;
vector<vector<int>> a;
vector<bool> ban;
int n;

bool get(int j, int P) {
    if (j == 0) {
        vector<bool> used(n + 1, false);
        for (int i = 1; i < n; i++) used[ans[i]] = true;
        for (int i = 1; i <= n; i++) {
            if (!used[i]) {
                ans[0] = i;
                return true;
            }
        }
    }
    vector<int> b(n + 1, 0);
    for (int i = 0; i < n - 1; i++) {
        if (!ban[i]) {
            for (auto x : a[i]) b[x]++;
        }
    }
    int x = -1, y = -1;
    for (int i = 1; i <= n; i++) {
        if (b[i] == 1) {
            if (x == -1) x = i;
            else y = i;
        }
    }
    if (y == P) y = -1;
    else if (x == P) {
        x = y;
        y = -1;
    }
    if (x == -1) return false;
    int _x = 0, _y = 0;
    for (int i = 0; i < n - 1; i++) {
        if (ban[i]) {
            for (auto el : a[i]) {
                if (el == x) _x++;
                if (el == y) _y++;
            }
        }
    }
    if (_y > _x) swap(x, y);
    if (y == -1 || _y != _x) {
        ans[j] = x;
        int l;
        for (int i = 0; i < n - 1; i++) {
            for (auto el : a[i]) if (el == x && ban[i] == false) {
                l = i;
            }
        }
        ban[l] = true;
        bool f = get(j - 1, P);
        ban[l] = false;
        return f;
    }
    ans[j] = x;
    int l;
    for (int i = 0; i < n - 1; i++) {
        for (auto el : a[i]) if (el == x && ban[i] == false) {
            l = i;
        }
    }
    ban[l] = true;
    bool f = get(j - 1, y);
    if (f) return true;
    ban[l] = false;
    ans[j] = y;
    for (int i = 0; i < n - 1; i++) {
        for (auto el : a[i]) if (el == y) ban[i] = true;
    }
    return get(j - 1, x);
}

void solve() {
    cin >> n;
    a.resize(n - 1);
    ans.resize(n);
    ban.resize(n - 1, false);
    for (int i = 0; i < n - 1; i++) {
        int k;
        cin >> k;
        a[i].resize(k);
        for (int j = 0; j < k; j++) cin >> a[i][j];
    }
    get(n - 1, -1);
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    a.clear();
    ans.clear();
    ban.clear();
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while (q--) {
        solve();
    }
}