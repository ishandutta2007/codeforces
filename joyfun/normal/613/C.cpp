#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int M = 100005;

const int N = 26;
int n, a[N];

int gcd(int a, int b) {
    if (!b) return a;
    return gcd(b, a % b);
}

void solve() {
    int cnt = 0;
    int d = 0;
    int v = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2) {
            cnt++;
            v = i;
        }
        d = gcd(d, a[i]);
    }
    if (cnt >= 2) {
        printf("0\n");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < a[i]; j++)
                printf("%c", i + 'a');
        }
    } else {
        printf("%d\n", d);
        if (v == -1) d /= 2;
        for (int k = 0; k < d; k++) {
            for (int i = 0; i < n; i++) {
                if (a[i] % 2) continue;
                for (int j = 0; j < a[i] / d / 2; j++)
                    printf("%c", i + 'a');
            }
            if (v != -1) for (int i = 0; i < a[v] / d; i++)
                printf("%c", v + 'a');
            for (int i = n - 1; i >= 0; i--) {
                if (a[i] % 2) continue;
                for (int j = 0; j < a[i] / d / 2; j++)
                    printf("%c", i + 'a');
            }
        }
        printf("\n");
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    solve();
    return 0;
}