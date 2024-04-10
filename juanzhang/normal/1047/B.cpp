#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x, y, mx = 0;
    scanf("%d", &n);
    while (n--) {
        scanf("%d %d", &x, &y);
        mx = max(mx, x + y);
    }
    printf("%d", mx);
    return 0;
}