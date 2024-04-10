#include <bits/stdc++.h>
using namespace std;
using pint = pair<int, int>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa){ os << "(" << pa.first << "," << pa.second << ")"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;


struct custom_hash
{
    // <https://codeforces.com/blog/entry/62393>
    static uint64_t splitmix64(uint64_t x)
    {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using uos = gp_hash_table<int, null_type, custom_hash>; // fast unordered_set

using ull = unsigned long long;

inline ull tousa(ull l, ull r) {
    // l + ... + r - 1
    return ((r - 1) * r - (l - 1) * l) / 2;
}
int main()
{
    ull N;
    int M;
    cin >> N >> M;
    ull A, B, C;
    cin >> A >> B >> C;

    ull ret = 0;
    // zero
    {
        ull n_lo = 0, n_hi = N;
        ull sum_lo = 0, sum_hi = tousa(0, N);
        REP(i, N) {
            n_hi--;
            sum_hi -= i;
            ret += A * sum_lo * n_hi + C * sum_hi * n_lo + B * i * n_lo * n_hi;

            sum_lo += i;
            n_lo++;
        }
    }

    vector<pint> lrs;
    vector<int> deg(N);

    {
        vector<ull> nb_lo(N);
        vector<ull> nb_hi(N);
        vector<ull> sum_lo(N);
        vector<ull> sum_hi(N);

        // one
        while (M--)
        {
            int u, v;
            cin >> u >> v;
            if (u > v) swap(u, v);
            ret -= (A * u + C * v) * (v - u - 1) + B * tousa(u + 1, v);
            ret -= (N - 1 - v) * (A * u + B * v) + C * tousa(v + 1, N);
            ret -= u * (B * u + C * v) + A * tousa(0, u);
            nb_hi[u]++;
            nb_lo[v]++;
            sum_hi[u] += v;
            sum_lo[v] += u;
            lrs.emplace_back(u, v);
            deg[u]++;
            deg[v]++;
        }

        // two
        REP(i, N) ret += nb_lo[i] * sum_hi[i] * C + sum_lo[i] * A * nb_hi[i] + B * i * nb_lo[i] * nb_hi[i];
    }
    {
        sort(lrs.rbegin(), lrs.rend());
        vector<ull> nb_lo(N);
        vector<ull> sum_lo(N);
        for (auto lr : lrs) {
            int l = lr.first, r = lr.second;
            ret += sum_lo[r] * B + nb_lo[r] * (l * A + r * C);
            nb_lo[r]++;
            sum_lo[r] += l;
        }
    }
    {
        sort(lrs.begin(), lrs.end(), [](pint l, pint r) { if (l.second != r.second) return l.second < r.second; else return l.first < r.first; });
        vector<ull> nb_hi(N);
        vector<ull> sum_hi(N);
        for (auto lr : lrs) {
            int l = lr.first, r = lr.second;
            ret += sum_hi[l] * B + nb_hi[l] * (l * A + r * C);
            nb_hi[l]++;
            sum_hi[l] += r;
        }
    }

    int TD = 4000;
    vector<int> dense_vertex(N, -1);
    vector<int> dl;
    REP(i, N) if (deg[i] >= TD) {
        dense_vertex[i] = dl.size();
        dl.push_back(i);
    }
    int ND = dl.size();
    vector<vector<int>> edense(ND, vector<int>(ND));
    vector<unordered_set<int>> adj(N);
    vector<vector<int>> adj_dense(N);
    for (auto p : lrs) {
        int u = dense_vertex[p.first];
        int v = dense_vertex[p.second];
        if (u >= 0 and v >= 0) edense[u][v] = 1;
        else {
            int s = p.first, t = p.second;
            if (adj[s].size() > adj[t].size()) swap(s, t);
            for (auto r : adj[s]) {
                if (adj[t].find(r) != adj[t].end()) {
                    if (r < p.first) ret -= r * A + p.first * B + p.second * C;
                    else if (p.second < r) ret -= p.first * A + p.second * B + r * C;
                    else ret -= p.first * A + r * B + p.second * C;
                }
            }
            adj[p.first].insert(p.second);
            adj[p.second].insert(p.first);
        }

        if (u >= 0) adj_dense[p.second].push_back(u);
        if (v >= 0) adj_dense[p.first].push_back(v);
    }

    REP(k, ND) REP(j, k) REP(i, j) if (edense[i][j] and edense[j][k] and edense[i][k]) {
        ret -= A * dl[i] + B * dl[j] + C * dl[k];
    }

    REP(r, N) {
        sort(adj_dense[r].begin(), adj_dense[r].end());
        REP(j, adj_dense[r].size()) REP(i, j) {
            int s = adj_dense[r][i];
            int t = adj_dense[r][j];
            if (adj_dense[s][t]) {
                int u = dl[s];
                int v = dl[t];
                if (r < u) ret -= A * r + B * u + C * v;
                else if (v < r) ret -= A * u + B * v + C * r;
                else ret -= A * u + B * r + C * v;
            }
        }
    }
    cout << ret << "\n";
}