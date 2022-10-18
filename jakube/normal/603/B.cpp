#include <bits/stdc++.h>

using namespace std;

#define ALL(v) v.begin(),v.end()
#define FOR(I, N) for (int I = 0; I < (N); ++I)
#define FORR(I, A, B) for (int I = (A); I < (B); ++I)

const double EPS = 1e-4;
const long double PI = acos((long double)-1.0);

typedef long long int lint;
typedef long double ld;

lint modpow(lint base, lint exp, lint modulus) {
    base %= modulus;
    lint result = 1;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % modulus;
        base = (base * base) % modulus;
        exp >>= 1;
    }
    return result;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie (NULL);
    cout.precision(10);
    cout << fixed;

    lint p, k;
    cin >> p >> k;

    lint result = 1;
    bitset<1000000> s;

    if (k == 0)
    {
        result = modpow(p, p-1, 1000000007);
    }
    else if (k == 1)
    {
        result = modpow(p, p, 1000000007);
    }
    else
    {
        for (lint i = 1; i < p; i++) {
            if (s.test(i))
                continue;

            lint j = i;
            do {
                s.set(j);
                j = (j * k) % p;
            }
            while (i != j);

            result = (result * p) % 1000000007;
        }
    }
    
    cout << result << endl;
}