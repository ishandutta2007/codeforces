#include <bits/stdc++.h>
using namespace std;
const int N = 500000;

int main() {
    int i, j, n, a, o, b[N];
    cin >> n;
    for (i = 1; i <= n; ++i) {
        b[i] = 0;
    }
    a = 1;
    printf("%d%c", a, ' ');
    int top = n + 1;
    for (i = 0; i < n; ++i) {
        scanf("%d", &j);
        b[j] = 1;
        while ((top > 0) && (b[top - 1] == 1)) --top;
        a = i + 2 - (n + 1 - top);
        printf("%d%c", a, ' ');
    }
}