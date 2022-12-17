#include <bits/stdc++.h>
using namespace std;
const int N = 200;

int main() {
    long long i, x, n, k, a[N], b[N], j;
    cin >> n >> k;
    for (i = 0; i < k; ++i) {
        cin >> a[i] >> b[i];
        --a[i];
        --b[i];
    }
    --n;
    int top = -1;
    for (i = 1; i <= 200; ++i) {
        bool found = true;
        for (j = 0; j < k; ++j)
        if ((a[j] >= (b[j] + 1) * i) || (a[j] < b[j] * i)) {
            found = false;
        }
        if (found)
            if (top < 0)
                top = n / i;
            else if (n / i != top) {
                cout << -1;
                return 0;
            }
    }
    if (top != -1)
        cout << top + 1;
    else
        cout << -1;
}