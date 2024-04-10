// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

mt19937 eng(chrono::high_resolution_clock::now().time_since_epoch().count());
using uid = uniform_int_distribution<ll>;
using urd = uniform_real_distribution<double>;

int main() {
    ios::sync_with_stdio(!cin.tie(0));
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<array<int, 5>> a(n);
        for (int i=0; i<n; i++) {
            for (int j=0; j<5; j++) {
                cin >> a[i][j];
            }
        }

        auto dom = [&](int x, int y) {
            int z = 0;
            for (int i=0; i<5; i++) {
                if (a[x][i] < a[y][i]) {
                    z++;
                }
            }
            return z >= 3;
        };

        vector<int> cand(n);
        iota(begin(cand), end(cand), 0);

        int steps = 100;
        while (steps--) {
            if (cand.empty()) break;
            int x = cand[uid(0, (int)cand.size() - 1)(eng)];
            vector<int> c2;
            for (int y : cand) {
                if (x == y) continue;
                int rx = 0;
                if (dom(y, x)) {
                    c2.push_back(y);
                }
            }
            if (c2.size()) {
                swap(cand, c2);
            } else {
                cand = {x};
                break;
            }
        }

        int f = -2;
        for (int x : cand) {
            int rx = 0;
            for (int y=0; y<n; y++) {
                if (x == y) continue;
                rx += dom(x, y);
            }
            if (rx == n-1) {
                f = x;
                break;
            }
        }

        cout << f+1 << '\n';
    }
}