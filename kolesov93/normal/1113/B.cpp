#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ld PI = acosl(-1.);


int main() {
    ll sum = 0;
    vector<int> a(101);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int x; scanf("%d", &x);
        a[x]++;
        sum += x;
    }
    ll ans = sum;

    for (int i = 1; i <= 100; ++i) {
        if (!a[i]) continue;
        --a[i];
        for (int j = 1; j <= 100; ++j) {
            if (!a[j]) continue;

            for (int x = 1; x <= i; ++x) {
                if (i % x == 0) {
                    ans = min(ans, sum - i - j + i / x + j * x);
                }
            }
        }
        ++a[i];
    }
    cout << ans << endl;

    return 0;
}