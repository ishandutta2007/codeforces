#include <stdio.h>
#include <string.h>
#include<algorithm>
using namespace std;
int k, n, i;
int num[105];

bool cmp(int a, int b) {
    return a > b;
}
int main() {
    scanf("%d%d", &k, &n);
    for (i = 1; i <= k; i++)
        scanf("%d", &num[i]);
    sort(num + 1, num + k + 1, cmp);
    printf("%d\n", num[n]);
    return 0;
}