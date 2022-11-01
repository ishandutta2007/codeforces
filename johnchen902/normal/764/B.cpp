#include <cstdio>
#include <utility>
int a[200000];
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", a + i);
    for(int i = 0, j = n - 1; i < j; i += 2, j -= 2)
        std::swap(a[i], a[j]);
    for(int i = 0; i < n; i++)
        printf("%d%c", a[i], i == n - 1 ? '\n' : ' ');
}