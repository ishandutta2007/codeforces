#include <cstdio>
#include <algorithm>
#include <numeric>
using namespace std;
int usb[300000], ps2[300000], mer[300000];
int main() {
    int a, b, c, m, nu = 0, np = 0;
    scanf("%d %d %d %d", &a, &b, &c, &m);
    for(int i = 0; i < m; i++) {
        int val;
        char s[5];
        scanf("%d %4s", &val, s);
        (*s == 'U' ? usb[nu++] : ps2[np++]) = val;
    }
    int ans1 = 0, nm = 0;
    long long ans2 = 0;

    sort(usb, usb + nu);
    ans1 += min(nu, a);
    ans2 += accumulate(usb, usb + min(nu, a), 0LL);
    copy(usb + min(nu, a), usb + nu, mer + nm);
    nm += nu - min(nu, a);

    sort(ps2, ps2 + np);
    ans1 += min(np, b);
    ans2 += accumulate(ps2, ps2 + min(np, b), 0LL);
    copy(ps2 + min(np, b), ps2 + np, mer + nm);
    nm += np - min(np, b);

    sort(mer, mer + nm);
    ans1 += min(nm, c);
    ans2 += accumulate(mer, mer + min(nm, c), 0LL);

    printf("%d %lld\n", ans1, ans2);
}