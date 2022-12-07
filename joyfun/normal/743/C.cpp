#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int n;

int main() {
    scanf("%d", &n);
    if (n == 1) printf("-1\n");
    else printf("%d %d %lld\n", n, n + 1, 1LL * n * (n + 1));
    return 0;
}