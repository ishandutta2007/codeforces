// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int n;
int a[505];

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }

    vector<tuple<int, int, int>> qs;
    for (int i=1; i<=n; i++) {
        for (int j=i+1; j<=n; j++) {
            int x = i, y = j;
            if (a[x] > a[y]) {
                swap(x, y);
            }
            qs.emplace_back(a[y] - a[x], x, y);
        }
    }

    sort(begin(qs), end(qs), greater<tuple<int, int, int>>());
    for (auto [w, i, j] : qs) {
        cout << "? " << j << ' ' << i << '\n' << flush;
        string re;
        cin >> re;
        if (re == "Yes") {
            cout << "! " << i << ' ' << j << '\n' << flush;
            return 0;
        }
    }

    cout << "! 0 0\n" << flush;
}