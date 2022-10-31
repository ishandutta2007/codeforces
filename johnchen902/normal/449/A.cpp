#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int n, m, k;
long long eval(int x) {
    if(x < 0) x = 0;
    if(x > k) x = k;
    return (n / (x + 1)) * 1ll * (m / (k - x + 1));
}
int main(){
    scanf("%d %d %d", &n, &m, &k);
    if(k > (n - 1) + (m - 1)) {
        puts("-1");
    } else {
        long long ans = eval(0);
        for(int i = 1; i * 1ll * i <= n; i++) {
            ans = max(ans, eval(i));
            ans = max(ans, eval(n / i - 1));
        }
        printf("%I64d\n", ans);
    }
}