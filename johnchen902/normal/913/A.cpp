#include <cstdio>
using namespace std;
int solve(int n, int m) {
    int p2n = 1;
    for (int i = 0; i < n; i++) {
        p2n *= 2;
        if (p2n > m)
            return m;
    }
    return m % p2n;
}
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    printf("%d\n", solve(n, m));
}