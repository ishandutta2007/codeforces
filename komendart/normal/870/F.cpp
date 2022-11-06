#include <iostream>

using namespace std;

using ll = long long;
const int maxn = 1e7 + 5;

int n;
int prime[maxn];
char bad[maxn];
int phi[maxn];
int number_of_prime_divisors[maxn];
int pref_smallest_prime[maxn];
int number_of_bad = 0;

void calc_arrays() {
    for (int i = 1; i <= n; ++i) {
        phi[i] = i;
    }
    for (int i = 2; i <= n; ++i) {
        if (prime[i]) continue;
        for (int j = i; j <= n; j += i) {
            if (!prime[j]) prime[j] = i;
            phi[j] /= i;
            phi[j] *= i - 1;
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (i == 1 || prime[i] == i && i * 2 > n) {
            bad[i] = true;
            ++number_of_bad;
        }
    }
    for (int i = 2; i <= n; ++i) {
        if (prime[i] == i) {
            number_of_prime_divisors[i] = 1;
        } else if (prime[i / prime[i]] == prime[i]) {
            number_of_prime_divisors[i] = number_of_prime_divisors[i / prime[i]];
        } else {
            number_of_prime_divisors[i] = number_of_prime_divisors[i / prime[i]] + 1;
        }
    }
}

ll get_dist_one() {
    ll ans = 0;
    for (int i = 2; i <= n; ++i) {
        if (!bad[i]) {
            ans += i - 1 - phi[i];
        }
    }
    return ans;
}

ll get_dist_two() {
    ll ans = 0;
    int pref_noncomposite = 1;
    for (int i = 2; i <= n; ++i) {
        if (prime[i] != i) {
            ans += phi[i];
            ans -= pref_noncomposite;
            ans += number_of_prime_divisors[i];
        } else {
            ++pref_noncomposite;
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (!bad[i]) {
            ++pref_smallest_prime[prime[i]];
        }
    }
    for (int i = 1; i <= n; ++i) {
        pref_smallest_prime[i] += pref_smallest_prime[i - 1];
    }
    for (int i = 2; i <= n; ++i) {
        if (prime[i] != i || bad[i]) continue;
        ans += pref_smallest_prime[n / i];
        for (int j = i; j <= n; j += i) {
            if (prime[j] <= n / i) {
                --ans;
            }
        }
    }
    for (int i = 2; i <= n; ++i) {
        int a = prime[i];
        int b = i / a;
        if (b != 1 && prime[b] == b && a != b) {
            --ans;
        }
    }
    return ans;
}

ll solve(int _n) {
    n = _n;
    calc_arrays();
    ll cnt_one = get_dist_one();
    ll cnt_two = get_dist_two();
    ll cnt_three = (ll) (n - number_of_bad) * (n - number_of_bad - 1) / 2 - cnt_one - cnt_two;
    return cnt_one * 1 + cnt_two * 2 + cnt_three * 3;
}

int main() {
    int n;
    cin >> n;
    cout << solve(n) << endl;
}