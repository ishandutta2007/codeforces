#include <cstdio>
#include <numeric>
#include <algorithm>
using namespace std;
unsigned long long a[100000], b[100000];
unsigned long long pa[100001], pb[100001];
int main(){
    int m, n;
    scanf("%d %d", &m, &n);
    for(int i = 0; i < m; i++) scanf("%I64u", a + i);
    for(int i = 0; i < n; i++) scanf("%I64u", b + i);
    sort(a, a + m);
    sort(b, b + n);
    partial_sum(a, a + m, pa + 1);
    partial_sum(b, b + n, pb + 1);
    unsigned long long mini = 10000000000000000000ULL;
    for(int i = 0; i < m; i++)
        mini = min(mini, pa[i] + pb[n] * (m - i));
    for(int i = 0; i < n; i++)
        mini = min(mini, pb[i] + pa[m] * (n - i));
    printf("%I64u\n", mini);
}