#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#include <cstddef>
#include <cstring>
#include <bitset>
#include <random>

typedef long long ll;

using namespace std;

const int MX = 2e5 + 7;
ll t[4 * MX];
int n;

void build(int n) {
    for (int i = 0; i < n; i++)
        t[i + n] = i + 1;
    for (int i = n - 1; i > 0; i--)
        t[i] = t[2 * i] + t[2 * i + 1];
}

void update(int pos, int val) {
    t[pos += n] = val;
    for (pos /= 2; pos; pos /= 2)
        t[pos] = t[2 * pos] + t[2 * pos + 1];
}

ll get(int l, int r) {
    ll res = 0;
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
        if (l & 1) res += t[l++];
        if (r & 1) res += t[--r];
    }
    return res;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);

    cin >> n;
    vector<ll> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    vector<int> sum(n + 1);
    for (int i = 0; i < n; i++)
        sum[i + 1] = sum[i] + (i + 1);

    build(n);
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--) {
        int l = 0, r = n + 1;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (get(0, m) <= p[i])
                l = m;
            else
                r = m;
        }
        update(l, 0);
        ans[i] = l + 1;
    }

    for (int i : ans) cout << i << ' ';


    return 0;
}