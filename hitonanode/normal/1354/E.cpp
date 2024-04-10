#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> void ndarray(vector<T> &vec, int len) { vec.resize(len); }
template<typename T, typename... Args> void ndarray(vector<T> &vec, int len, Args... args) { vec.resize(len); for (auto &v : vec) ndarray(v, args...); }
template<typename T> bool chmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool chmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template<typename T1, typename T2> pair<T1, T2> operator+(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first + r.first, l.second + r.second); }
template<typename T1, typename T2> pair<T1, T2> operator-(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first - r.first, l.second - r.second); }
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const deque<T> &vec){ os << "deq["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const unordered_set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const multiset<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const unordered_multiset<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa){ os << "(" << pa.first << "," << pa.second << ")"; return os; }
template<typename TK, typename TV> ostream &operator<<(ostream &os, const map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }
template<typename TK, typename TV> ostream &operator<<(ostream &os, const unordered_map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;

// UnionFind Tree (0-indexed), based on size of each disjoint set
struct UnionFind
{
    std::vector<int> par, cou;
    UnionFind(int N = 0) : par(N), cou(N, 1) {
        iota(par.begin(), par.end(), 0);
        FOR(i, N / 2, N) cou[i] = 0;
    }
    int find(int x) { return (par[x] == x) ? x : (par[x] = find(par[x])); }
    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        if (cou[x] < cou[y]) std::swap(x, y);
        par[y] = x, cou[x] += cou[y];
        return true;
    }
    int count(int x) { return cou[find(x)]; }
    bool same(int x, int y) { return find(x) == find(y); }
};

void No()
{
    puts("NO");
    exit(0);
}

void solve()
{
    int N, M;
    cin >> N >> M;
    vector<int> v(3);
    cin >> v;
    UnionFind uf(N * 2);
    while (M--)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        uf.unite(u + N, v);
        uf.unite(u, v + N);
    }
    map<int, int> i2p;
    set<int> srid;
    REP(i, N)
    {
        if (uf.same(i, i + N)) No();
        if (srid.count(uf.find(i))) continue;
        i2p[uf.find(i)] = uf.count(i);
        i2p[uf.find(i + N)] = uf.count(i + N);
        srid.insert(uf.find(i));
        srid.insert(uf.find(i + N));
    }

    int S = i2p.size();
    vector<vector<int>> dp(S / 2 + 1, vector<int>(N + 1, -1));
    dp[0][0] = 0;
    int s = 0;
    srid.clear();
    for (auto p : i2p)
    {
        int r = p.first;
        if (srid.count(r)) continue;
        int rr = uf.find((r + N) % (N * 2));
        srid.insert(r);
        srid.insert(rr);
        REP(i, N + 1) if (dp[s][i] != -1)
        {
            dp[s + 1][i + i2p[r]] = r;
            dp[s + 1][i + i2p[rr]] = rr;
        }
        s++;
    }

    if (dp.back()[v[1]] == -1) No();

    s = dp.size() - 1;
    int i = v[1];
    set<int> s2;
    while (s)
    {
        s2.insert(dp[s][i]);
        i -= uf.count(dp[s][i]), s--;
    }

    string ret(N, '.');
    REP(i, N)
    {
        if (s2.count(uf.find(i))) ret[i] = '2';
        else if (v[0]) ret[i] = '1', v[0]--;
        else ret[i] = '3';
    }
    cout << "YES\n" << ret << '\n';
}

int main()
{
    solve();
}