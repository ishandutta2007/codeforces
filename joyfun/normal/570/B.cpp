#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m;

int main() {
    scanf("%d%d", &n, &m);
    int a = -1;
    if (m != 1) {
        a = m - 1;
    }
    if (m + 1 <= n) {
        if (n - m > a) a = m + 1;
    }
    if (a == -1) a = m;
    printf("%d\n", a);
    return 0;
}