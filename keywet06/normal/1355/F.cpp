#include <bits/stdc++.h>

const long long Q = 1e18;
const int X = 1e9;

bool isPrime[1000];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    auto query = [&](long long q) {
        std::cout << "? " << q << std::endl;
        int res;
        std::cin >> res;
        return res;
    };
    std::fill(isPrime + 2, isPrime + 1000, true);
    for (int i = 2; i < 1000; ++i)
        if (isPrime[i])
            for (int j = i * i; j < 1000; j += i) isPrime[j] = false;
    std::vector<int> primes;
    for (int i = 2; i < 1000; ++i)
        if (isPrime[i]) primes.push_back(i);
    int t;
    std::cin >> t;
    while (t--) {
        std::vector<int> can;
        for (int i = 0, j = 0; i < 17; ++i) {
            const int l = j;
            long long x = 1;
            while (x <= Q / primes[j]) x *= primes[j++];
            x = query(x);
            for (int k = l; k < j; ++k) {
                if (x % primes[k] == 0) can.push_back(primes[k]);
            }
        }
        int d = 1;
        for (int i = 0; i < int(can.size()); i += 2) {
            long long x = 1;
            for (int j = i; j < std::min(i + 2, int(can.size())); ++j) {
                int y = 1;
                while (y <= X / can[j]) y *= can[j];
                x *= y;
            }
            x = query(x);
            for (int j = i; j < std::min(i + 2, int(can.size())); ++j) {
                int t = 0;
                while (x % can[j] == 0) {
                    x /= can[j];
                    ++t;
                }
                d *= (t + 1);
            }
        }
        if (d <= 2) {
            std::cout << "! " << d + 7 << std::endl;
        } else {
            std::cout << "! " << 2 * d << std::endl;
        }
    }
    return 0;
}