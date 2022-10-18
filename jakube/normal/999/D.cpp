#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    int c = n / m;
    vector<int> cnt(m, 0);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int x : a)
        cnt[x % m]++;
    set<int> to_few;
    for (int i = 0; i < m; i++) {
        if (cnt[i] < c) {
            to_few.insert(i);
        }
    }

    long long res = 0;
    for (int i = 0; i < n; i++) {
        int& x = a[i];
        if (cnt[x % m] > c) {
            // find next
            auto it = to_few.lower_bound(x % m);
            int value;
            if (it == to_few.end()) {
                it = to_few.begin();
                value = *it + m - x % m;
            } else
                value = *it - x % m;

            res += value;
            cnt[x % m]--;
            x += value;
            cnt[x % m]++;
            if (cnt[x % m] == c)
                to_few.erase(x % m);
        }
    }
    cout << res << '\n';
    for (auto x : a) {
        cout << x << ' ';
    }
    cout << '\n';
}