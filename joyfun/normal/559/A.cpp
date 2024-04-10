#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

ll a[6];

int main() {
    for (int i = 0; i < 6; i++)scanf("%lld", &a[i]);
    ll s = a[0] * 2 - 1;
    ll ans = 0;
    for (int i = 0; i < min(a[1], a[5]); i++) {
        s += 2;
        ans += s;
    }
    s = a[3] * 2 - 1;
    for (int i = 0; i < min(a[2], a[4]); i++) {
        s += 2;
        ans += s;
    }
    s++;
    for (int i = 0; i < max(a[2], a[4]) - min(a[2], a[4]); i++) {
        ans += s;
    }
    printf("%lld\n", ans);
    return 0;
}