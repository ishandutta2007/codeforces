#include <bits/stdc++.h>
using namespace std;

std::vector<int> compute_primes(int n)
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

    std::vector<int> primes = {2, 3};
    for (int i = 5; i < n; i++) {
        if (m[i])
            primes.push_back(i);
    }
    return primes;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> primes = compute_primes(4e4);
    int x, y;
    cin >> x >> y;
    int x2 = x;
    int y2 = y;
    
    map<int, long long> X, Y;
    for (int p : primes) {
        while (x2 % p == 0) {
            X[p]++;
            x2 /= p;
        }
        while (y2 % p == 0) {
            Y[p]++;
            y2 /= p;
        }
    }
    for (auto& p : X)
        p.second *= y;
    for (auto& p : Y)
        p.second *= x;
    if (X == Y) {
        cout << "=" << '\n';
        return 0;
    }

    if (log(x) * y < log(y) * x)
        cout << "<" << '\n';
    else
        cout << ">" << '\n';
}