#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 6e5 + 10;

int n, a[N];

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++)
        scanf("%d", a + i);
    long long ans = 0, sum = 0;
    for(int i = 1; i <= n; i ++) {
        if(a[i] >= sum * 2) {
            a[i] -= sum * 2;
            ans += sum;
            sum = 0;
        } else {
            ans += a[i] / 2;
            sum -= a[i] / 2;
            a[i] %= 2;
        }
        ans += a[i] / 3;
        sum += a[i] % 3;
    }
    printf("%I64d\n", ans);
    return 0;
}