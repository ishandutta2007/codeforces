// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

unsigned hsh(unsigned x) {
    return x * 898923299ull;
}

const int inf = INT_MAX;

struct mfq {
    vector<pair<int, int>> a;
    int m, f, msk;

    mfq(int n) {
        m = 1;
        while (m < n) m <<= 1;
        a.assign(m, {inf, 0});
        msk = m-1;
        f = 0;
    }

    void operator+= (int x) {
        int i = hsh(x) & msk;
        while (a[i].first != x && a[i].first != inf) i = (i+1) & msk;
        a[i] = {x, a[i].second + 1};
        f = max(f, a[i].second);
    }

    int operator() () const {
        return f;
    }
};

int n;
int a[100005];

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n;
    for (int i : ra(0, n)) cin >> a[i];

    int sol = 0;
    for (int d : ra(-250, 251)) {
        mfq eng(3*n/2);
        for (int i : ra(0, n)) {
            eng += a[i] - d*i;
        }
        sol = max(sol, eng());
    }

    for (int i : ra(0, n)) {
        mfq eng(min(i, 400) * 3 / 2);
        for (int j=max(0, i-400); j<i; j++) {
            int p = a[i] - a[j];
            int q = i - j;
            if (p % q == 0) {
                eng += p / q;
            }
        }
        sol = max(sol, eng() + 1);
    }

    cout << n-sol << '\n';
}