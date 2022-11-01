#include <cstdio>
#include <algorithm>
using namespace std;

char s[1000][1001];

bool solve(int n, int a, int b) {
    if (a > 1 && b > 1)
        return false;
    if (n == 2 && a == 1 && b == 1)
        return false;
    if (n == 3 && a == 1 && b == 1)
        return false;
    for (int i = 0; i < n; i++) {
        s[i][i] = '0';
        for (int j = i + 1; j < n; j++)
            s[i][j] = s[j][i] = (a == 1 ? '1' : '0');
    }
    for (int j = 0; j < n - max(a, b); j++)
        s[j][j + 1] = s[j + 1][j] = (a == 1 ? '0' : '1');
    return true;
}

int main() {
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);

    if (solve(n, a, b)) {
        puts("YES");
        for (int i = 0; i < n; i++)
            puts(s[i]);
    } else {
        puts("NO");
    }
}