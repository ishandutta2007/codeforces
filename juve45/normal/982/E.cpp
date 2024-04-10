#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

const long long N = 100;

long long n, k, m, x, y, vx, vy, k2;

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
    out << v.size() << '\n';
    for(auto e : v) out << e << ' ';
    return out;
}


long long gcd (long long a, long long b, long long & x, long long & y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    long long x1, y1;
    long long d = gcd (b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

bool find_any_solution (long long a, long long b, long long c, long long & x0, long long & y0, long long & g) {
    g = gcd (abs(a), abs(b), x0, y0);
    if (c % g != 0)
        return false;
    x0 *= c / g;
    y0 *= c / g;
    if (a < 0)   x0 *= -1;
    if (b < 0)   y0 *= -1;
    return true;
}

void shift_solution (long long & x, long long & y, long long a, long long b, long long cnt) {
    x += cnt * b;
    y -= cnt * a;
}
 
bool invx, invy;

long long gcdExtended(long long a, long long b, long long *x, long long *y);
 
// Function to find modulo inverse of a
long long modInverse(long long a, long long m)
{
    long long x, y;
    long long g = gcdExtended(a, m, &x, &y);
    if (g != 1)
        return -1;
    else
    {
        // m is added to handle negative x
        long long res = (x%m + m) % m;
        return res;
    }
}
 
// C function for extended Euclidean Algorithm
long long gcdExtended(long long a, long long b, long long *x, long long *y)
{
    // Base Case
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }
 
    long long x1, y1; // To store results of recursive call
    long long gcd = gcdExtended(b%a, a, &x1, &y1);
 
    // Update x and y using results of recursive
    // call
    *x = y1 - (b/a) * x1;
    *y = x1;
 
    return gcd;
}

long long inv(long long a, long long m)
{
    long long m0 = m, t, q;
    long long x0 = 0, x1 = 1;
 
    if (m == 1)
       return 0;
    // Apply extended Euclid Algorithm
    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
 
    if (x1 < 0)
       x1 += m0;
    return x1;
}
 
// k is size of num[] and rem[].  Returns the smallest
// number x such that:
//  x % num[0] = rem[0],
//  x % num[1] = rem[1],
//  ..................
//  x % num[k-2] = rem[k-1]
// Assumption: Numbers in num[] are pairwise coprime
// (gcd for every pair is 1)
long long findMinX(long long num[], long long rem[], long long k)
{
    // Compute product of all numbers
    long long prod = 1;
    for (long long i = 0; i < k; i++)
        prod *= num[i];
 
    // Initialize result
    long long result = 0;
 
    // Apply above formula
    for (long long i = 0; i < k; i++)
    {
        long long pp = prod / num[i];
        dbg(rem[i]);
        dbg(inv(pp, num[i]));
        dbg(pp);
        result += ((rem[i] * inv(pp, num[i])) % num[i]) * pp;
    }
    dbg(result);
    return result % prod;
}
 

int main() {
    ios_base::sync_with_stdio(false);
    
    cin >> n >> m >> x >> y >> vx >> vy;

    if(vx == 0) {
        if(x == 0 || x == n) {
            if(vy < 0)
                m = 0;
            return cout << x << " " << m << '\n', 0;
        }
        return cout << "-1\n", 0;
    }

    if(vy == 0) {
        if(y == 0 || y == m) {
            if(vx < 0)
                n = 0;
            return cout << n << " " << y << '\n', 0;
        }
        return cout << "-1\n", 0;
    }


    if(vx == -1) {
        invx = true;
        x = n - x;
        vx = 1;
    }
    if(vy == -1) {
        invy = true;
        y = m - y;
        vy = 1;
    }
    long long X = x;
    long long Y = y;
    long long cn = n;
    long long cm = m;
    long long g = __gcd(n, m);
    
    n /= g;
    m /= g;
    if(g != 1 && x % g != y % g)
        return cout << "-1\n", 0;
    long long off = g - (x % g);
    if(off == g) off = 0;
    dbg(off);
    x += off;
    y += off;
    dbg(x);
    dbg(y);
    dbg(g);
    x = n * g - x;
    y = m * g - y;
    dbg(x);
    dbg(y);
    x /= g;
    y /= g;
    dbg(x);
    dbg(y);
    long long rem[] = {x, y};
    long long num[] = {n, m};

    long long p = findMinX(num, rem, 2);
    p *= g;
    p += off;

    x = X;
    y = Y;
    long long k = x + p;
    long long k2 = y + p;
    n = cn;
    m = cm;
    k /= n;
    k2 /= m;
    dbg(p);
    dbg(k);
    dbg(k2);    
    if(k % 2 == 0) 
        n = cn - n;
    if(k2 % 2 == 0) 
        m = cm - m;

    if(invy)
        m = cm - m;
    if(invx)
        n = cn - n;

    cout << n << ' ' << m << '\n';
    
}