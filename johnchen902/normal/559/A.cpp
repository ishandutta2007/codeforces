#include <cstdio>
using namespace std;
int main() {
    int a[6];
    for(int i = 0; i < 6; i++) scanf("%d", a + i);
    int ans = 0;
    while(a[0]) ans -= a[0], a[0]--, a[1]++, a[5]++, ans -= a[0];
    while(a[2]) ans -= a[2], a[2]--, a[3]++, a[1]++, ans -= a[2];
    while(a[4]) ans -= a[4], a[4]--, a[5]++, a[3]++, ans -= a[4];
    ans += a[1] * a[1];
    printf("%d\n", ans);
}