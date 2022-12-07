#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 2005;

int n, m;
long long a[N], b[N], c[N * N];

long long abss(long long x) {
    return max(x, -x);
}

void solve() {
    long long sa = 0, sb = 0;
    for (int i = 0; i < n; i++) sa += a[i];
    for (int i = 0; i < m; i++) sb += b[i];
    int ti = 0;
    int a1, b1;
    long long ansa = sa, ansb = sb;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            long long ssa = sa - a[i] + b[j];
            long long ssb = sb - b[j] + a[i];
            if (abss(ansa - ansb) > abss(ssa - ssb)) {
                ansa = ssa;
                ansb = ssb;
                ti = 1;
                a1 = i;
                b1 = j;
            }
        }
    }
    int cn = 0;
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            c[cn++] = 2 * (b[i] + b[j]);
        }
    }
    //printf("%lld %lld\n", ansa, ansb);
    sort(c, c + cn);
    long long ansc;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            long long ssa = sa - a[i] - a[j];
            long long ssb = sb + a[i] + a[j];
            long long ss = ssa - ssb;
            int v = lower_bound(c, c + cn, -ss) - c;
            if (v > 0) {
                if (abss(ansa - ansb) > abss(ss + c[v - 1])) {
                    ti = 2;
                    ansa = ssa + c[v - 1] / 2;
                    ansb = ssb - c[v - 1] / 2;
                    a1 = i; b1 = j;
                    ansc = c[v - 1] / 2;
                }
            }
            if (v != cn) {
                if (abss(ansa - ansb) > abss(ss + c[v])) {
                    ti = 2;
                    ansa = ssa + c[v] / 2;
                    ansb = ssb - c[v] / 2;
                    a1 = i; b1 = j;
                    ansc = c[v] / 2;
                }
            }
        }
    }
   // printf("%lld %lld %d\n", ansa, ansb, ansc);
   printf("%lld\n", abs(ansa - ansb));
   if (ti == 0) {
    printf("0\n");
   }
   else  if (ti == 1) {
        printf("1\n");
        printf("%d %d\n", a1 + 1, b1 + 1);
    } else {
        printf("2\n");
        for (int i = 0; i < m; i++){
            for (int j = i + 1; j < m; j++) {
                if (b[i] + b[j] == ansc) {
                    printf("%d %d\n", a1 + 1, i + 1);
                    printf("%d %d\n", b1 + 1, j + 1);
                    return;
                }
            }
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
    scanf("%d", &m);
    for (int i = 0; i < m; i++) scanf("%lld", &b[i]);
    solve();
    return 0;
}