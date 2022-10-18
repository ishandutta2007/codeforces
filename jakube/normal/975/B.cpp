#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<long long> v(14);
    for (int i = 0; i < 14; i++) {
        cin >> v[i];
    }

    long long best = 0;
    for (int i = 0; i < 14; i++) {
        auto w = v;
        long long x = w[i];
        w[i] = 0;
        for (int j = 0; j < 14; j++) {
            w[(i + j + 1) % 14] += x / 14 + (j < (x % 14));
        }

        long long sum = 0;
        for (long long x : w) {
            if (x % 2 == 0)
                sum += x;
        }
        best = max(best, sum);
    }
    cout << best << '\n';
}