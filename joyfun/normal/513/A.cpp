#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n1, n2, k1, k2;

int main() {
    scanf("%d%d%d%d", &n1, &n2, &k1, &k2);
    if (n1 > n2) printf("First\n");
    else printf("Second\n");
    return 0;
}