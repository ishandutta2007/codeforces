#include <cstdio>
using namespace std;
int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        long long ans = (long long) n * (n + 1) / 2;
        for(int x = 1; x <= n; x *= 2)
            ans -= 2 * x;
        printf("%lld\n", ans);
    }
}