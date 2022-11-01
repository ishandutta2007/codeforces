#include <cstdio>
using namespace std;
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    if(k > n / 2)
        k = n / 2;
    printf("%lld\n", ((long long) n * (n - 1) - (long long) (n - k * 2) * (n - k * 2 - 1)) / 2);
}