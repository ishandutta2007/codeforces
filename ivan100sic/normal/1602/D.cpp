// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

constexpr int maxn = 1 << 19;

int n;
int a[300005], b[300005];

int d[3*maxn], p[3*maxn];

template<class CB>
void rec(int l, int r, CB cb, int x=1, int xl=0, int xr=maxn) {
    if (l <= xl && xr <= r) {
        cb(x);
        return;
    }

    if (xr <= l || r <= xl) {
        return;
    }

    int xm = (xl+xr) >> 1;
    rec(l, r, cb, 2*x, xl, xm);
    rec(l, r, cb, 2*x+1, xm, xr);
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n;
    for (int i : ra(1, n+1)) cin >> a[i];
    for (int i : ra(1, n+1)) cin >> b[i];

    memset(d, 63, sizeof(d));
    memset(p, 255, sizeof(p));

    deque<int> q;
    const int start = n + 2*maxn;
    q.push_back(start);
    d[start] = 0;
    p[start] = -2;

    auto go = [&](int x, int y, int w) {
        if (d[y] > d[x] + w) {
            d[y] = d[x] + w;
            p[y] = x;
            w ? q.push_back(y) : q.push_front(y);
        }
    };

    while (q.size()) {
        int x = q.front(); q.pop_front();

        if (x >= 2*maxn) {
            int k = x - 2*maxn;
            rec(k-a[k], k+1, [&](int y) {
                go(x, y, 1);
            });
        } else if (x < maxn) {
            for (int y : {2*x, 2*x+1}) {
                go(x, y, 0);
            }
        } else {
            go(x, x + b[x-maxn] + maxn, 0);
        }
    }

    const int goal = 2*maxn;
    if (p[goal] == -1) {
        cout << "-1\n";
        return 0;
    }

    cout << d[goal] << "\n";
    vector<int> steps;
    for (int x = goal; x != -2; x = p[x]) {
        if (x >= maxn && x < 2*maxn) {
            steps.push_back(x - maxn);
        }
    }

    for (int x : steps | views::reverse) cout << x << ' ';
    cout << '\n';
}