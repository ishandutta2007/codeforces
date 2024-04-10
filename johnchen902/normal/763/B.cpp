#include <cstdio>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    puts("YES");
    for(int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d %*d %*d", &x, &y);
        printf("%d\n", 1 + (x & 1) + (y & 1) * 2);
    }
}