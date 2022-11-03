#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

int solve(int n) {
    if (n == 1 || n == 2) {
        return 1;
    }
    if (n == 3) {
        return 0;
    }
    int k = 3;
    int depth = 1;
    while (2 * k + 1 <= n) {
        k <<= 1;
        k += 1;
        ++depth;
    }
    if (n == k) {
        return 0;
    }
    int all_leaves = k + 1;
    int leaves = n - k;
    if (leaves < all_leaves / 4 || leaves > all_leaves / 2) {
        return 0;
    }
    int exp_count;
    if (depth == 1) {
        exp_count = 0;
    } else if (depth == 2) {
        exp_count = 0;
    } else {
        exp_count = 1;
        int cur = 3;
        while (cur < depth) {
            ++cur;
            exp_count *= 2;
            exp_count += depth % 2;
        }
    }
    int val = leaves - all_leaves / 4 - exp_count;
    if (val == 0 || val == 1) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> v = {1, 2};
    int cur = 4;
    int deg = 1;
    while (v.back() <= 1000000) {
        v.push_back(cur);
        v.push_back(cur + 1);
        cur *= 2;
        cur += 1;
        ++deg;
        if (deg % 2 == 1) {
            ++cur;
        }
    }
    for (auto u: v) {
        if (n == u) {
            cout << 1 << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
//    cout << solve(n) << endl;
//    for (int i = 1; i <= 1000000; ++i) {
//        if (solve(i)) {
//            cout << i << " ";
//            cout.flush();
//        }
//    }
//    cout << endl;
}