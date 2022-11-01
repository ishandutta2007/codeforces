#include <cstdio>
#include <algorithm>
using namespace std;
int a[1999];
int main() {
    int n, k = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        if(i && __gcd(a[i + k - 1], x) != 1) {
            a[i + k++] = 1;
        }
        a[i + k] = x;
    }
    printf("%d\n", k);
    for(int i = 0; i < n + k; i++)
        printf("%d%c", a[i], " \n"[i + 1 == n + k]);
}