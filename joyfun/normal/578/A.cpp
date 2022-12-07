#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

ll a, b;

int main() {
    scanf("%lld%lld", &a, &b);
    if (b > a) {
        printf("-1\n");
        return 0;
    }
    ll s = a + b;
    ll sb = s / b;
    if (sb % 2) sb--;
    printf("%.10f\n", s * 1.0 / sb);
    return 0;
}