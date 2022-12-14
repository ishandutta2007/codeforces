#include <bits/stdc++.h>

using namespace std;

int main() {
    long long k, c[15], x = 1;
    scanf("%lld", &k);
    for (int i = 0; i < 10; i++) c[i] = 1;
    for (int i = 0; x < k; i = (i + 1) % 10) {
        x /= c[i];
        c[i]++;
        x *= c[i];
    }
    for (int i = 0; i < 10; i++) {
        while (c[i]--) printf("%c", "codeforces"[i]);
    }
}