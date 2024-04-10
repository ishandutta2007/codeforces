#include <bits/stdc++.h>
using namespace std;

struct Query
{
    long long n;
    bool ans;
};

std::vector<int> compute_primes(int n)
{
    std::vector<bool> m(n + 1, false);

    int root = std::sqrt(n) + 1;
    for (int i = 1; i <= root; i++) {
        for (int j = 1; j <= root; j++) {
            int a = 4 * i * i + j * j;
            int b = 3 * i * i + j * j;
            int c = 3 * i * i - j * j;

            if (a <= n && (a % 12 == 1 || a % 12 == 5))
                m[a].flip();
            if (b <= n && b % 12 == 7)
                m[b].flip();
            if (i > j && c <= n && c % 12 == 11)
                m[c].flip();
        }
    }

    for (int i = 5; i * i <= n; i++) {
        if (m[i]) {
            for (int j = 1; j * i * i <= n; j++)
                m[j * i * i] = false;
        }
    }

    std::vector<int> primes = {2, 3};
    for (int i = 5; i < n; i++) {
        if (m[i])
            primes.push_back(i);
    }
    return primes;
}

template <typename T>
T floor_div(T a, long long b) {
    return (a < 0 ? a - (b - 1) : a) / b;
}

template <typename T>
T ceil_div(T a, long long b) {
    return (a >= 0 ? a + (b - 1) : a) / b;
}

template <typename T>
class LinearDiophantine {
public:
    static T extended_gcd(T a, T b, T& x, T& y) {
        if (a == 0) {
            x = 0;
            y = 1;
            return b;
        }
        long long d = extended_gcd(b % a, a, y, x);
        x -= b / a * y;
        return d;
    }

    static bool solve(T a, T b, T c, T& x, T& y, T& g) {
        if (a == 0) {
            if (b == 0) {
                x = y = 0;
                g = 1;
                return c == 0;
            } else {
                x = 0;
                y = c / b;
                g = abs(b);
                return c % b == 0;
            }
        } else {
            if (b == 0) {
                x = c / a;
                y = 0;
                g = abs(b);
                return c % a == 0;
            } else {
                g = extended_gcd(a, b, x, y);
                T dx = c / a;
                c %= a;
                T dy = c / b;
                c %= b;
                x = dx + multiply_mod(x, c / g, b);
                y = dy + multiply_mod(y, c / g, a);
                g = abs(g);
                return c % g == 0;
            }
        }
    }

    static T multiply_mod(T x, T y, T m) {
        int sign = (x < 0 ? -1 : 1) * (y < 0 ? -1 : 1);
        x = abs(x) % m;
        y = abs(y) % m;
        T res = 0;
        while (y) {
            if (y & 1)
                res = (res + x) % m;
            x = (x << 1) % m;
            y >>= 1;
        }
        return sign * res;
    }
};

vector<long long> dijkstra(vector<vector<pair<int, long long>>> const& adj, int v0) {
    int n = adj.size();
    vector<long long> cost(n, -1);
    priority_queue<pair<long long, int>> pq;
    pq.push({0, v0});
    cost[v0] = 0;
    while (!pq.empty()) {
        auto x = pq.top();
        pq.pop();
        long long c = -x.first;
        int v = x.second;
        if (c > cost[v])
            continue;
        cost[v] = c;
        for (auto next : adj[v]) {
            if (cost[next.first] == -1 || cost[next.first] > c + next.second) {
                cost[next.first] = c + next.second;
                pq.push({-(c + next.second), next.first});
            }
        }
    }
    return cost;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    auto primes = compute_primes(34'000'000);
    int t;
    cin >> t;
    vector<Query> queries(t);
    map<long long, vector<int>> m;
    for (int i = 0; i < t; i++) {
        long long n, k;
        cin >> n >> k;
        m[k].push_back(i);
        queries[i].n = n;
    }
    
    for (auto pp : m) {
        auto k = pp.first;
        auto indices = pp.second;
        vector<long long> p;
        for (int d : primes) {
            if (k % d == 0) {
                p.push_back(d);
                do {
                    k /= d;
                } while (k % d == 0);
            }
        }
        if (k > 1)
            p.push_back(k);

        if (p.size() == 0) {
            for (int i : indices) {
                auto& q = queries[i];
                q.ans = false;
            }
            continue;
        }

        vector<vector<pair<int, long long>>> adj;
        vector<long long> cost;
        if (p.size() > 2) {
            adj.resize(p[0]);
            for (int v = 0; v < p[0]; v++) {
                for (int i = 1; i < (int)p.size(); i++) {
                    adj[v].push_back({(v + p[i]) % p[0], p[i]});
                }
            }
            cost = dijkstra(adj, 0);
        }

        for (int i : indices) {
            auto& q = queries[i];
            if (p.size() == 0) {
                q.ans = false;
            } else if (p.size() == 1) {
                q.ans = q.n % p[0] == 0;
            } else if (p.size() == 2) {
                long long x, y, g;
                LinearDiophantine<long long>::solve(p[0], p[1], q.n, x, y, g);
                // solutions are (x + k*p[1], y-k*p[0])
                // x + k*p[1] >= 0
                // k*p[1] >= -x
                long long mi1 = ceil_div(-x, p[1]);
                // y - k*p[0] >= 0
                // y >= k*p[0]
                long long ma2 = floor_div(y, p[0]);
                q.ans = mi1 <= ma2;
            } else {
                q.ans = q.n >= cost[q.n % p[0]];
            }
        }
    }

    for (auto q : queries) {
        if (q.ans)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
}