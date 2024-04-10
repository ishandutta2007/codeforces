#include <bits/stdc++.h>
using namespace std;

int main() {
    long long i, j, n, k, sum;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> k;
    for (i = 0; i < k; ++i) {
        cin >> n;
        sum = ((n + 1) * n) / 2;
        for (j = 1; j <= n; j *= 2)
            sum -= 2 * j;
        cout << sum << "\n";
    }
}