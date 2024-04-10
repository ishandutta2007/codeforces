// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

const int N = 32768;

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    vector<int> d(N, -1);
    vector<vector<int>> e(N);

    for (int x : ra(0, N)) {
        e[(2*x)%N].push_back(x);
        e[(x+1)%N].push_back(x);
    }

    queue<int> q;
    q.push(0);
    d[0] = 0;
    while (q.size()) {
        int x = q.front();
        q.pop();
        for (int y : e[x]) {
            if (d[y] == -1) {
                d[y] = d[x] + 1;
                q.push(y);
            }
        }
    }

    int t;
    cin >> t;
    while (t--) {
        ll x, z = 0;
        cin >> x;
        cout << d[x] << ' ';
    }
    cout << '\n';
}