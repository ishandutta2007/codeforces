#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

ll a, b, ans;

ll gcd(ll a, ll b) {
    if (!b) return a;
    ans += a / b;
    return gcd(b, a % b);
}

int main() {
    scanf("%lld%lld", &a, &b);
    gcd(a, b);
    printf("%lld\n", ans);
    return 0;
}