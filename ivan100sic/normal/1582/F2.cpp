// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int dp[8192];
vector<short> q[8192];

void mn(int& x, int y) {
    x = min(x, y);
}

// cuvaj za svako x, sve brojeve i tako da je dp[i] > x && dp[i^x] < x

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    dp[0] = -1;

    for (int x : ra(1, 8192)) {
        q[x].push_back(x);
        dp[x] = 8191;
    }

    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;

        for (int i : q[x]) {
            // dodaje se u queue-ove
            int& y = dp[i];
            while (y > x) {
                if (dp[i^y] > y) {
                    q[y].push_back(i^y);
                }
                y--;
            }
        }
        q[x] = {};
    }

    // OK
    vector<int> a;
    for (int i : ra(0, 8192)) {
        if (dp[i] < 8191) {
            a.push_back(i);
        }
    }

    cout << a.size() << '\n';
    for (int x : a) cout << x << ' ';
    cout << '\n';
}