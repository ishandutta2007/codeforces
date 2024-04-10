#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;
long long n;
long long f[N];

int main() {
    scanf("%lld", &n);
    f[0] = 1; f[1] = 2;
    for (int i = 2; ; i++) {
        f[i] = f[i - 1] + f[i - 2];
        if (f[i] > n) {
            printf("%d\n", i - 1);
            return 0;
        }
    }
    return 0;
}