#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long llong;

int gcd(int x, int y) {
    for (; y; swap(x, y)) x %= y;
    return x;
}

int n;
char S[200001];
int C[200000];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> S;
    bool zero = 1;
    for (int i = 0; i < n; ++i) {
        if (S[i] == '1') zero = 0;
    }
    if (zero) {
        printf("%d\n", n);
        return 0;
    }
    int ans = 0;
    for (int k = 1; k < n; ++k) ++C[gcd(k, n)];
    for (int i = 1; i < n; ++i) {
        if (C[i] == 0) continue;
        bool ch = 1;
        for (int j = 0; j < i; ++j) {
            int sum = 0;
            for (int k = 0; k < n / i; ++k) {
                if (S[k * i + j] == '1') ++sum;
            }
            if (sum & 1) {
                ch = 0;
                break;
            }
        }
        if (ch) ans += C[i];
    }
    printf("%d\n", ans);
    return 0;
}