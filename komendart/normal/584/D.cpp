#include <bits/stdc++.h>

using namespace std;

vector<int> primes;
vector<char> prime;

bool is_prime(int n) {
    for (int i: primes) {
        if (i * i > n) return true;
        if (n % i == 0) return false;
    }
}

vector<int> result;

void solve(int n) {
    if (is_prime(n)) {
        result.push_back(n);
    } else if (is_prime(n - 2)) {
        result.push_back(2);
        result.push_back(n - 2);
    } else {
        if (n & 1) {
            result.push_back(3);
            n -= 3;
        }
        for (int i: primes) {
            if (is_prime(n - i)) {
                result.push_back(i);
                result.push_back(n - i);
                return;
            }
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);

    int sqrtn = 4e4;
    prime.assign(sqrtn + 1, true);
    for (int i = 2; i <= sqrtn; i++) {
        if (!prime[i]) continue;
        primes.push_back(i);
        for (int j = i + i; j <= sqrtn; j += i) {
            prime[j] = false;
        }
    }

    int n; cin >> n;
    solve(n);

    cout << result.size() << '\n';
    for (auto i: result) {
        cout << i << ' ';
    }
}