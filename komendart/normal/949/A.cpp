#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())

void fail() {
    cout << -1 << '\n';
    exit(0);
}

signed main() {
    //freopen("t.in", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0);

    string s;
    cin >> s;
    int n = sz(s);
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        a[i] = s[i] - '0';
    }
    vector<int> oneend;
    vector<int> zeroend;
    vector<int> parent(n);
    for (int i = 0; i < n; ++i) {
        if (a[i] == 1) {
            if (zeroend.empty()) fail();
            parent[i] = parent[zeroend.back()];
            zeroend.pop_back();
            oneend.push_back(i);
        } else {
            if (oneend.empty()) {
                parent[i] = i;
                zeroend.push_back(i);
            } else {
                parent[i] = parent[oneend.back()];
                oneend.pop_back();
                zeroend.push_back(i);
            }
        }
    }
    if (!oneend.empty()) fail();
    vector< vector<int> > ans(n);
    int k = 0;
    for (int i = 0; i < n; ++i) {
        if (i == parent[i]) ++k;
        ans[parent[i]].push_back(i);
    }
    cout << k << '\n';
    for (int i = 0; i < n; ++i) {
        if (i != parent[i]) continue;
        cout << sz(ans[i]) << ' ';
        for (auto j: ans[i]) cout << j + 1 << ' ';
        cout << '\n';
    }
}