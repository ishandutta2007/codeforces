#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e17;

long long solve(int k, const vector<int> &a) {
    if (k == 0) {
        return INF;
    }
    long long ans = 0;
    for (auto v: a) {
        int r = v % k;
        int t = (v / (k + 1) - r) / k;
        long long y = k * t + r;
        if (v < y * (k + 1)) return INF;
        ans += (v - y) / k;
    }
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long ans = INF;
    int mi = *min_element(a.begin(), a.end());
    for (int i = 1; i * i <= mi; ++i) {
        ans = min(ans, solve(i, a));
    }
    for (int i = 1; i * i <= mi; ++i) {
        int k = mi / i;
        ans = min(ans, solve(k, a));
        ans = min(ans, solve(k - 1, a));
    }

    cout << ans << '\n';
}