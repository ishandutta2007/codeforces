#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 500005;

int n, p[N];
long long sum1[N], sum2[N];
char str[N];

int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
    scanf("%s", str + 1);
    for (int i = 1; i <= n; i++) {
        sum1[i] = sum1[i - 1];
        sum2[i] = sum2[i - 1];
        if (str[i] == 'A') sum1[i] += p[i];
        else sum2[i] += p[i];
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, sum1[i - 1] + sum2[n] - sum2[i - 1]);
        ans = max(ans, sum2[i - 1] + sum1[n] - sum1[i - 1]);
    }
    printf("%lld\n", ans);
    return 0;
}