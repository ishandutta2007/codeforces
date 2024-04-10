#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using pint = pair<int, int>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }

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
SieveOfEratosthenes sieve(200001);

// UnionFind, able to rewind to the previous state by undo()
// Written for Educational Codeforces 62 F, although not verified yet.
struct UndoSizeAwareUnionFind
{
    using pint = std::pair<int, int>;
    std::vector<int> par, cou;
    std::stack<std::pair<int, pint>> history;
    UndoSizeAwareUnionFind(int N) : par(N), cou(N, 1) {
        std::iota(par.begin(), par.end(), 0);
    }
    int find(int x) { return (par[x] == x) ? x : find(par[x]); }
    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        if (cou[x] < cou[y]) std::swap(x, y);
        history.emplace(y, pint(par[y], cou[x]));
        if (x != y) par[y] = x, cou[x] += cou[y];
        return true;
    }
    void undo()
    {
        cou[par[history.top().first]] = history.top().second.second;
        par[history.top().first] = history.top().second.first;
        history.pop();
    }
    void reset() {
        while (!history.empty()) undo();
    }
    int count(int x) { return cou[find(x)]; }
    bool same(int x, int y) { return find(x) == find(y); }
};

// f[n]nn*if[n*i] O(NloglogN)
// p
//  <https://yukicoder.me/submissions/385043>
template<typename T>
void fast_integer_zeta(vector<T> &f)
{
    int N = f.size() - 1;
    vector<int> is_prime(N + 1, 1);
    for (int p = 2; p <= N; p++) if (is_prime[p]) {
        for (int q = p * 2; q <= N; q += p) is_prime[q] = 0;
        for (int j = N / p * p; j > 0; j -= p) f[j / p] += f[j];
    }
}

// fast_integer_zeta O(NloglogN)
//  <https://yukicoder.me/submissions/385120>
template <typename T>
void fast_integer_moebius(vector<T> &f)
{
    int N = f.size() - 1;
    vector<int> is_prime(N + 1, 1);
    for (int p = 2; p <= N; p++) if (is_prime[p]) {
        for (int q = p * 2; q <= N; q += p) is_prime[q] = 0;
        for (int j = p; j <= N; j += p) f[j / p] -= f[j];
    }
}

int AMAX = 200001;
int main()
{
    int N;
    cin >> N;
    UndoSizeAwareUnionFind uf(N);
    vector<vector<int>> euse(AMAX);

    vector<lint> ret(AMAX);
    vector<int> A(N);
    cin >> A;
    for (auto a : A) for (auto d : sieve.Divisors(a)) ret[d]++;

    vector<pint> edges;
    REP(eid, N - 1) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        edges.emplace_back(u, v);
        for (auto d : sieve.Divisors(__gcd(A[u], A[v]))) euse[d].push_back(eid);
    }

    vector<int> tmp(AMAX);

    REP(d, AMAX) {
        uf.reset();
        for (auto e : euse[d]) {
            lint sz1 = uf.count(edges[e].first), sz2 = uf.count(edges[e].second);
            if (uf.unite(edges[e].first, edges[e].second)) ret[d] += sz1 * sz2;
        }
    }

    fast_integer_moebius(ret);
    FOR(i, 1, AMAX) if (ret[i]) {
        printf("%d %lld\n", i, ret[i]);
    }
}