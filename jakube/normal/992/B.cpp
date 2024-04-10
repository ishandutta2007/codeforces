#include <bits/stdc++.h>
using namespace std;

vector<int> primes;
void compute_primes(int n)
{
    std::vector<bool> m(n + 1, false);

    int root = std::sqrt(n) + 1;
    for (int i = 1; i <= root; i++) {
        for (int j = 1; j <= root; j++) {
            int a = 4 * i * i + j * j;
            int b = 3 * i * i + j * j;
            int c = 3 * i * i - j * j;

            if (a <= n && (a % 12 == 1 || a % 12 == 5))
                m[a].flip();
            if (b <= n && b % 12 == 7)
                m[b].flip();
            if (i > j && c <= n && c % 12 == 11)
                m[c].flip();
        }
    }

    for (int i = 5; i * i <= n; i++) {
        if (m[i]) {
            for (int j = 1; j * i * i <= n; j++)
                m[j * i * i] = false;
        }
    }

    primes = {2, 3};
    for (int i = 5; i < n; i++) {
        if (m[i])
            primes.push_back(i);
    }
}

std::vector<int> divisors(int x) {
    std::vector<int> d;
    d.push_back(1);

    for (int p : primes) {
        int b = 1;
        while (x % p == 0) {
            b *= p;
            x /= p;
        }
        if (b > 1) {
            int n = d.size();
            for (int i = 0; i < n; i++) {
                d.push_back(d[i] * b);
            }
        }
    }
    if (x > 1) {
        int n = d.size();
        for (int i = 0; i < n; i++) {
            d.push_back(d[i] * x);
        }
    }
    return d;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    compute_primes(1e5);
    int l, r, x, y;
    cin >> l >> r >> x >> y;
    if (y % x != 0) {
        cout << 0 << '\n';
        return 0;
    }

    int cnt = 0;
    for (int d : divisors(y / x)) {
        int a = d * x;
        int b = (y / x / d) * x;
        if (a >= l && a <= r && b >= l && b <= r)
            cnt++;
    }
    cout << cnt << '\n';
}