#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int n;

int main() {
    scanf("%d", &n);
    int f = 0;
    int a, b;
    while (n--) {
        scanf("%*s%d%d", &a, &b);
        if (a >= 2400 && b > a) f = 1;
    }
    printf("%s\n", f ? "YES" : "NO");
    return 0;
}