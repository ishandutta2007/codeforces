#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;
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
};
SieveOfEratosthenes sieve(100000);

int query(lint Q)
{
    cout << "? " << Q << endl;
    int ret;
    cin >> ret;
    return ret;
}

void answer(lint ans)
{
    cout << "! " << ans << endl;
}

void solve()
{
    map<lint, int> mf;

    int api = 22;

    vector<int> prime_to_check;

    int ip = 0;
    while (true)
    {
        if ((api - 1) * 2 < int(prime_to_check.size())) break;
        __int128 q = 1;
        while (ip < sieve.primes.size())
        {
            lint p = sieve.primes[ip];
            // dbg(p);
            if (q * p >= 1000000000000000000LL) break;
            q *= p;
            ip++;
        }
        int g = query(q);
        api--;
        for (auto p : sieve.Factorize(g)) prime_to_check.push_back(p.first);
    }
    lint nb = 1;
    for (int i = 0; i < prime_to_check.size(); i += 2)
    {
        if (api <= 0) break;
        lint n1 = 1, n2 = 1;
        lint p1 = prime_to_check[i];
        while (n1 * p1 <= 1000000000) n1 *= p1;
        if (i + 1 < prime_to_check.size())
        {
            lint p2 = prime_to_check[i + 1];
            while (n2 * p2 <= 1000000000) n2 *= p2;
        }
        for (auto p : sieve.Factorize(query(n1 * n2))) nb *= p.second + 1;
        api--;
    }
    answer(nb * 2);
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
}