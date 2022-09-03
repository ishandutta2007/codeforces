#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;


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
SieveOfEratosthenes sieve(1000000);

// Shortest cycle detection of undirected simple graphs based on 01-BFS
// Assumption: only two types of edges are permitted: weight = 0 or W ( > 0)
// Complexity: O(E)
// Verified: <https://codeforces.com/contest/1325/problem/E>
struct ShortestCycle01
{
    int V, E;
    int INVALID = -1;
    std::vector<std::vector<std::pair<int, int>>> to;  // (nxt, weight)
    ShortestCycle01() = default;
    ShortestCycle01(int V) : V(V), E(0), to(V) {}
    void add_edge(int s, int t, int len) {
        assert(0 <= s and s < V);
        assert(0 <= t and t < V);
        to[s].emplace_back(t, len);
        to[t].emplace_back(s, len);
        E++;
    }

    std::vector<int> dist;
    std::vector<int> prev;
    // Find minimum length simple cycle which passes vertex `v`
    // - return: (LEN, (a, b))
    //   - LEN: length of the shortest cycles if exists, numeric_limits<int>::max() otherwise.
    //   - the cycle consists of vertices [v, ..., prev[prev[a]], prev[a], a, b, prev[b], prev[prev[b]], ..., v]
    std::pair<int, std::pair<int, int>> Solve(int v) {
        assert(0 <= v and v < V);
        dist.assign(V, std::numeric_limits<int>::max());
        dist[v] = 0;
        prev.assign(V, -1);
        std::deque<std::pair<int, int>> bfsq;
        std::vector<std::pair<std::pair<int, int>, int>> add_edge;
        bfsq.emplace_back(v, -1);
        while (!bfsq.empty()) {
            int now = bfsq.front().first, prv = bfsq.front().second;
            bfsq.pop_front();
            for (auto nxt : to[now]) if (nxt.first != prv) {
                if (dist[nxt.first] == std::numeric_limits<int>::max()) {
                    dist[nxt.first] = dist[now] + nxt.second;
                    prev[nxt.first] = now;
                    if (nxt.second) bfsq.emplace_back(nxt.first, now);
                    else bfsq.emplace_front(nxt.first, now);
                }
                else add_edge.emplace_back(std::make_pair(now, nxt.first), nxt.second);
            }
        }
        int minimum_cycle = std::numeric_limits<int>::max();
        int s = -1, t = -1;
        for (auto edge : add_edge) {
            int a = edge.first.first, b = edge.first.second;
            int L = dist[a] + dist[b] + edge.second;
            if (L < minimum_cycle) minimum_cycle = L, s = a, t = b;
        }
        return std::make_pair(minimum_cycle, std::make_pair(s, t));
    }
};

int main()
{
    ShortestCycle01 graph(1000001);

    int ret = 1e9;
    int N;
    cin >> N;
    vector<int> cnt(1000001);
    while (N--) {
        int a;
        cin >> a;
        auto f = sieve.Factorize(a);
        vector<int> pr;
        int prod = 1;
        for (auto p : f) if (p.second % 2) pr.push_back(p.first), prod *= p.first;
        if (pr.size() == 0) {
            puts("1");
            return 0;
        }
        pr.push_back(1);
        graph.add_edge(pr[0], pr[1], 1);
        cnt[prod]++;
        if (cnt[prod] >= 2) ret = 2;
    }
    if (ret == 2) {
        puts("2");
        return 0;
    }
    for (int r = 1; r < 1000; r++) {
        if (graph.to[r].size() > 1) ret = min(ret, graph.Solve(r).first);
    }
    cout << (ret > 1e8 ? -1 : ret) << endl;
}