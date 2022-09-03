#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((lint)(x).size())
#define POW2(n) (1LL << (n))
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> bool mmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool mmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
///// This part below is only for debug, not used /////
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa){ os << "(" << pa.first << "," << pa.second << ")"; return os; }
template<typename TK, typename TV> ostream &operator<<(ostream &os, const map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;
///// END /////


/*struct UndoSizeAwareUnionFind
{
    vector<int> par, cou;
    stack<pair<int, pint>> history;
    UndoSizeAwareUnionFind(int N) : par(N), cou(N) { REP(i, N) par[i] = i, cou[i] = 1; }
    int find(int x) { return (par[x] == x) ? x :find(par[x]); }
    void unite(int x, int y) {
        x = find(x), y = find(y);
        if (cou[x] < cou[y]) swap(x, y);
        history.emplace(y, pint(par[y], cou[x]));
        if (x != y) par[y] = x, cou[x] += cou[y];
    }
    void undo()
    {
        cou[par[history.top().first]] = history.top().second.second;
        par[history.top().first] = history.top().second.first;
        history.pop();
    }
    int count(int x) { return cou[find(x)]; }
    bool same(int x, int y) { return find(x) == find(y); }
};*/

struct UndoUnionFind
{
    vector<int> par;
    vector<pint> cou;
    stack<pair<int, pair<int, pint>>> history;
    UndoUnionFind(int N) : par(N), cou(N) {
        REP(i, N) par[i] = i;
        REP(i, N / 2) cou[i].first = 1, cou[i + N / 2].second = 1;
    }
    int find(int x) { return (par[x] == x) ? x :find(par[x]); }
    void unite(int x, int y) {
        x = find(x), y = find(y);
        if (cou[x].first + cou[x].second < cou[y].first + cou[y].second) swap(x, y);
        history.emplace(y, make_pair(par[y], cou[x]));
        if (x != y) par[y] = x, cou[x].first += cou[y].first, cou[x].second += cou[y].second;
    }
    void undo()
    {
        cou[par[history.top().first]] = history.top().second.second;
        par[history.top().first] = history.top().second.first;
        history.pop();
    }
    pint count(int x) { return cou[find(x)]; }
    bool same(int x, int y) { return find(x) == find(y); }
};

struct SegTree
{
    int N;
    int head;
    vector<vector<pint>> x;

    SegTree(int N) : N(N)
    {
        int N_tmp = 1; while (N_tmp < N) N_tmp <<= 1;
        x.resize(N_tmp*2), head = N_tmp - 1;
    }
    void add(int l, int r, pint xy, int now = 0, int L = 0, int R = -1) // [l, r]
    {
        if (R < 0) R = head;
        if (r < L or l > R) return;
        if (l <= L and r >= R) x[now].emplace_back(xy);
        else
        {
            add(l, r, xy, now * 2 + 1, L, (L + R - 1) / 2);
            add(l, r, xy, now * 2 + 2, (L + R + 1) / 2, R);
        }
    }
};

constexpr int XMAX = 300002;
UndoUnionFind uf(0);
SegTree st(1);
vector<lint> ret;

void dfs(int now, lint tmp, lint n_e)
{
    lint tmp_diff = 0;
    for (auto pa : st.x[now])
    {
        n_e++;
        if (!uf.same(pa.first, pa.second + XMAX))
        {
            pint pa1 = uf.count(pa.first);
            pint pa2 = uf.count(pa.second + XMAX);
            tmp_diff += (lint)(pa1.first + pa2.first) * (pa1.second + pa2.second) - (lint)pa1.first * pa1.second - (lint)pa2.first * pa2.second;
        }
        uf.unite(pa.first, pa.second + XMAX);
    }

    if (now >= st.head)
    {
        ret.push_back(tmp + tmp_diff);
    }
    else
    {
        dfs(now * 2 + 1, tmp + tmp_diff, n_e);
        dfs(now * 2 + 2, tmp + tmp_diff, n_e);
    }

    REP(_, st.x[now].size()) uf.undo();
}

int Q;

int main()
{
    cin >> Q;
    map<pint, int> ma;
    vector<pair<pint, pint>> query;
    REP(t, Q)
    {
        pint pa;
        cin >> pa.first >> pa.second;
        if (ma.count(pa))
        {
            query.emplace_back(make_pair(pa, pint(ma[pa], t)));
            ma.erase(pa);
        }
        else
        {
            ma[pa] = t;
        }
    }
    for (auto pa : ma) query.emplace_back(make_pair(pa.first, pint(pa.second, Q)));

    st = SegTree(Q + 1);
    for (auto q : query)
    {
        pint t = q.second;
        st.add(t.first, t.second - 1, q.first);
    }

    uf = UndoUnionFind(2 * XMAX);
    dfs(0, 0, 0);
    REP(i, Q) printf("%lld ", ret[i]);
    puts("");
}