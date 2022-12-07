#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n;

int main() {
    scanf("%d", &n);
    int i = n - 1;
    for (; i >= 1; i -= 2);
    i += 2;
    for (; i <= n - 1; i += 2)
        printf("%d ", i);
    i -= 2;
    for (; i >= 1; i -= 2)
        printf("%d ", i);

    i = n - 2;
    for (; i >= 1; i -= 2);
    i += 2;
    for (; i <= n - 2; i += 2)
        printf("%d ", i);
    printf("%d ", n);
    i -= 2;
    for (; i >= 1; i -= 2)
        printf("%d ", i);
    printf("%d ", n);
    return 0;
}