#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

#include "bits/stdc++.h"
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int testcase = 1; testcase <= T; testcase++) {
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        for (auto& x : v)
            cin >> x;
        for (int i = 0; i < n; i++) {
            int c = min(k, v[i]);
            v[i] -= c;
            k -= c;
            v[n-1] += c;
        }
        for (auto x : v) {
            cout << x << ' ';
        }
        cout << '\n';
    }
}