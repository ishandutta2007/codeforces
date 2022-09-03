#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)

// Sieve of Eratosthenes
// (*this)[i] = (divisor of i, greater than 1)
// Example: [0, 1, 2, 3, 2, 5, 3, 7, 2, 3, 2, 11, ...]
// Complexity: Space O(MAXN), Time (construction) O(MAXNloglogMAXN)
struct SieveOfEratosthenes : std::vector<int>
{
    std::vector<int> primes;
    SieveOfEratosthenes(int MAXN) : std::vector<int>(MAXN + 1) {
        std::iota(begin(), end(), 0);
        for (int i = 2; i <= MAXN; i++) {
            if ((*this)[i] == i) {
                primes.push_back(i);
                for (int j = i; j <= MAXN; j += i) (*this)[j] = i;
            }
        }
    }
    using T = long long int;
    // Prime factorization for x <= MAXN^2
    // Complexity: O(log x)          (x <= MAXN)
    //             O(MAXN / logMAXN) (MAXN < x <= MAXN^2)
    std::map<T, int> Factorize(T x) {
        assert(x <= 1LL * (int(size()) - 1) * (int(size()) - 1));
        std::map<T, int> ret;
        if (x < int(size())) {
            while (x > 1) {
                ret[(*this)[x]]++;
                x /= (*this)[x];
            }
        }
        else {
            for (auto p : primes) {
                while (!(x % p)) x /= p, ret[p]++;
                if (x == 1) break;
            }
            if (x > 1) ret[x]++;
        }
        return ret;
    }
    std::vector<T> Divisors(int x) {
        std::vector<T> ret{1};
        for (auto p : Factorize(x)) {
            int n = ret.size();
            for (int i = 0; i < n; i++) {
                for (T a = 1, d = 1; d <= p.second; d++) {
                    a *= p.first;
                    ret.push_back(ret[i] * a);
                }
            }
        }
        return ret; // Not sorted
    }
    // Moebius function Table
    // return: [0=>0, 1=>1, 2=>-1, 3=>-1, 4=>0, 5=>-1, 6=>1, 7=>-1, 8=>0, ...]
    std::vector<int> GenerateMoebiusFunctionTable() {
        std::vector<int> ret(size());
        for (int i = 1; i < int(size()); i++) {
            if (i == 1) ret[i] = 1;
            else if ((i / (*this)[i]) % (*this)[i] == 0) ret[i] = 0;
            else ret[i] = -ret[i / (*this)[i]];
        }
        return ret;
    }
};
SieveOfEratosthenes sieve(100000);

lint sol2(lint M) {
    map<lint, int> fac = sieve.Factorize(M);
    for (auto p : fac) M = M / p.first * (p.first - 1);
    return M;
}

lint solve()
{
    lint A, M;
    cin >> A >> M;
    lint G = __gcd(A, M);
    return sol2(M / G);
}

int main()
{
    int T;
    cin >> T;
    while (T--) cout << solve() << endl;
}