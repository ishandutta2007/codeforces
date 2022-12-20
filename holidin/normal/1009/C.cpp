#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;


int a[N], b[N];

int main() {
    long long i, j, n, q, top, l, r, t, k, x, d;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    long long cntp = 0, cntm = 0, ans = 0;
    for (i = 0; i < n; ++i) {
        cntp += i;
        cntm += abs(i - n / 2);
    }
    for (i = 0; i < k; ++i) {
        cin >> x >> d;
        if (d < 0)
            ans += cntm * d + x * n;
        else
            ans += cntp * d + x * n;
    }
    cout << fixed << setprecision(8) << 1.0 * ans / n;
}