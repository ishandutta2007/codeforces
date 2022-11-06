#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long llong;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    llong r;
    cin >> r;
    for (llong x = 1; x * x <= r; ++x) {
        llong y = r - x * x - x - 1;
        if (y > 0 && y % (x + x) == 0) {
            printf("%lld %lld\n", x, y / (x + x));
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}