#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <tuple>
#include <utility>
#include <queue>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;
typedef long long ll;

const ll MOD = 998244353;
const ll BOUND = 33 * 1000000;
vector<ll> primes;
vector<bool> isPrime(BOUND + 1, true);

void erath() {
    primes.reserve(2048);
    for (ll i = 2; i < BOUND; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (ll j = i * i; j < BOUND; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

vector<ll> findFactors(ll D) {
    vector<ll> res;
    for (auto p : primes) {
        if (D % p == 0) {
            res.push_back(p);
            while (D % p == 0) {
                D /= p;
            }
        }
    }
    if (D != 1) {
        res.push_back(D);
    }
    return res;
}

vector<ll> findPowers(ll D, vector<ll>& factors) {
    vector<ll> powers(factors.size(), 0);
    for (int i = 0; i < factors.size(); i++) {
        while (D % factors[i] == 0) {
            D /= factors[i];
            powers[i]++;
        }
    }
    return powers;
}

ll pow(ll a, int n) {
    if (n == 0) return 1;
    if (n == 1) return a;
    ll res = pow(a, n / 2);
    res = (res * res) % MOD;
    if (n % 2 == 1) res = (res * a) % MOD;
    return res;
}

ll inv(int a) {
    return pow(a, MOD - 2);
}

void factorialPrecomp(int maxim, vector<ll>& fact, vector<ll>& invFact) {
    fact[0] = 1;
    invFact[0] = 1;
    for (ll i = 1; i < maxim; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
        invFact[i] = inv(fact[i]);
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    erath();
    vector<ll> fact(1000);
    vector<ll> invFact(1000);
    factorialPrecomp(1000, fact, invFact);
    ll D;
    cin >> D;
    vector<ll> factors = findFactors(D);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        ll u, v;
        cin >> u >> v;
        vector<ll> uPow = findPowers(u, factors);
        vector<ll> vPow = findPowers(v, factors);
        
        vector<ll> neg, pos;
        for (int i = 0; i < uPow.size(); i++) {
            if (uPow[i] < vPow[i]) {
                neg.push_back(vPow[i] - uPow[i]);
            } else if (uPow[i] > vPow[i]) {
                pos.push_back(uPow[i] - vPow[i]);
            }
        }

        ll negSum = 0;
        ll posSum = 0;
        for (auto negElem : neg) negSum += negElem;
        for (auto posElem : pos) posSum += posElem;
        ll res = (fact[negSum] * fact[posSum]) % MOD;
        for (auto negElem : neg) res = (res * invFact[negElem]) % MOD;
        for (auto posElem : pos) res = (res * invFact[posElem]) % MOD;
        cout << res << "\n";
    }
}