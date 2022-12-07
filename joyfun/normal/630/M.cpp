#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;

ll n;

int main() {
    scanf("%lld", &n);
    n %= 360;
    ll Min = 100000000000000000LL;
    int Minv;
    for (int i = 0; i < 4; i++) {
        ll sb = n - 90 * i;
        sb %= 360;
        sb = (sb + 360) % 360;
        if (sb > 180) sb = 360 - sb;
        if (sb < Min) {
            Min = sb;
            Minv = i;
        }
    }
    printf("%d\n", Minv);
    return 0;
}