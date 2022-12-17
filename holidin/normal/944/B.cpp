#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
using namespace std;
const int N = 200000;
long long a[N], v[3];

int main() {
    long long i, j, n;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    long long minx = 1e9, maxx = -1e9;
    long long sum = 0;
    for (i = 0; i < n; ++i) {
        cin >> a[i];
        minx = min(a[i], minx);
        maxx = max(a[i], maxx);
        sum += a[i];
    }
    if (minx == maxx) {
        cout << n << endl;
        for (i = 0; i < n; ++i)
            cout << minx << ' ';
        return 0;
    }
    if (minx == maxx - 1) {
        cout << n << endl;
        for (i = 0; i < n; ++i)
            cout << a[i] << ' ';
        return 0;
    }
    for (i = 0; i < n; ++i)
        ++v[a[i] - minx];
    long long sr = minx + 1;
    int cnt = 1e9, as = -1;
    for (i = 0; i <= n; ++i) {
        long long l = 0, r = n - i + 1;
        while (r - l > 1) {
            long long x = (l + r) / 2 - 1;
            long long y = n - x - i;
            if (i * sr + x * minx + y * maxx > sum)
                l = x + 1;
            else
                r = x + 1;
        }
        long long y = n - l - i;
        if (i * sr + l * minx + y * maxx == sum)
            if (min(i, v[1]) + min(l, v[0]) + min(y, v[2]) < cnt) {
                cnt = min(i, v[1]) + min(l, v[0]) + min(y, v[2]);
                as = i;
            }
    }
    cout << cnt << endl;
    i = as;
    int l = 0, r = n - i + 1;
        while (r - l > 1) {
            long long x = (l + r) / 2 - 1;
            long long y = n - x - i;
            if (i * sr + x * minx + y * maxx > sum)
                l = x + 1;
            else
                r = x + 1;
        }
        long long y = n - l - i;
    for (j = 0; j < i; ++j)
        cout << sr << ' ';
    for (j = 0; j < l; ++j)
        cout << minx << ' ';
    for (j = 0; j < y; ++j)
        cout << maxx << ' ';
}