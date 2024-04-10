#include <cstdio>
#include <cstring>

const int MOD = (int)1e9 + 7;

const int N = 1000000;

bool visited[N];

int main() {
    int p, k;
    scanf("%d%d", &p, &k);
    int result = 1;
    if (k == 0) {
        for (int i = 0; i < p - 1; ++ i) {
            result = (long long)result * p % MOD;
        }
    } if (k == 1) {
        for (int i = 0; i < p; ++ i) {
            result = (long long)result * p % MOD;
        }
    } else {
        memset(visited, 0, sizeof(visited));
        for (int i = 1; i < p; ++ i) {
            if (!visited[i]) {
                int power = 1;
                for (int j = i; !visited[j]; j = (long long)j * k % p) {
                    power = (long long)power * k % p;
                    visited[j] = true;
                }
                if (power == 1) {
                    result = (long long)result * p % MOD;
                }
            }
        }
    }
    printf("%d\n", result);
    return 0;
}