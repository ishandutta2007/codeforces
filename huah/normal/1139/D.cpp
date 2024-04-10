#include <cstring>
#include <iostream>
typedef long long int int_t;
using std::cin;
using std::cout;
using std::endl;

const int_t mod = 1e9 + 7;
const int_t LARGE = 1e5;
int_t inv[LARGE + 1];
int_t m;
int_t mu[LARGE + 1];
int_t factor[LARGE + 1];
bool isPrime[LARGE + 1];

int main() {
    memset(isPrime, 1, sizeof(isPrime));
    cin >> m;
    inv[1] = 1;
    for (int_t i = 2; i <= m; i++)
        inv[i] = (mod - mod / i) * inv[mod % i] % mod;
    for (int_t i = 2; i <= m; i++)
        if (isPrime[i]) {
            for (int_t j = i * i; j <= m; j += i) {
                factor[j] = i;
                isPrime[j] = false;
            }
            factor[i] = i;
        }
    mu[1] = 1;
    for (int_t i = 2; i <= m; i++) {
        int_t p = factor[i];
        if (i / p % p == 0)
            mu[i] = 0;
        else
            mu[i] = mu[i / p] * -1;
    }
    int_t result = 1;
    for (int_t i = 2; i <= m; i++) {
        int_t x = m / i;
        result = (result - mu[i] * x % mod * inv[m - x] % mod + mod) % mod;
    }
    cout << result << endl;
    return 0;
}