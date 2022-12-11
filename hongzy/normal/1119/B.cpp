#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 1010;

int n, h, ans, a[N], b[N], dp[N];

bool check(int k) {
    for(int i = 1; i <= k; i ++) b[i] = a[i];
    sort(b + 1, b + k + 1);
    long long sum = 0;
    if(k & 1) {
        for(int i = k; i >= 1; i -= 2) {
            sum += b[i];
        }
    } else {
        for(int i = k; i >= 2; i -= 2) {
            sum += b[i];
        }
    }
    return sum <= h;
}

int main() {
    scanf("%d%d", &n, &h);
    for(int i = 1; i <= n; i ++) {
        scanf("%d", a + i);
    }
    int ans = 1;
    for(int i = 1; i <= n; i ++)
        if(check(i)) ans = i;
    printf("%d\n", ans);
    return 0;
}