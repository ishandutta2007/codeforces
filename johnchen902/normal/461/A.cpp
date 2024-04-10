#include <cstdio>
#include <algorithm>
using namespace std;
int a[300000];
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", a + i);
    sort(a, a + n);
    long long val = 0;
    for(int i = 0; i < n; i++)
        val += a[i] * (i + 2LL);
    val -= a[n - 1];
    printf("%I64d\n", val);
}