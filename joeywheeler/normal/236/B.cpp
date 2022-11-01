#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>

#define N 1000001

using namespace std;

long long d[N];

int main() {
    for (int i = 1; i < N; i++) {
        for (int j = i; j < N; j += i) {
            d[j]++;
            d[j] %= 1 << 30;
        }
    }
    int a, b, c;
    long long ans = 0;
    scanf("%d %d %d", &a, &b, &c);
    for (int i = 0; i <= a; i++) {
        for (int j = 0; j <= b; j++) {
            for (int k = 0; k <= c; k++) {
                ans += d[i*j*k];
                ans %= 1 << 30;
            }
        }
    }
    printf("%d", (int) ans);
}