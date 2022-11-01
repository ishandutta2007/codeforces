#include <cstdio>

using namespace std;

long long a[15][15];
int n;

int main(){
    scanf("%d", &n);
    for (int i = 0; i <= 10; ++i) a[i][0] = a[0][i] = 1;
    for (int i = 1; i <= 10; ++i)
    for (int j = 1; j <= 10; ++j)
    a[i][j] = a[i][j - 1] + a[i - 1][j];
    printf("%I64d\n", a[n - 1][n - 1]);
    return 0;
}