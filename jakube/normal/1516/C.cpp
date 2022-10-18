#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

#include "bits/stdc++.h"
using namespace std;

constexpr int power(int x, int e) {
    return e ? x * power(x, e-1) : 1;
}

bool isPossible(vector<int>& v) {
    int sum = accumulate(v.begin(), v.end(), 0);
    bitset<200'001> bs;
    bs[0] = true;
    for (int x : v)
        bs |= bs << x;
    return sum % 2 == 0 && bs[sum/2];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> v(n);
    for (auto& x : v)
        cin >> x;

    int g = power(2, 20);
    for (auto& x : v)
        g = gcd(g, x);
    for (auto& x : v)
        x /= g;

    if (isPossible(v)) {
        cout << 1 << '\n';
        for (int i = 0; i < n; i++) {
            if (v[i] % 2) {
                cout << i + 1 << '\n';
                break;
            }
        }
    } else {
        cout << 0 << '\n';
    }
}