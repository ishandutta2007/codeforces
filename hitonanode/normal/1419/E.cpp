#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)

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
    std::vector<T> Divisors(T x) {
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
};
SieveOfEratosthenes sieve(40000);

void solve()
{
    int N;
    cin >> N;
    auto f = sieve.Factorize(N);
    auto divs = sieve.Divisors(N);
    sort(divs.begin(), divs.end());
    if (f.size() == 1)
    {
        for (auto x : divs) if (x > 1) cout << x << ' ';
        cout << "\n0\n";
        return;
    }
    else
    {
        vector<int> joints, ps, ret;
        for (auto p : f) ps.emplace_back(p.first);
        REP(i, ps.size())
        {
            joints.emplace_back(ps[i] * ps[(i + 1) % ps.size()]);
            if (f.size() == 2 and i == 1)
            {
                joints.pop_back();
                if (N % (1LL * ps[0] * ps[0] * ps[1]) == 0) joints.emplace_back(ps[0] * ps[0] * ps[1]);
                else if (N % (1LL * ps[0] * ps[1] * ps[1]) == 0) joints.emplace_back(ps[0] * ps[1] * ps[1]);
            }
        }
        vector<int> used(divs.size());
        for (auto x : joints)
        {
            used[lower_bound(divs.begin(), divs.end(), x) - divs.begin()] = 1;
        }
        REP(ip, ps.size())
        {
            int p = ps[ip];
            REP(i, used.size()) if (!used[i] and divs[i] % p == 0)
            {
                used[i] = 1;
                ret.emplace_back(divs[i]);
            }
            if (joints.size() > ip) ret.emplace_back(joints[ip]);
        }
        ret.resize(divs.size() - 1);
        for (auto x : ret) cout << x << ' ';
        cout << '\n' << (joints.size() != f.size()) << '\n';
    }
}
int main()
{
    int T;
    cin >> T;
    while (T--) solve();
}