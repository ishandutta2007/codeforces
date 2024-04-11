#include<bits/stdc++.h>
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
using namespace std;


int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    ios::sync_with_stdio(false);

    int n;
    scanf("%d", &n);

    vector<ld> mx(n), mi(n);
    for (int i = 0; i < n; ++i) {
        double x;
        scanf("%lf", &x);
        mx[i] = x;
    }
    for (int i = 0; i < n; ++i) {
        double x;
        scanf("%lf", &x);
        mi[i] = x;
    }

    vector<ld> ans1(n + 1), ans2(n + 1);

    ld fma = 0, fmi = 0;
    for (int i = 0; i < n; ++i) {
        fma += mx[i];
        fmi += mi[i];

        const ld s = fmi + fma;
        
        const ld B = s;
        const ld C = -fma;
        const ld A = -1;

        const ld D = sqrtl(max(B * B - 4 * A * C, ld(0)));
        const ld x1 = (-B + D) / (2 * A);
        const ld x2 = (-B - D) / (2 * A);

        ans1[i + 1] = x1;
        ans2[i + 1] = x2;
    }

    for (int  i = 0; i < n; ++i) {
        double v = max(double(ans1[i+1] - ans1[i]), double(1e-20));
        printf("%.12f ", v);
    }
    puts("");
    for (int  i = 0; i < n; ++i) {
        double v = max(double(ans2[i+1] - ans2[i]), double(1e-20));
        printf("%.12f ", v);
    }
    puts("");

    return 0;
}