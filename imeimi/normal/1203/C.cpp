#include <iostream>
#include <algorithm>
#include <vector>
#define fs first
#define se second

using namespace std;
typedef long long llong;
typedef pair<int, int> pii;

llong gcd(llong x, llong y) {
    for (; y; swap(x, y)) x %= y;
    return x;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    llong x = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        llong y;
        cin >> y;
        x = gcd(x, y);
    }
    int ans = 0;
    for (llong i = 1; i * i <= x; ++i) {
        if (x % i > 0) continue;
        ++ans;
        if (i * i < x) ++ans;
    }
    printf("%d\n", ans);
    return 0;
}