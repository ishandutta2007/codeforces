// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int n, m;
    cin >> n >> m;

    vector<int> w(m);
    for (int i : ra(0, m)) {
        string a(m, '0');
        a[i] = '1';
        cout << "? " << a << '\n' << flush;
        cin >> w[i];
    }

    vector<int> id(m);
    iota(begin(id), end(id), 0);

    R::sort(id, [&](int i, int j) { return w[i] < w[j]; });

    string mst(m, '0');
    int wt = 0;

    for (int i : id) {
        auto a = mst;
        a[i] = '1';
        cout << "? " << a << '\n' << flush;
        int wq;
        cin >> wq;

        if (wq == wt + w[i]) {
            wt = wq;
            mst = a;
        }
    }

    cout << "! " << wt << '\n' << flush;
}