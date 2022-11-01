#include <cstdio>
#include <string>
#include <iostream>

const int mod = 1000000007;

int wyn[107][2700];

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 0; i < 26; i++) wyn[0][i] = 1;
    for (int i = 1; i <= 100; i++) {
        for (int q = 0; q <= 2500; q++) {
            for (int w = 0; w < 26; w++) {
                if (q - w >= 0)
                    wyn[i][q] = (wyn[i][q] + wyn[i - 1][q - w]) % mod;
            }
        }
    }
    while (T--) {
        std::string s;
        std::cin >> s;
        int sum = 0;
        for (auto it : s)
            sum += it - 'a';
        printf("%d\n", (wyn[s.length() - 1][sum] - 1 + mod) % mod);
    }
    return 0;
}