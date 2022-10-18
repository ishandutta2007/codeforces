#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

#include "bits/stdc++.h"
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> v(n);
    for (auto& x : v)
        cin >> x;

    int Xor = 0;
    for (int i = 0; i < n-1; i++) {
        Xor ^= v[i];
        int cur = 0;
        for (int j = i+1; j < n; j++) {
            if (cur == Xor && v[j] != 0)
                cur = 0;
            cur ^= v[j];
        }
        if (cur == Xor) {
            cout << "YES" << '\n';
            return;
        }
    }
    cout << "NO" << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int testcase = 1; testcase <= T; testcase++) {
        solve();
    }
}