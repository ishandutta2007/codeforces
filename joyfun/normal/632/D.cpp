#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 1000005;

int n, m, a[N], cnt[N], tot[N], lcm[N];

int gcd(int a, int b) {
    if (!b) return a;
    return gcd(b, a % b);
}

int LCM(int a, int b) {
    return a / gcd(a, b) * b;
}

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if (a[i] > m) continue;
        cnt[a[i]]++;
    }
    for (int i = 1; i <= m; i++) lcm[i] = 1;
    for (int i = 1; i <= m; i++) {
        for (int j = i; j <= m; j += i) {
            tot[j] += cnt[i];
            if (cnt[i]) lcm[j] = LCM(lcm[j], i);
        }
    }
    int Maxv = 1;
    for (int i = 2; i <= m; i++) {
     //       printf("%d %d\n", i, lcm[i]);
        if (lcm[i] == i) {
            if (tot[Maxv] < tot[i]) {
                Maxv = i;
            }
        }
    }
    printf("%d %d\n", Maxv, tot[Maxv]);
    for (int i = 1; i <= n; i++) {
        if (LCM(Maxv, a[i]) == Maxv) printf("%d ", i);
    }
    printf("\n");
    return 0;
}