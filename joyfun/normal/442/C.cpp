#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int N = 500005;
int n, top;
long long stack[N], x, ans;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    while (top > 0 && stack[top - 1] >= stack[top] && x >= stack[top]) {
        ans += min(stack[top - 1], x);
        top--;
    }
    stack[++top] = x;
    }
    sort(stack + 1, stack + 1 + top);
    for (int i = 1; i <= top - 2; i++) {
    ans += stack[i];
    }
    printf("%lld\n", ans);
    return 0;
}