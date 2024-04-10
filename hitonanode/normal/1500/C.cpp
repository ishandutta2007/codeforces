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
template <typename T, size_t sz> ostream &operator<<(ostream &os, const array<T, sz> &arr) { os << '['; for (auto v : arr) os << v << ','; os << ']'; return os; }
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
const string COLOR_RESET = "\033[0m", BRIGHT_GREEN = "\033[1;32m", BRIGHT_RED = "\033[1;31m", BRIGHT_CYAN = "\033[1;36m", NORMAL_CROSSED = "\033[0;9;37m", RED_BACKGROUND = "\033[1;41m", NORMAL_FAINT = "\033[0;2m";
#define dbg(x) cerr << BRIGHT_CYAN << #x << COLOR_RESET << " = " << (x) << NORMAL_FAINT << " (L" << __LINE__ << ") " << __FILE__ << COLOR_RESET << endl
#else
#define dbg(x) (x)
#endif

template <typename T> T rd_integer() {
    T ret = 0;
    bool minus = false;

    char c = getchar();
    while (!isdigit(c)) minus |= (c == '-'), c = getchar();
    while (isdigit(c)) ret = (ret << 1) + (ret << 3) + (c ^ 48), c = getchar();

    return minus ? -ret : ret;
}
int rdi() { return rd_integer<int>(); }

void answer(const vector<int> &ret) {
    cout << ret.size() << '\n';
    for (auto x : ret) cout << x + 1 << ' ';
    cout << '\n';
    exit(0);
}

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<short>> A(H, vector<short>(W));
    vector<vector<short>> B(H, vector<short>(W));
    // REP(i, H) REP(j, W) A[i][j] = rdi();
    // REP(i, H) REP(j, W) B[i][j] = rdi();
    cin >> A >> B;

    if (A == B) answer({});
    
    set<short> waiting;
    REP(j, W) waiting.insert(j);

    vector<short> ready;

    vector<vector<short>> units;
    {
        vector<short> tmp(H);
        iota(ALL(tmp), 0);
        units.push_back(tmp);
    }
    REP(j, W) {
        bool ok = true;
        REP(i, H - 1) if (B[i][j] > B[i + 1][j]) {
            ok = false;
            break;
        }
        if (ok) ready.push_back(j), waiting.erase(j);
    }

    vector<int> done;
    vector<short> as;
    while (ready.size()) {
        int w = ready.back();
        ready.pop_back();
        done.push_back(w);

        vector<vector<short>> units_nxt;
        for (auto v : units) {
            as.clear();
            for (auto i : v) as.push_back(B[i][w]);
            as = sort_unique(as);
            vector<vector<short>> ump(as.size());
            for (auto i : v) ump[lower_bound(ALL(as), B[i][w]) - as.begin()].push_back(i);

            for (auto &vec : ump) {
                if (vec.size() > 1) units_nxt.push_back(vec);
            }
        }
        units = units_nxt;

        vector<short> ers;
        for (auto w : waiting) {
            bool req = false;
            bool ok = true;
            for (const auto &v : units) {
                REP(i, int(v.size()) - 1) {
                    if (B[v[i]][w] > B[v[i + 1]][w]) {
                        ok = false;
                        break;
                    }
                    if (B[v[i]][w] < B[v[i + 1]][w]) req = true;
                }
                if (!ok) break;
            }
            if (ok and req) ers.push_back(w);
        }
        for (auto w : ers) waiting.erase(w), ready.push_back(w);
    }

    reverse(done.begin(), done.end());

    vector<short> simulate(H);
    iota(ALL(simulate), 0);
    for (auto w : done) {
        vector<pint> a2i;
        a2i.reserve(H);
        for (auto i : simulate) {
            a2i.emplace_back(A[i][w], i);
        }
        stable_sort(a2i.begin(), a2i.end(), [&](pint l, pint r) { return l.first < r.first; });
        REP(i, H) simulate[i] = a2i[i].second;
    }
    vector<vector<short>> AA(H);
    REP(i, H) AA[i] = A[simulate[i]];
    if (AA == B) answer(done);
    puts("-1");
}