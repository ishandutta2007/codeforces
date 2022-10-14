#include <bits/stdc++.h>
using namespace std;

int n, k;

int main() {
    scanf("%d %d", &n, &k);
    if(n == 2) printf("6\n");
    else printf("%d\n", min(k-1, n-k) + 5 + n - 1 + 2*(n - 2));
    return 0;
}