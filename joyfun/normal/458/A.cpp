#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const double eps = 1e-10;
const int N = 100005;

char A[N], B[N];
long long a[N], b[N];

int main() {
    scanf("%s%s", A, B);
    int an = strlen(A);
    int bn = strlen(B);
    for (int i = 0; i <  an; i++)
    a[i] = A[an - i - 1] - '0';
    for (int i = 0; i < bn ; i++)
    b[i] = B[bn - i - 1] - '0';
    int n = max(an, bn);
    for (int i = n - 1; i >= 2; i--) {
    if (a[i] >= b[i] ){
        a[i] -= b[i];
        b[i] = 0;
    }
    else if (a[i] <= b[i]) {
        b[i] -= a[i];
        a[i] = 0;
    }
    if (a[i] >= 2) {
        printf(">\n");
        return 0;
    }
    if (b[i] >= 2) {
        printf("<\n");
        return 0;
    }
    a[i - 1] += a[i]; a[i - 2] += a[i];
    b[i - 1] += b[i]; b[i - 2] += b[i];
    }
    long long aa = a[0], bb = a[1];
    long long cc = b[0], dd = b[1];
    long long x = 2 * (aa - cc) - (dd - bb);
    long long y = (dd - bb);
    if (x < 0 && y > 0) {
    printf("<\n");
    }
    else if (x > 0 && y < 0) {
    printf(">\n");
    }
    else if (x >= 0 && y >= 0) {
    x = x * x;
    y = y * y * 5;
    if (x == y) printf("=\n");
    else if (x < y) printf("<\n");
    else printf(">\n");
    }
    else {
    x = x * x;
    y = y * y * 5;
    if (x == y) printf("=\n");
    else if (x < y) printf(">\n");
    else printf("<\n");
    }
    return 0;
}