// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int a[2222], n;
vector<int> sol;

int pos(int x) {
    return find(a+1, a+n+1, x) - a;
}

void work(int l) {
    if (l == 1) return;
    reverse(a+1, a+l+1);
    sol.push_back(l);
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        sol = {};

        cin >> n;
        bool ok = 1;
        for (int i=1; i<=n; i++) {
            cin >> a[i];
            if ((a[i] - i) % 2) {
                ok = 0;
            }
        }

        if (!ok) {
            cout << "-1\n";
            continue;
        }

        for (int y=n; y>3; y-=2) {
            work(pos(y));
            work(pos(y-1)-1);
            work(pos(y) + 2);
            work(3);
            work(y);
        }

        if (a[1] == 3) work(3);

        cout << sol.size() << '\n';
        for (int x : sol) cout << x << ' ';
        cout << '\n';
    }
}

//                  10 ....... 11 ....... |
// 11 ............. 10 .................. |
// ............. 11 10 .................. |
// x 10 11 .............................. |
// 11 10 ................................ |
// ..................................10 11|