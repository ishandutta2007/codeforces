// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

const int H = 5000000;

int cnt[H+5];
int dv[H+5];
ll dp[H+5];

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int n;
    cin >> n;
    for (int i : ra(0, n)) {
        int x;
        cin >> x;
        cnt[x]++;
    }

    for (int i : ra(1, H+1)) {
        for (int j=i; j<=H; j+=i) {
            dv[i] += cnt[j];
        }
    }

    dp[1] = n;
    for (int i : ra(1, H+1)) {
        for (int j=2*i; j<=H; j+=i) {
            dp[j] = max(dp[j], dp[i] + dv[j] * ll(j-i));
        }
    }

    cout << *max_element(dp+1, dp+H+1) << '\n';
}