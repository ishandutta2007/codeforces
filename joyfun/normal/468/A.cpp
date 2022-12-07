#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int n;

void solve(int n) {
    if (n % 2 == 0) {
        printf("1 + 2 = 3\n");
        printf("3 + 3 = 6\n");
        printf("6 * 4 = 24\n");
        for (int i = 5; i <= n; i += 2) {
            printf("%d - %d = 1\n", i + 1, i);
            printf("24 * 1 = 24\n");
        }
    } else {
        printf("5 - 3 = 2\n");
        printf("1 + 2 = 3\n");
        printf("2 * 3 = 6\n");
        printf("4 * 6 = 24\n");
        for (int i = 6; i <= n; i += 2) {
            printf("%d - %d = 1\n", i + 1, i);
            printf("24 * 1 = 24\n");
        }
    }
}

int main() {
    scanf("%d", &n);
    if (n < 4) printf("NO\n");
    else {
        printf("YES\n");
        solve(n);
    }
    return 0;
}