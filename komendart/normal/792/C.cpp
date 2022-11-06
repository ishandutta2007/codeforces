#include <bits/stdc++.h>

using namespace std;

void solve(const vector<int> &a, vector<int> &used) {
    int mod = 0;
    int n = a.size();
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            mod = (mod + a[i]) % 3;
        }
    }
    int p = 0;
    while (p < n && (a[p] == 0 || used[p] || mod != 0)) {
        if (!used[p]) {
            mod = ((mod - a[p]) % 3 + 3) % 3;
        }
        used[p] = true;
        ++p;
    }
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    string str;
    cin >> str;
    int n = str.size();
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        a[i] = str[i] - '0';
    }
    vector<int> one, two;
    for (int i = n - 1; i >= 0; --i) {
        if (a[i] % 3 == 1) one.push_back(i);
        else if (a[i] % 3 == 2) two.push_back(i);
    }

    vector<int> ans(n, true);
    for (int i = 0; i <= 2 && i <= one.size(); ++i) {
        for (int j = 0; j <= 2 && j <= two.size(); ++j) {
            vector<int> used(n);
            for (int k = 0; k < i; ++k) used[one[k]] = true;
            for (int k = 0; k < j; ++k) used[two[k]] = true;
            solve(a, used);
            if (accumulate(used.begin(), used.end(), 0) < accumulate(ans.begin(), ans.end(), 0)) {
                ans = used;
            }
        }
    }
    if (accumulate(ans.begin(), ans.end(), 0) == n) {
        for (int i = 0; i < n; ++i) {
            if (a[i] == 0) {
                cout << "0\n";
                return 0;
            }
        }
        cout << -1 << '\n';
    } else {
        for (int i = 0; i < n; ++i) {
            if (!ans[i]) {
                cout << a[i];
            }
        }
    }
}