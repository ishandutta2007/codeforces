#include <cstdio>
int main() {
    int n, a, b;
    std::scanf("%d %d %d", &n, &a, &b);
    int n0 = (n + 1) / 2, n1 = n / 2;
    if(n <= a * b)
        for(int i = 0; i < a; i++)
            for(int j = 0; j < b; j++)
                std::printf("%d%c", (i + j) % 2 ? n1 > 0 ? 2 * n1-- : 0 : n0 > 0 ? 2 * n0-- - 1 : 0, " \n"[j == b - 1]);
    else
        std::puts("-1");
}