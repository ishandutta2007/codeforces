#include <cstdio>
#include <numeric>
using namespace std;

int main() {
    int n, k;
    scanf("%d%d", &n, &k);

    int x = k;
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        x = gcd(x, a % k);
    }

    printf("%d\n", k / x);
    for (int i = 0; i < k; i += x)
        printf("%d%c", i, i + x == k ? '\n' : ' ');
}