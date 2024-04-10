#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int n;
__int64 a, b;

int main() {
    __int64 num;
    scanf("%d%I64d%I64d", &n, &a, &b);
    for (int i = 0; i < n - 1; i++) {
        scanf("%I64d", &num);
        __int64 sb = num * a % b;
        printf("%I64d ", sb/a);
    }
        scanf("%I64d", &num);
        __int64 sb = num * a % b;
        printf("%I64d\n", sb/a);
    return 0;
}