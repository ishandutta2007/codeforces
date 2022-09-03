#include <bits/stdc++.h>
using namespace std;

// Sieve of Eratosthenes
// (*this)[i] = (divisor of i, greater than 1)
// Example: [0, 1, 2, 3, 2, 5, 3, 7, 2, 3, 2, 11, ...]
// Complexity: Space O(MAXN), Time (construction) O(MAXNloglogMAXN)
struct SieveOfEratosthenes : std::vector<int>
{
    std::vector<int> primes;
    SieveOfEratosthenes(int MAXN) : std::vector<int>(MAXN + 1)
    {
        std::iota(begin(), end(), 0);
        for (int i = 2; i <= MAXN; i++)
        {
            if ((*this)[i] == i)
            {
                primes.push_back(i);
                for (int j = i; j <= MAXN; j += i)
                    (*this)[j] = i;
            }
        }
    }
    using T = long long int;
    // Prime factorization for x <= MAXN^2
    // Complexity: O(log x)          (x <= MAXN)
    //             O(MAXN / logMAXN) (MAXN < x <= MAXN^2)
    std::map<T, int> Factorize(T x)
    {
        assert(x <= 1LL * (int(size()) - 1) * (int(size()) - 1));
        std::map<T, int> ret;
        if (x < int(size()))
        {
            while (x > 1)
            {
                ret[(*this)[x]]++;
                x /= (*this)[x];
            }
        }
        else
        {
            for (auto p : primes)
            {
                while (!(x % p))
                    x /= p, ret[p]++;
                if (x == 1)
                    break;
            }
            if (x > 1)
                ret[x]++;
        }
        return ret;
    }
    std::vector<T> Divisors(int x)
    {
        std::vector<T> ret{1};
        for (auto p : Factorize(x))
        {
            int n = ret.size();
            for (int i = 0; i < n; i++)
            {
                for (T a = 1, d = 1; d <= p.second; d++)
                {
                    a *= p.first;
                    ret.push_back(ret[i] * a);
                }
            }
        }
        return ret; // Not sorted
    }
    // Moebius function Table
    // return: [0=>0, 1=>1, 2=>-1, 3=>-1, 4=>0, 5=>-1, 6=>1, 7=>-1, 8=>0, ...]
    std::vector<int> GenerateMoebiusFunctionTable()
    {
        std::vector<int> ret(size());
        for (int i = 1; i < int(size()); i++)
        {
            if (i == 1)
                ret[i] = 1;
            else if ((i / (*this)[i]) % (*this)[i] == 0)
                ret[i] = 0;
            else
                ret[i] = -ret[i / (*this)[i]];
        }
        return ret;
    }
};

SieveOfEratosthenes sieve(40000);

void solve()
{
    int N;
    cin >> N;
    vector<int> v;
    for (auto p : sieve.primes) {
        int d = p;
        while (N % d == 0) {
            v.push_back(d);
            N /= d;
            d *= p;
            if (v.size() > 1 or N == 1) break;
        }
        if (v.size() > 1 or N == 1) break;
    }
    if (v.size() == 2 and N > 1 and N != v[0] and N != v[1]) {
        puts("YES");
        printf("%d %d %d\n", v[0], v[1], N);
    }
    else puts("NO");
}

int main()
{
    int T;
    cin >> T;
    while (T--) solve();
}