#include <bits/stdc++.h>

using namespace std;

#define int long long
#define sz(x) ((int) (x).size())

struct item {
    signed val;
    int mask;
};

int solve(vector<item> &a, int bits) {
    assert(bits > 0);
    
    int x = 0, y = 0, z = 0, w = 0;
    int first = 1ll << (bits - 1);
    int second = 1ll << (bits - 2);
    vector<item> rest;
    rest.reserve(sz(a));
    for (auto [val, mask]: a) {
        if (!(mask & first) && !(mask & second)) {
            rest.push_back({val, mask});
            w += val;
        }
    }
    
    int ans = 0;
    if (w > 0) {
        ans = solve(rest, bits - 2);
    }
    x = 0, y = 0, z = 0, w = 0;
    for (auto [val, mask]: a) {
        if (__builtin_popcountll(mask & ans) & 1) {
            val = -val;
        }
        if (mask & first) {
            if (mask & second) x += val;
            else y += val;
        } else {
            if (mask & second) z += val;
            else w += val;
        }
    }
    
    int mi = min({x + y + z, -x - y + z, -x + y - z, x - y - z});
    if (x + y + z == mi) {
        return ans;
    }
    if (-x - y + z == mi) {
        return ans ^ first;
    }
    if (-x + y - z == mi) {
        return ans ^ second;
    }
    return ans ^ first ^ second;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int n;
    cin >> n;
    vector<item> a(n);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].val >> a[i].mask;
        sum += a[i].val;
    }
    if (sum < 0) {
        for (int i = 0; i < n; ++i) {
            a[i].val = -a[i].val;
        }
    }
    
    int ans = solve(a, 62);
    cout << ans << '\n';
    
    /*int temp = 0;
    for (auto [val, mask]: a) {
        if (__builtin_popcountll(mask & ans) & 1) {
            temp -= val;
        } else {
            temp += val;
        }
    }
    assert(temp < 0);*/
}