#include <cstdio>
#include <algorithm>
using namespace std;
int a[100000];
int b[100000];
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", a + i);
    int base = a[0];
    for(int i = 1; i < n; i++) {
        int test = a[i];
        while(base != test) (base > test ? base : test) /= 2;
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int x = a[i];
        while(x % base || ((x / base) & (x / base - 1)))
            x /= 2, ans++;
        while(x != base)
            x /= 2, b[i]++;
    }
    nth_element(b, b + n / 2, b + n);
    for(int i = 0; i < n / 2; i++)
        ans += b[n / 2] - b[i];
    for(int i = n / 2 + 1; i < n; i++)
        ans += b[i] - b[n / 2];
    printf("%d\n", ans);
}