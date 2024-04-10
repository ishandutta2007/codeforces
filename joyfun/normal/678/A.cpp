#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, k;

int main() {
    scanf("%d%d", &n, &k);
    n++;
    printf("%d\n", ( n + k - 1) / k * k);
    return 0;
}