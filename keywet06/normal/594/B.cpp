#include <bits/stdc++.h>
const double pai = acos(-1);
int n, r, v, s, f, k;
double len, c, ans, left, right, middle;
int main() {
    scanf("%d %d %d", &n, &r, &v);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &s, &f);
        len = f - s;
        c = pai * r * 2;
        k = len / c;
        ans = k * c / v;
        len -= c * k;
        len /= 2;
        left = 0, right = len;
        for (int i = 0; i < 50; i++) {
            middle = (left + right) / 2;
            if (middle + r * sin(middle / r) >= len) {
                right = middle;
            } else {
                left = middle;
            }
        }
        ans += 2 * left / v;
        printf("%.12lf\n", ans);
    }
    return 0;
}