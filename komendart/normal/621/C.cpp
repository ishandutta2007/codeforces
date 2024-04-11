#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, p;
    cin >> n >> p;
    vector<ld> prob(n);
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        prob[i] = (r / p - (l - 1) / p) / (ld) (r - l + 1);
    }

    ld res = (1 - prob[0]) * prob[n - 1] + prob[0];
    for (int i = 1; i < n; i++) {
        res += (1 - prob[i]) * prob[i - 1] + prob[i];
    }

    cout << fixed; cout.precision(12);
    cout << res * 2000 << '\n';
}