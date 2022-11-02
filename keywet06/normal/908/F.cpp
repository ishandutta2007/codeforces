#include <bits/stdc++.h>

using int64 = long long;

using namespace std;

vector<int64> rb, gb, b;

int64 g(const vector<int64>& v, int64 l, int64 r) {
    int il = lower_bound(v.begin(), v.end(), l) - v.begin();
    int ir = lower_bound(v.begin(), v.end(), r) - v.begin();
    int64 ret = 0;
    for (int i = il; i < ir; ++i) ret = max(ret, v[i + 1] - v[i]);
    return ret;
}

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed), cout.precision(20);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        char c;
        cin >> c;
        if (c == 'R') {
            rb.push_back(x);
        } else if (c == 'B') {
            gb.push_back(x);
        } else {
            rb.push_back(x);
            gb.push_back(x);
            b.push_back(x);
        }
    }
    int64 ans = 0;
    if (rb.size() > 1) ans += rb.back() - rb.front();
    if (gb.size() > 1) ans += gb.back() - gb.front();
    for (int i = 1; i < b.size(); ++i) {
        int64 l = b[i - 1], r = b[i];
        int64 sub = g(rb, l, r) + g(gb, l, r);
        ans -= max(0ll, sub - (r - l));
    }
    cout << ans << "\n";
    return 0;
}