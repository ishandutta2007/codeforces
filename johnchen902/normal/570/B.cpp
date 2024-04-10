#include <cstdio>
using namespace std;
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    printf("%d\n", n == 1 ? 1 : m <= n / 2 ? m + 1 : m - 1);
}