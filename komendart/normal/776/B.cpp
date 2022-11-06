#include <bits/stdc++.h>

using namespace std;

const int maxw = 1e5 + 10;

char prime[maxw];

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    for (int i = 0; i < maxw; ++i) prime[i] = true;
    for (int i = 2; i < maxw; ++i) {
        if (!prime[i]) continue;
        for (int j = i + i; j < maxw; j += i) {
            prime[j] = false;
        }
    }

    int n;
    cin >> n;
    if (n <= 2) cout << "1\n";
    else cout << "2\n";
    for (int i = 2; i <= n + 1; ++i) {
        if (prime[i]) cout << 1 << ' ';
        else cout << 2 << ' ';
    }
}