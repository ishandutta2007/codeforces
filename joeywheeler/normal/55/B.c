// write in C...
#include <stdio.h>

#ifdef DEBUG
#define D(x...) fprintf(stderr, x)
#else
#define D(x...)
#endif

char op[20];

long long min(long long a, long long b) {
    return a < b ? a : b;
}

long long can_do(long long a, long long b, long long c, long long d, int i) {
    long long res = 2000000000000000000;
    if (i == 3) res = a;
    else {
        if (op[2*i] == '+') {
            if (i < 3)
                res = min(res, can_do(a+b, c, d, -1, i+1));
            if (i < 2) {
                res = min(res, can_do(a+c, b, d, -1, i+1));
                res = min(res, can_do(a, b+c, d, -1, i+1));
            }
            if (i < 1) {
                res = min(res, can_do(a+d, b, c, -1, i+1));
                res = min(res, can_do(a, b+d, c, -1, i+1));
                res = min(res, can_do(a, b, c+d, -1, i+1));
            }
        } else {
            if (i < 3)
                res = min(res, can_do(a*b, c, d, -1, i+1));
            if (i < 2) {
                res = min(res, can_do(a*c, b, d, -1, i+1));
                res = min(res, can_do(a, b*c, d, -1, i+1));
            }
            if (i < 1) {
                res = min(res, can_do(a*d, b, c, -1, i+1));
                res = min(res, can_do(a, b*d, c, -1, i+1));
                res = min(res, can_do(a, b, c*d, -1, i+1));
            }
        }
    }
    return res;
}

int main() {
    long long a, b, c, d;
    scanf("%I64d %I64d %I64d %I64d", &a, &b, &c, &d);
    scanf(" %c %c %c", op, op+2, op+4);
    printf("%I64d", can_do(a, b, c, d, 0));
    return 0;
}