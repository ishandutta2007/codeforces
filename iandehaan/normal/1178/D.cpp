/*  Author: Noah Weninger, 2018

    Tests if a 64-bit number is prime using the deterministic Miller-Rabin
    algorithm. This requires use of the __uint128_t numeric type, which is
    nonstandard and might not be supported by every compiler.

    Complexity: O(log n) with a relatively large constant

    Reference:
    https://en.wikipedia.org/wiki/Miller%E2%80%93Rabin_primality_test#Deterministic_variants_of_the_test

    Reliability:
    primes2 - Open Kattis
    psuedoprime - Open Kattis
*/

#include<initializer_list>
#include<cstdint>
#include<iostream>
#include <math.h>
using namespace std;

using u128 = uint64_t;
u128 powmod(u128 b, u128 e, u128 m) {
    u128 res = 1;
    for (b %= m; e; e >>= 1) {
        if (e&1) res = res*b%m;
        b = b*b%m;
    }
    return res;
}
bool is_prime(uint64_t n) {
    if (n < 2) return false;
    u128 d = n-1, r = 0;
    while (d%2 == 0) r++, d /= 2;
    for (u128 a : {2,3,5,7,11,13,17,19,23,29,31,37}) {
        if (a > n-2) break;
        u128 x = powmod(a, d, n);
        if (x == 1 || x == n-1) continue;
        for (u128 j = 0; r && j < r-1; j++) {
            x = x*x%n;
            if (x == n-1) goto next;
        }
        return false;
    next:;
    }
    return true;
}
int main() {
    int n;
    cin >> n;
    int conns[n];
    for (int i = 0; i < n; i++) {
        conns[i] = 2;
    }
    int numEdges = n;
    int ind = 0;
    while (!is_prime(numEdges)) {
        if (conns[ind] >= 3) {
            ind++;
            ind %= n;
        }
        numEdges++;
        conns[ind]++;
        ind += 2;
        ind %= n;
        if (conns[ind] >= 3) {
            ind++;
            ind %= n;
        }
        conns[ind]++;
        ind += 2;
        ind %= n;
    }
    cout << numEdges << endl;
    cout << 1 << ' ' << n << endl;
    conns[0]--;
    conns[n-1]--;
    for (int i = 1; i < n; i++) {
        cout <<i << ' ' << i+1 << endl;
        conns[i-1]--;
        conns[i]--;
    }
    for (int i = 0; i < n; i++) {
        int ind = i+2;
        while (conns[i] > 0) {
            
            ind %= n;
            if (abs(ind-i) <= 1) {
                ind++;
                continue;
            }
            if (conns[ind] > 0) {
                cout << i+1 << ' ' << ind+1 << endl;
                conns[ind]--;
                conns[i]--;
            }
            ind++;
        }
    }

}