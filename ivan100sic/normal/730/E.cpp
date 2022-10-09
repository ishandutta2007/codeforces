// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int n;
int a[105], d[105];

int dp[105][105];
int pos_id[105], neg_id[105];

void mx(int& x, int y) {
    x = max(x, y);
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    vector<int> pos, neg;
    
    cin >> n;
    for (int i : ra(0, n)) {
        cin >> a[i] >> d[i];
        if (d[i] > 0) {
            pos.push_back(i);
        } else if (d[i] < 0) {
            neg.push_back(i);
        }
    }

    auto cmp = [&](int i, int j) {
        return pair(-a[i], i) < pair(-a[j], j);
    };

    R::sort(neg, cmp);
    R::sort(R::reverse_view(pos), cmp);

    for (int i : ra(0, ssize(pos))) pos_id[pos[i]] = i;
    for (int i : ra(0, ssize(neg))) neg_id[neg[i]] = i;

    for (int i=0; i<=ssize(pos); i++) {
        for (int j=0; j<=ssize(neg); j++) {

            int best = -1;

            auto take = [&](int id) {
                pair lo(-a[id], id);
                pair hi(-a[id]-d[id], id);
                if (lo > hi) swap(lo, hi);
                int z = 0;
                for (int k=0; k<n; k++) {
                    int ins = 0;
                    if (d[k] > 0) ins = pos_id[k] < i;
                    else if (d[k] < 0) ins = neg_id[k] < j;

                    pair pk(-a[k]-d[k]*ins, k);
                    z += lo < pk && pk < hi;
                }
                return z;
            };

            if (i < ssize(pos)) mx(dp[i+1][j], dp[i][j] + take(pos[i]));
            if (j < ssize(neg)) mx(dp[i][j+1], dp[i][j] + take(neg[j]));
        }
    }

    cout << dp[size(pos)][size(neg)] << '\n';
}