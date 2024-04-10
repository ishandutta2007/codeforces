#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 400005;

int n;
int a[N], b[N];

int main() {
    scanf("%d", &n);
    int as, bs;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (a[i] == 1) as = i;
        a[i + n] = a[i];
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
        if (b[i] == 1) bs = i;
        b[i + n] = b[i];
    }
    int flag = 1;
    for (int i = 0; i < n; i++) {
        if (a[as + i] == 0) as++;
        if (b[bs + i] == 0) bs++;
        if (a[as + i] != b[bs + i]) {
            flag = 0;
            break;
        }
    }
    printf("%s\n", flag ? "YES" : "NO");
    return 0;
}