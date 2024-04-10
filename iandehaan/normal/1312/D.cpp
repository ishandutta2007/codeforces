#include <bits/stdc++.h>
using namespace std;

int64_t mod = 998244353;

// the same one from gcd_ex.cpp
int64_t gcd_ex(int64_t a, int64_t b, int64_t& s, int64_t& t) {
    int64_t r0 = a, r1 = b, q;
    int64_t s0 = 1, s1 = 0;
    int64_t t0 = 0, t1 = 1;

    //invariant: ri = a*si + b*ti for both i = 0 and i = 1
    while (r1) {
        q = r0 / r1;

        r0 -= q*r1;
        swap(r0, r1);

        s0 -= q*s1;
        swap(s0, s1);

        t0 -= q*t1;
        swap(t0, t1);
    }

    //now r0 = gcd(a, b)
    s = s0;
    t = t0;

    return r0;
}

int64_t mod_inverse(int64_t a, int64_t m) {
    int64_t s, t;

    a %= m;

    /* can ignore the next line a is never nonnegative
      The current standard ensures that if m > 0 and a < 0 then
      a%m wiint64_t be the negative number r closes to 0 such that m | (a-r).
      example: (-22) % 6 == -4
      http://en.cppreference.com/w/cpp/language/operator_arithmetic
      http://en.cppreference.com/w/cpp/numeric/math/div
    */
    if (a < 0) a += m;

    if (gcd_ex(a, m, s, t) > 1) return -1;

    s %= m;

    //must always have this one, even if a > 0 is guaranteed
    if (s < 0) s += m;

    return s;
}

int main() {
   int n, m;
   cin >> n >> m;
   int64_t fac[max(m, n)+1];
   fac[0] = 1;
   for (int i = 1; i <= max(m, n); i++) {
       fac[i] = i*fac[i-1];
       fac[i] %= mod;
   }

   int64_t outsidemul = fac[m];
   outsidemul *= mod_inverse(fac[n-1], mod);
   outsidemul %= mod;
   outsidemul += mod;
   outsidemul %= mod;
   outsidemul *= mod_inverse(fac[m-(n-1)], mod);
   outsidemul %= mod;
   outsidemul += mod;
   outsidemul %= mod;

   int64_t sm = 0;
   for (int i = 2; i <= n-1; i++) {
       int64_t blah = fac[n-3];
       blah *= mod_inverse(fac[i-2], mod);
       blah %= mod;
        blah += mod;
        blah %= mod;
        blah *= mod_inverse(fac[n-3-(i-2)], mod);
        blah %= mod;
        blah += mod;
        blah %= mod;
        sm += blah;
        sm %= mod;
   }

   int64_t out = (outsidemul*sm)%mod;
   out += mod;
   out %= mod;
   out *= (n-2);
   out %= mod;
   cout << out << endl;
}