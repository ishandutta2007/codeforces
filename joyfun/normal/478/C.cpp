#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
ll a[3], ans = 0;

int main() {
    for (ll i = 0; i < 3; i++)
        scanf("%lld", &a[i]);
    sort(a, a + 3);
    if ((a[0] + a[1]) * 2 >= a[2]) printf("%lld\n", (a[0] + a[1] + a[2]) / 3);
    else printf("%lld\n", a[0] + a[1]);
    return 0;
}