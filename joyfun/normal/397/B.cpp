#include <stdio.h>
#include <string.h>

int t;
__int64 n, l, r, i;

bool solve() {
    if (n < l) return false;
    __int64 k = n / l;
    if (n <= r * k) return true;
    return false;
}

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%I64d%I64d%I64d", &n, &l, &r);
        printf("%s\n", solve()?"Yes":"No");
    }
    return 0;
}