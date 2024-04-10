#include <bits/stdc++.h>
using namespace std;

int main() {
    long long i, x, n, k;
    cin >> n >> k;
    x = 1;
    for (i = 0; i < k; ++i) {
        if (n % 2 == 0)
            n = n / 2;
        if (n % 5 == 0)
            n = n / 5;
        x = x * 10;
    }
    cout << x * n;
}