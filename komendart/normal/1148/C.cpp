#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())

int n;
vector<int> a;
vector<int> id;
vector<pair<int, int>> ans;

void change(int x, int y) {
    assert(abs(x - y) >= n / 2);
    id[a[x]] = y;
    id[a[y]] = x;
    swap(a[x], a[y]);
    ans.emplace_back(x, y);
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    cin >> n;
    a.resize(n + 1);
    id.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        id[a[i]] = i;
    }
    
    for (int i = 1; i <= n / 2; ++i) {
        if (id[i] == i) continue;
        if (id[i] - i >= n / 2) {
            change(i, id[i]);
        } else if (n - id[i] >= n / 2) {
            change(id[i], n);
            change(n, i);
        } else {
            int tmp = id[i];
            change(1, tmp);
            change(1, n);
            change(i, n);
            change(1, tmp);
        }
    }
    for (int i = n / 2 + 1; i <= n; ++i) {
        if (id[i] == i) continue;
        int tmp = id[i];
        change(tmp, 1);
        change(1, i);
        change(1, tmp);
    }
    
    for (int i = 1; i <= n; ++i) {
        assert(a[i] == i);
    }
    
    cout << sz(ans) << '\n';
    for (auto [x, y]: ans) {
        cout << x << ' ' << y << '\n';
    }
}