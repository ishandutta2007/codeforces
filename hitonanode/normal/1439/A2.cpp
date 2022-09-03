#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios {
    fast_ios() { cin.tie(nullptr), ios::sync_with_stdio(false), cout << fixed << setprecision(20); };
} fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for (int i = (begin), i##_end_ = (end); i < i##_end_; i++)
#define IFOR(i, begin, end) for (int i = (end)-1, i##_begin_ = (begin); i >= i##_begin_; i--)
#define REP(i, n) FOR(i, 0, n)
#define IREP(i, n) IFOR(i, 0, n)
template <typename T, typename V> void ndarray(vector<T> &vec, const V &val, int len) { vec.assign(len, val); }
template <typename T, typename V, typename... Args> void ndarray(vector<T> &vec, const V &val, int len, Args... args) {
    vec.resize(len), for_each(begin(vec), end(vec), [&](T &v) { ndarray(v, val, args...); });
}
template <typename T> bool chmax(T &m, const T q) { return m < q ? (m = q, true) : false; }
template <typename T> bool chmin(T &m, const T q) { return m > q ? (m = q, true) : false; }
template <typename T1, typename T2> pair<T1, T2> operator+(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first + r.first, l.second + r.second); }
template <typename T1, typename T2> pair<T1, T2> operator-(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first - r.first, l.second - r.second); }
template <typename T> vector<T> srtunq(vector<T> vec) { return sort(vec.begin(), vec.end()), vec.erase(unique(vec.begin(), vec.end()), vec.end()), vec; }
template <typename T> istream &operator>>(istream &is, vector<T> &vec) {
    for (auto &v : vec) is >> v;
    return is;
}
template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec) {
    return os << '[', for_each(vec.begin(), vec.end(), [&](const T &x) { os << x << ','; }), os << ']', os;
}
#if __cplusplus >= 201703L
template <typename... T> istream &operator>>(istream &is, tuple<T...> &tpl) {
    return std::apply([&is](auto &&... args) { ((is >> args), ...); }, tpl), is;
}
template <typename... T> ostream &operator<<(ostream &os, const tuple<T...> &tpl) {
    return std::apply([&os](auto &&... args) { ((os << args << ','), ...); }, tpl), os;
}
#endif
template <typename T> ostream &operator<<(ostream &os, const deque<T> &vec) {
    return os << '[', for_each(vec.begin(), vec.end(), [&](const T &x) { os << x << ','; }), os << ']', os;
}
template <typename T> ostream &operator<<(ostream &os, const set<T> &vec) {
    return os << '{', for_each(vec.begin(), vec.end(), [&](const T &x) { os << x << ','; }), os << '}', os;
}
template <typename T, typename TH> ostream &operator<<(ostream &os, const unordered_set<T, TH> &vec) {
    return os << '{', for_each(vec.begin(), vec.end(), [&](const T &x) { os << x << ','; }), os << '}', os;
}
template <typename T> ostream &operator<<(ostream &os, const multiset<T> &vec) {
    return os << '{', for_each(vec.begin(), vec.end(), [&](const T &x) { os << x << ','; }), os << '}', os;
}
template <typename T> ostream &operator<<(ostream &os, const unordered_multiset<T> &vec) {
    return os << '{', for_each(vec.begin(), vec.end(), [&](const T &x) { os << x << ','; }), os << '}', os;
}
template <typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa) { return os << '(' << pa.first << ',' << pa.second << ')', os; }
template <typename TK, typename TV> ostream &operator<<(ostream &os, const map<TK, TV> &mp) {
    return os << '{', for_each(mp.begin(), mp.end(), [&](const pair<TK, TV> &v) { os << v.first << "=>" << v.second << ','; }), os << '}', os;
}
template <typename TK, typename TV, typename TH> ostream &operator<<(ostream &os, const unordered_map<TK, TV, TH> &mp) {
    return os << '{', for_each(mp.begin(), mp.end(), [&](const pair<TK, TV> &v) { os << v.first << "=>" << v.second << ','; }), os << '}', os;
}
#ifdef HITONANODE_LOCAL
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl
#else
#define dbg(x) 0
#endif

void solve() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> A(N, vector<int>(M));
    {
        vector<string> S(N);
        cin >> S;
        REP(i, N) REP(j, M) { A[i][j] = (S[i][j] == '1'); }
    }
    vector<pint> ret;

    auto tgl = [&](int i, int j) {
        A[i][j] ^= 1;
        ret.emplace_back(i, j);
    };
    REP(i, N - 2) REP(j, M) {
        if (A[i][j]) {
            tgl(i, j);
            tgl(i + 1, j);
            if (j + 1 < M)
                tgl(i, j + 1);
            else
                tgl(i + 1, j - 1);
        }
    }
    REP(j, M - 2) {
        int cntt = 0;
        if (A[N - 2][j]) {
            tgl(N - 2, j);
            cntt++;
        }
        if (A[N - 1][j]) {
            tgl(N - 1, j);
            cntt++;
        }
        if (cntt) {
            tgl(N - 2, j + 1);
            cntt++;
            if (cntt < 3) tgl(N - 1, j + 1);
        }
    }
    while (true) {
        int cnt = 0;
        FOR(i, N - 2, N) FOR(j, M - 2, M) { cnt += A[i][j]; }
        if (!cnt) break;
        if (cnt == 4) {
            int u = 3;
            FOR(i, N - 2, N) FOR(j, M - 2, M) {
                if (u) u--, tgl(i, j);
            }
        } else if (cnt == 3) {
            FOR(i, N - 2, N) FOR(j, M - 2, M) if (A[i][j]) { tgl(i, j); }
        } else if (cnt == 2) {
            int u = 1;
            FOR(i, N - 2, N) FOR(j, M - 2, M) {
                if (!A[i][j])
                    tgl(i, j);
                else if (u) {
                    tgl(i, j), u--;
                }
            }
        } else if (cnt == 1) {
            int u = 2;
            FOR(i, N - 2, N) FOR(j, M - 2, M) {
                if (A[i][j]) {
                    tgl(i, j);
                } else if (u) {
                    tgl(i, j), u--;
                }
            }
        }
    }
    dbg(A);
    cout << ret.size() / 3 << '\n';
    for (auto p : ret) { cout << p.first + 1 << ' ' << p.second + 1 << ' '; }
    cout << '\n';
}

int main() {
    int T;
    cin >> T;

    while (T--) { solve(); }
}