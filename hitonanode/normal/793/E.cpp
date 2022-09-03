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
int floor_lg(long long x) { return x <= 0 ? -1 : 63 - __builtin_clzll(x); }
template <typename T1, typename T2> pair<T1, T2> operator+(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first + r.first, l.second + r.second); }
template <typename T1, typename T2> pair<T1, T2> operator-(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first - r.first, l.second - r.second); }
template <typename T> vector<T> sort_unique(vector<T> vec) { sort(vec.begin(), vec.end()), vec.erase(unique(vec.begin(), vec.end()), vec.end()); return vec; }
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
constexpr int BS = 20;
#else
#define dbg(x) {}
constexpr int BS = 5010;
#endif



int main()
{
    int N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;
    A--, B--, C--, D--;

    vector<int> P(N);
    cin >> P;
    for (auto& x : P) x--;
    vector<vector<int>> chi(N);
    vector<int> par(N, -1);
    FOR(i, 1, N)
    {
        par[i] = P[i - 1];
        chi[P[i - 1]].emplace_back(i);
    }

    vector<int> stsz(N);
    auto dfs = [&](auto self, int now) -> void {
        for (auto nxt : chi[now])
        {
            self(self, nxt);
            stsz[now] += stsz[nxt];
        }
        if (chi[now].empty())
        {
            stsz[now] = 1;
        }
    };
    dfs(dfs, 0);
    dbg(stsz);
    vector<vector<int>> vs(5);
    vector<int> visited(N);
    auto up = [&](int l, int save) {
        int prv = -1;
        while (l) {
            visited[l] = 1;
            for (auto c : chi[l]) {
                if (c != prv) vs[save].emplace_back(stsz[c]);
            }
            prv = l;
            l = par[l];
        }
    };

    up(A, 0);
    up(B, 1);
    up(C, 2);
    up(D, 3);
    for (auto nxt : chi[0]) if (!visited[nxt] and stsz[nxt]) vs[4].emplace_back(stsz[nxt]);
    dbg(chi);
    dbg(vs);
    const int L = stsz[0];
    dbg(L);
    if (L % 2) {
        puts("NO");
        return 0;
    }

    auto can_make = [&](vector<int> is, int tgt) -> bool {
        if (tgt < 0) return false;
        bitset<BS> bs;
        bs.set(2);
        for (auto i : is)
            for (auto v : vs[i]) { bs = bs | (bs << v); }
        return bs[tgt];
    };

    if (can_make({0, 1, 4}, L / 2 - accumulate(ALL(vs[2]), 0))
        and can_make({2, 3, 4}, L / 2 - accumulate(ALL(vs[1]), 0))) {
        puts("YES");
    } else
        puts("NO");
}