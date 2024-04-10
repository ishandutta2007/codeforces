#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(nullptr), ios::sync_with_stdio(false), cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template <typename T> bool chmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template <typename T> bool chmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template <typename T> vector<T> sort_unique(vector<T> vec) { sort(vec.begin(), vec.end()), vec.erase(unique(vec.begin(), vec.end()), vec.end()); return vec; }
template <typename T> istream &operator>>(istream &is, vector<T> &vec) { for (auto &v : vec) is >> v; return is; }
template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec) { os << '['; for (auto v : vec) os << v << ','; os << ']'; return os; }
#ifdef HITONANODE_LOCAL
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl
#else
#define dbg(x) {}
#endif

// Disjoint sparse table
// <https://discuss.codechef.com/t/tutorial-disjoint-sparse-table/17404>
// <https://drken1215.hatenablog.com/entry/2018/09/08/162600>
// Complexity: O(NlogN) for precalculation, O(1) per query
// - get(l, r): return op(x_l, ..., x_{r - 1})
template <typename T, typename F> struct DisjointSparseTable {
    int N, sz;
    F f;
    std::vector<std::vector<T>> data;
    static int _msb(int x) noexcept { return x == 0 ? 0 : (__builtin_clz(x) ^ 31); }
    DisjointSparseTable() = default;
    DisjointSparseTable(const std::vector<T> &seq, F op) : N(seq.size()), f(op) {
        sz = 1 << (_msb(N - 1) + 1);
        data.assign(_msb(sz) + 1, std::vector<T>(sz));
        std::copy(seq.begin(), seq.end(), data[0].begin());

        for (int h = 1, half = 2; half < N; h++, half <<= 1) {
            for (int i = half; i < sz; i += half * 2) {
                data[h][i - 1] = data[0][i - 1];
                for (int j = i - 2; j >= i - half; j--) { data[h][j] = f(data[0][j], data[h][j + 1]); }
                data[h][i] = data[0][i];
                for (int j = i + 1; j < i + half; j++) { data[h][j] = f(data[h][j - 1], data[0][j]); }
            }
        }
    }
    // [l, r), 0-indexed
    T get(int l, int r) {
        if (l == r) return -1;
        if (l + 1 == r) return data[0][l];
        int h = _msb(l ^ (r - 1));
        return f(data[h][l], data[h][r - 1]);
    }
};

void yes(int x, int y, int z) { cout << "YES\n" << x << ' ' << y << ' ' << z << '\n'; }

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    cin >> A;

    const vector<int> d = sort_unique(A);
    for (auto &a : A) a = lower_bound(d.begin(), d.end(), a) - d.begin();

    vector<vector<int>> a2is(d.size());
    REP(i, N) a2is[A[i]].emplace_back(i);

    DisjointSparseTable stmin(A, [&](int i, int j) { return min(i, j); });
    DisjointSparseTable stmax(A, [&](int i, int j) { return max(i, j); });

    int l = N, r = -1;

    IREP(a, a2is.size()) {
        const auto &vec = a2is[a];
        if (r == -1) {
            if (vec.size() >= 3) {
                int x = vec[1], y = 1, z = N - x - y;
                yes(x, y, z);
                return;
            }
        } else if (l >= 0 and stmin.get(l, r) == a and stmax.get(0, l) == a and stmax.get(r, N) == a) {
            int x = l, z = N - r, y = N - x - z;
            yes(x, y, z);
            return;
        } else if (l > 0 and stmin.get(l - 1, r) == a and stmax.get(0, l - 1) == a and stmax.get(r, N) == a) {
            int x = l - 1, z = N - r, y = N - x - z;
            yes(x, y, z);
            return;
        } else if (l >= 0 and r < N and stmin.get(l, r + 1) == a and stmax.get(0, l) == a and stmax.get(r + 1, N) == a) {
            int x = l, z = N - r - 1, y = N - x - z;
            yes(x, y, z);
            return;
        }
        for (auto i : vec) chmin(l, i), chmax(r, i + 1);
    }
    cout << "NO\n";
}

int main()
{
    int T;
    cin >> T;
    while (T--) solve();
}