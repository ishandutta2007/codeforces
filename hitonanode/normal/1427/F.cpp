#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios { fast_ios(){ cin.tie(nullptr), ios::sync_with_stdio(false), cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template <typename T, typename V>
void ndarray(vector<T>& vec, const V& val, int len) { vec.assign(len, val); }
template <typename T, typename V, typename... Args> void ndarray(vector<T>& vec, const V& val, int len, Args... args) { vec.resize(len), for_each(begin(vec), end(vec), [&](T& v) { ndarray(v, val, args...); }); }
template <typename T> bool chmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template <typename T> bool chmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template <typename T1, typename T2> pair<T1, T2> operator+(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first + r.first, l.second + r.second); }
template <typename T1, typename T2> pair<T1, T2> operator-(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first - r.first, l.second - r.second); }
template <typename T> vector<T> srtunq(vector<T> vec) { sort(vec.begin(), vec.end()), vec.erase(unique(vec.begin(), vec.end()), vec.end()); return vec; }
template <typename T> istream &operator>>(istream &is, vector<T> &vec) { for (auto &v : vec) is >> v; return is; }
template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec) { os << '['; for (auto v : vec) os << v << ','; os << ']'; return os; }
#if __cplusplus >= 201703L
template <typename... T> istream &operator>>(istream &is, tuple<T...> &tpl) { std::apply([&is](auto &&... args) { ((is >> args), ...);}, tpl); return is; }
template <typename... T> ostream &operator<<(ostream &os, const tuple<T...> &tpl) { std::apply([&os](auto &&... args) { ((os << args << ','), ...);}, tpl); return os; }
#endif
template <typename T> ostream &operator<<(ostream &os, const deque<T> &vec) { os << "deq["; for (auto v : vec) os << v << ','; os << ']'; return os; }
template <typename T> ostream &operator<<(ostream &os, const set<T> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <typename T, typename TH> ostream &operator<<(ostream &os, const unordered_set<T, TH> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <typename T> ostream &operator<<(ostream &os, const multiset<T> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <typename T> ostream &operator<<(ostream &os, const unordered_multiset<T> &vec) { os << '{'; for (auto v : vec) os << v << ','; os << '}'; return os; }
template <typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa) { os << '(' << pa.first << ',' << pa.second << ')'; return os; }
template <typename TK, typename TV> ostream &operator<<(ostream &os, const map<TK, TV> &mp) { os << '{'; for (auto v : mp) os << v.first << "=>" << v.second << ','; os << '}'; return os; }
template <typename TK, typename TV, typename TH> ostream &operator<<(ostream &os, const unordered_map<TK, TV, TH> &mp) { os << '{'; for (auto v : mp) os << v.first << "=>" << v.second << ','; os << '}'; return os; }
#ifdef HITONANODE_LOCAL
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl
#else
#define dbg(x) {}
#endif


int main()
{
    int N;
    cin >> N;
    vector<int> Color(N * 6 + 1, 0);
    REP(_, N * 3)
    {
        int a;
        cin >> a;
        Color[a] = 1;
    }
    vector<pint> P;
    FOR(i, 1, N * 6 + 1) P.emplace_back(i, Color[i]);
    sort(ALL(P));

    vector<vector<int>> T10;
    while (P.size()) {
        vector<int> used(P.size());
        REP(j, P.size() - 2)
        {
            if (P[j].second == P[j + 1].second and P[j].second == P[j + 2].second)
            {
                T10.push_back({ P[j].first, P[j + 1].first, P[j + 2].first });
                REP(d, 3) used[j + d] = true;
                break;
                j += 2;
            }
        }
        vector<pint> Pnew;
        REP(i, used.size()) if (!used[i]) Pnew.emplace_back(P[i]);
        P = Pnew;
    }

    sort(ALL(T10), [](const vector<int>& l, const vector<int>& r) { return l.back() - l[0] < r.back() - r[0]; });

    vector<int> cs;
    for (auto v : T10) cs.emplace_back(Color[v[0]]);
    vector<set<int>> chi(cs.size());
    vector<int> par(cs.size(), -1);
    // vector<vector<int>> parents(cs.size()), par_diff(cs.size());

    REP(i, cs.size())
    {
        REP(j, cs.size()) if (cs[i] != cs[j])
        {
            if (T10[i][0] > T10[j][0] and T10[i][2] < T10[j][2]) {
                if (par[i] == -1) par[i] = j;
                else if (T10[par[i]][0] < T10[j][0]) par[i] = j;
                // chi[j].insert(i);
                // parents[i].emplace_back(j);
                // if (cs[i] != cs[j]) par_diff[i].emplace_back(j);
            }
        }
        if (par[i] >= 0) chi[par[i]].insert(i);
    }

    dbg(T10);
    dbg(cs);
    dbg(par);
    dbg(chi);

    vector<int> removed(cs.size());

    vector<vector<int>> ret;
    while (ret.size() < N * 2)
    {
        IREP(d, 2)
        {
            int u = -1;
            REP(i, removed.size()) if (!removed[i] and cs[i] == d and chi[i].empty())
            {
                if (par[i] >= 0) {
                    u = i;
                    break;
                }
                else if (u < 0) u = i;
            }
            removed[u] = 1;
            ret.emplace_back(T10[u]);
            int p = par[u];
            if (p >= 0) {
                chi[p].erase(u);
            }
        }
    }
    dbg(chi);
    // dbg(parents);
    for (auto vec : ret) {
        cout << vec[0] << ' ' << vec[1] << ' ' << vec[2] << '\n';
    }
}