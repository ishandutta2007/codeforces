#include <cstdio>
#include <cstring>
using namespace std;

int n, a[15][15];

int main() {
    for (int i = 1; i <= 10; i++) a[1][i] = a[i][1] = 1;
    for (int i = 2; i <= 10; i++)
        for (int j = 2; j <= 10; j++)
            a[i][j] = a[i - 1][j] + a[i][j - 1];
    while (~scanf("%d", &n)){
        printf("%d\n", a[n][n]);
    }
    return 0;
}