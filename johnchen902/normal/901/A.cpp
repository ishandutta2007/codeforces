#include <cstdio>
using namespace std;
int a[100001];
void solve(int h) {
    for (int i = 0; i + 1 <= h; i++) {
        if (a[i] > 1 && a[i + 1] > 1) {
            puts("ambiguous");
            for (int j = 0, p = 0; j <= h; p += a[j], j++)
                for (int k = 0; k < a[j]; k++)
                    printf("%d%c", p, j == h && k == a[j] - 1 ? '\n' : ' ');
            for (int j = 0, p = 0; j <= h; p += a[j], j++)
                for (int k = 0; k < a[j]; k++)
                    printf("%d%c", j == i + 1 && k == 1 ? p - 1 : p,
                            j == h && k == a[j] - 1 ? '\n' : ' ');
            return;
        }
    }

    puts("perfect");
}
int main() {
    int h;
    scanf("%d", &h);
    for (int i = 0; i <= h; i++)
        scanf("%d", a + i);
    solve(h);
}