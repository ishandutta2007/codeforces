#include <cstdio>

const int N = 100000;

int n, depth[N], result[N];

int main()
{
    result[depth[0] = 0] = 1;
    scanf("%d", &n);
    for (int i = 1, p; i < n; ++ i) {
        scanf("%d", &p);
        result[depth[i] = depth[p - 1] + 1] ^= 1;
    }
    int sum = 0;
    for (int i = 0; i < n; ++ i) {
        sum += result[i];
    }
    printf("%d\n", sum);
}