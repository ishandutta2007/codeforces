#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

char b[1 << 20];
char n[1 << 20];

int c;

int64 powmod(int64 a, int64 x) {
    if (x == 0) return 1;
    if (x & 1) return a * powmod(a * a % c, x / 2) % c;
    return powmod(a * a % c, x / 2);
}

int main() {
    std::cin >> b >> n >> c;
    int64 B = 0;
    for (int i = 0; b[i]; ++i) B = (B * 10 + b[i] - '0') % c;
    int len = strlen(n);
    int i = len - 1;
    while (n[i] == '0') --i;
    --n[i];
    for (int j = i + 1; j < len; ++j) n[j] = '9';
    int64 res = 1;
    int64 now = B;
    for (int j = len - 1; j >= 0; --j) {
        res = res * powmod(now, n[j] - '0') % c;
        now = powmod(now, 10);
    }
    res = res * (B - 1) % c;
    if (res <= 0) res += c;
    std::cout << res << '\n';
    return 0;
}