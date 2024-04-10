#include <bits/stdc++.h>
using namespace std;

int main() {
    long long k, d, t;
    //freopen("input.txt", "r", stdin);
    //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> k >> d >> t;
    t *= 2;
    if (d >= k) {
        long long cnt = t / (2 * k + (d - k));
        t %= (2 * k + (d - k));
        if (t <= 2 * k) {
            cout << cnt * d + t / 2;
            if (t % 2 == 1)
                cout << ".5";
        } else
            cout << cnt * d + k + (t - 2*k);
    } else {
        long long tm = (k + (d - k % d) % d);
        long long L = 2*k + (d - k % d) % d;
        long long cnt = t / L;
        t %= L;
        if (t <= 2 * k) {
            cout << cnt * tm + t / 2;
            if (t % 2 == 1)
                cout << ".5";
        } else
            cout << cnt * tm + k + (t - 2 * k);
    }
}