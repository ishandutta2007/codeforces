#include <bits/stdc++.h>
using namespace std;
using pint = pair<int, int>;
struct fast_ios { fast_ios(){ cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template <typename T> istream &operator>>(istream &is, vector<T> &vec) { for (auto &v : vec) is >> v; return is; }
template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec) { os << '['; for (auto v : vec) os << v << ','; os << ']'; return os; }
template <typename T> ostream &operator<<(ostream &os, const set<T> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa) { os << '(' << pa.first << ',' << pa.second << ')'; return os; }
#ifdef HITONANODE_LOCAL
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl
#else
#define dbg(x)
#endif

// UnionFind Tree (0-indexed), based on size of each disjoint set
struct UnionFind
{
    std::vector<int> par;
    vector<list<int>> cou;
    UnionFind(int N = 0) : par(N), cou(N) {
        iota(par.begin(), par.end(), 0);
        REP(i, N) cou[i].emplace_back(i);
    }
    int find(int x) { return (par[x] == x) ? x : (par[x] = find(par[x])); }
    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        if (cou[x].size() < cou[y].size()) std::swap(x, y);
        par[y] = x, cou[x].splice(cou[x].end(), std::move(cou[y]));
        return true;
    }
    int count(int x) { return cou[find(x)].size(); }
    bool same(int x, int y) { return find(x) == find(y); }
};
vector<pint> edges;

int main()
{
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<int> P(N);
    cin >> P;
    REP(t, M)
    {
        int a, b;
        cin >> a >> b;
        edges.emplace_back(a - 1, b - 1);
    }
    vector<int> edge_alive(M, 1);
    vector<pint> queries(Q);
    REP(q, Q)
    {
        cin >> queries[q].first >> queries[q].second;
        queries[q].second--;
        if (queries[q].first == 2)
        {
            edge_alive[queries[q].second] = 0;
        }
    }

    UnionFind uf(N);
    REP(i, edge_alive.size()) if (edge_alive[i])
    {
        uf.unite(edges[i].first, edges[i].second);
    }
    vector<vector<int>> merge_vs(Q);
    vector<int> oldi(Q, -1), oldra(Q, -1), oldrb(Q, -1);
    IREP(q, Q)
    {
        if (queries[q].first == 2)
        {
            int e = queries[q].second;
            auto [a, b] = edges[e];
            if (!uf.same(a, b))
            {
                if (uf.count(a) > uf.count(b)) swap(a, b);
                for (auto v : uf.cou[uf.find(a)])
                {
                    merge_vs[q].emplace_back(v);
                }
                oldra[q] = uf.find(a), oldrb[q] = uf.find(b);
                uf.unite(b, a);
            }
        }
        else
        {
            oldi[q] = uf.find(queries[q].second);
        }
    }
    dbg(merge_vs);
    dbg(oldra);
    dbg(oldrb);
    vector<set<pint>> rvi(N);
    REP(i, N) rvi[uf.find(i)].emplace(P[i], i);
    REP(q, Q)
    {
        dbg(rvi);
        if (queries[q].first == 1)
        {
            int r = oldi[q];
            assert(r >= 0);
            if (rvi[r].empty())
            {
                cout << '0' << '\n';
            }
            else
            {
                pint p = *prev(rvi[r].end());
                rvi[r].erase(p);
                auto [v, i] = p;
                P[i] = 0;
                cout << v << '\n';
            }
        }
        else
        {
            const int rb = oldrb[q], ra = oldra[q];
            if (rb < 0) continue;
            for (auto i : merge_vs[q]) if (P[i])
            {
                rvi[rb].erase(pint(P[i], i));
                rvi[ra].emplace(P[i], i);
            }
        }
    }
}