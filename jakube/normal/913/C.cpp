#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, L;
    cin >> n >> L;
    vector<long long> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 1; i < n; i++) {
        v[i] = min(v[i], v[i-1] * 2);
    }

    long long best = std::numeric_limits<long long>::max();
    long long cur = 0;
    int remaining = L;
    int big = 1 << (n - 1);
    int c = remaining / big;
    cur += c * v.back();
    remaining %= big;
    if (remaining == 0) {
        cout << cur << '\n';
        return 0;
    }
    for (int i = n - 1; i >= 0; i--) {
        int p = 1 << i;
        if (remaining <= p) {
            best = min(best, cur + v[i]);
        } else {
            cur += v[i];
            remaining -= p;
            best = min(best, cur + v[i]);
        }
    }

    cout << best << '\n';
}