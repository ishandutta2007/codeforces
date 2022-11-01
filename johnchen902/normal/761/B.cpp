#include <cstdio>
#include <algorithm>
#include <numeric>
using namespace std;
int a[100], b[100];
int c[100], d[100];
int main() {
    int n, l;
    scanf("%d %d", &n, &l);
    for(int i = 0; i < n; i++)
        scanf("%d", a + i);
    for(int i = 0; i < n; i++)
        scanf("%d", b + i);
    adjacent_difference(a, a + n, c);
    adjacent_difference(b, b + n, d);
    c[0] = a[0] - a[n - 1] + l;
    d[0] = b[0] - b[n - 1] + l;
    bool ok = false;
    for(int i = 0; i < n; i++) {
        if(equal(c, c + n, d)) {
            ok = true;
            break;
        }
        rotate(d, d + 1, d + n);
    }
    puts(ok ? "YES" : "NO");
}