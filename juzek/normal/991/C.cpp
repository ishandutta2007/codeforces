#include <cstdio>
#include <algorithm>

bool check(long long N, long long k) {
    long long a = 0;
    long long M = N;
    while (N > 0) {
        a += std::min(N, k);
        N -= std::min(N, k);
        N -= N / 10;
    }
    return a * 2 >= M;
}

int main() {
    long long N;
    scanf("%I64d", &N);
    long long pocz = 0, kon = N + 1;
    while (pocz != kon - 1) {
        long long sr = (pocz + kon) / 2;
        if (check(N, sr))
            kon = sr;
        else
            pocz = sr;
    }
    printf("%I64d", kon);
    return 0;
}