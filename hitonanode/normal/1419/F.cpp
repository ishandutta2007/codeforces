#include <bits/stdc++.h>
using namespace std;
using lint = long long;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template <typename T> vector<T> srtunq(vector<T> vec) { sort(vec.begin(), vec.end()), vec.erase(unique(vec.begin(), vec.end()), vec.end()); return vec; }
template <typename T> istream &operator>>(istream &is, vector<T> &vec) { for (auto &v : vec) is >> v; return is; }
template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec) { os << '['; for (auto v : vec) os << v << ','; os << ']'; return os; }
#ifdef HITONANODE_LOCAL
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl
#else
#define dbg(x)
#endif

// UnionFind Tree (0-indexed), based on size of each disjoint set
struct UnionFind
{
    std::vector<int> par, cou;
    UnionFind(int N = 0) : par(N), cou(N, 1) {
        iota(par.begin(), par.end(), 0);
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

int main()
{
    int N;
    cin >> N;
    vector<lint> X(N), Y(N);
    REP(i, N) cin >> X[i] >> Y[i];

    auto xu = srtunq(X);
    auto yu = srtunq(Y);
    const int H = xu.size(), W = yu.size();

    vector<int> XZ(N), YZ(N);
    REP(i, N)
    {
        XZ[i] = lower_bound(xu.begin(), xu.end(), X[i]) - xu.begin();
        YZ[i] = lower_bound(yu.begin(), yu.end(), Y[i]) - yu.begin();
    }
    dbg(xu);
    dbg(XZ);

    constexpr lint INF = 3e9;
    lint ng = 0, ok = INF;
    while (ok - ng > 1)
    {
        const lint t = (ng + ok) / 2;
        UnionFind uf(N);
        REP(i, N) REP(j, i)
        {
            if (X[i] == X[j] and abs(Y[i] - Y[j]) <= t) uf.unite(i, j);
            if (Y[i] == Y[j] and abs(X[i] - X[j]) <= t) uf.unite(i, j);
        }
        vector<int> roots_(N);
        REP(i, N) roots_[i] = uf.find(i);
        auto zr = srtunq(roots_);
        if (zr.size() > 4)
        {
            ng = t;
            continue;
        }
        if (zr.size() == 1)
        {
            ok = t;
            continue;
        }
        if (zr.size() == 2)
        {
            bool is_ok = false;
            REP(i, N) REP(j, N) if (roots_[i] != roots_[j])
            {
                if (X[i] == X[j] and abs(Y[i] - Y[j]) <= t * 2) is_ok = true;
                if (Y[i] == Y[j] and abs(X[i] - X[j]) <= t * 2) is_ok = true;
                if (abs(X[i] - X[j]) <= t and abs(Y[i] - Y[j]) <= t) is_ok = true;
            }
            if (is_ok)
            {
                ok = t;
                continue;
            }
        }
        vector GD1(zr.size(), vector(H + 1, vector(W + 1, 0)));
        vector GD2(zr.size(), vector(H + 1, vector(W + 1, 0)));

        REP(a, N)
        {
            int ilo = lower_bound(xu.begin(), xu.end(), X[a] - t) - xu.begin();
            int ihi = upper_bound(xu.begin(), xu.end(), X[a] + t) - xu.begin();
            int jlo = lower_bound(yu.begin(), yu.end(), Y[a] - t) - yu.begin();
            int jhi = upper_bound(yu.begin(), yu.end(), Y[a] + t) - yu.begin();
            int z = 0;
            while (zr[z] != roots_[a]) z++;
            GD1[z][ilo][YZ[a]]++;
            GD1[z][ihi][YZ[a]]--;
            GD2[z][XZ[a]][jlo]++;
            GD2[z][XZ[a]][jhi]--;
        }

        REP(z, zr.size())
        {
            REP(i, H) REP(j, W) GD1[z][i + 1][j] += GD1[z][i][j];
            REP(i, H) REP(j, W) GD2[z][i][j + 1] += GD2[z][i][j];
        }
        bool fok = false;
        REP(i, H) REP(j, W)
        {
            int cnt = 0;
            REP(z, zr.size()) cnt += (GD1[z][i][j] + GD2[z][i][j] > 0);
            if (cnt == zr.size()) fok = true;
        }
        if (t == 1)
        {
            dbg(H);
            dbg(W);
            dbg(zr.size());
            dbg(GD1[0]);
            dbg(GD2[0]);
            dbg(GD1[1]);
            dbg(GD2[1]);
            dbg(fok);
        }
        (fok ? ok : ng) = t;
    }

    cout << (ok == INF ? -1 : ok) << '\n';
}