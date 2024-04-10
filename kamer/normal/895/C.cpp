#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>
#include <utility>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
using namespace std;
typedef long long ll;

const int BOUND = 70;
const int MOD = 1'000'000'007;

vector<int> primes;
vector<bool> is_prime(BOUND + 1, true);

ll expo(ll a, ll n) {
    if (n == 0) return 1;
    if (n == 1) return a;
    ll sqrt_a = expo(a, n / 2);
    sqrt_a = (sqrt_a * sqrt_a) % MOD;
    if (n % 2 == 0) {
        return sqrt_a;
    } else {
        return (sqrt_a * a) % MOD;
    }
}

void eratosthenes() {
    for (int i = 2; i < BOUND; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = 2 * i; j < BOUND; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

ll decompose(ll a) {
    ll res = 0;
    for (int i = 0; i < primes.size(); i++) {
        int prime = primes[i];
        bool exp = false;
        while (a % prime == 0) {
            exp = !exp;
            a /= prime;
        }
        if (exp) {
            res += ((ll) 1 << i);
        }
    }
    return res;
}

vector<ll> find_basis(vector<ll>& v) {
    set<ll, greater<ll>> basis;
    for (auto el : v) {
        for (auto b : basis) {
            el = min(el, el ^ b);
        }
        if (el) {
            basis.insert(el);
        }
    }

    vector<ll> result;
    for (auto b : basis) {
        result.push_back(b);
    }
    return result;
}


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(14);
    eratosthenes();
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<ll> v;
    for (auto el : a) v.push_back(decompose(el));
    int basis_size = find_basis(v).size();
    cout << expo(2, v.size() - basis_size) - 1 << "\n";
}