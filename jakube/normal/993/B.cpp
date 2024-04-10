#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
        if (a[i].first > a[i].second)
            swap(a[i].first, a[i].second);
    }
    vector<pair<int, int>> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i].first >> b[i].second;
        if (b[i].first > b[i].second)
            swap(b[i].first, b[i].second);
    }

    vector<bool> in_both(10, false);
    int cnt = 0;
    for (auto p : a) {
        for (auto q : b) {
            if (p == q) continue;
            if (p.first == q.first || p.first == q.second)
                in_both[p.first] = true;
            if (p.second == q.first || p.second == q.second)
                in_both[p.second] = true;
        }
    }
    for (int i = 0; i < 10; i++) {
        cnt += in_both[i];
    }

    if (cnt == 1) {
        for (int i = 1; i < 10; i++)
            if (in_both[i])
                cout << i << '\n';
        return 0;
    }

    // does A know?
    bool A_knows = true;
    for (auto p : a) {
        vector<bool> in(10, false);
        for (auto q : b) {
            if (p == q) continue;
            if (p.first == q.first || p.first == q.second)
                in[p.first] = true;
            if (p.second == q.first || p.second == q.second)
                in[p.second] = true;
        }
        if (accumulate(in.begin(), in.end(), 0LL) > 1)
            A_knows = false;
    }
    bool B_knows = true;
    for (auto p : b) {
        vector<bool> in(10, false);
        for (auto q : a) {
            if (p == q) continue;
            if (p.first == q.first || p.first == q.second)
                in[p.first] = true;
            if (p.second == q.first || p.second == q.second)
                in[p.second] = true;
        }
        if (accumulate(in.begin(), in.end(), 0LL) > 1)
            B_knows = false;
    }

    if (A_knows && B_knows) {
        cout << 0 << '\n';
        return 0;
    }

    cout << -1 << '\n';
}