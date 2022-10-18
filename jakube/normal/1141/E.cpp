#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long H;
    cin >> H;
    int n;
    cin >> n;
    vector<int> d(n);
    for (auto& x : d)
        cin >> x;
    long long sum = accumulate(d.begin(), d.end(), 0LL);

    auto round = [&](long long H) {
        for (int i = 0; i < n; i++) {
            H += d[i];
            if (H <= 0)
                return i + 1;
        }
        return -1;
    };

    if (sum >= 0) {
        cout << round(H) << '\n';
    } else {
        long long L = -1; // too small
        long long R = H / -sum + 1; // works
        while (L + 1 < R) {
            long long M = (L + R) / 2;
            if (round(H + M * sum) >= 0)
                R = M;
            else
                L = M;
        }
        cout << round(H + R * sum) + R * n << '\n';
    }
}