#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using pint = pair<int, int>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> bool chmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool chmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa){ os << "(" << pa.first << "," << pa.second << ")"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;


// StarrySkyTree: segment tree for Range Minimum Query & Range Add Query
// Complexity: O(N) (construction), O(lg N) (add / get)
template <typename _Tp>
struct RangeAddRangeMin
{
    int N, head;
    _Tp defaultMin;
    std::vector<_Tp> range_min, range_add;
    static inline _Tp f(_Tp x, _Tp y) noexcept
    {
        return std::min(x, y);
    }

    inline void _merge(int pos)
    {
        range_min[pos] = f(range_min[pos * 2] + range_add[pos * 2], range_min[pos * 2 + 1] + range_add[pos * 2 + 1]);
    }
    void initialize(const std::vector<_Tp> &data_init, _Tp default_min)
    {
        N = data_init.size(), head = 1;
        while (head < N) head <<= 1;
        defaultMin = default_min;
        range_min.assign(head * 2, defaultMin);
        range_add.assign(head * 2, 0);
        std::copy(data_init.begin(), data_init.end(), range_min.begin() + head);
        for (int pos = head; --pos;) _merge(pos);
    }
    RangeAddRangeMin() = default;
    RangeAddRangeMin(const std::vector<_Tp> &data_init, _Tp default_min)
    {
        initialize(data_init, default_min);
    }
    void _add(int begin, int end, int pos, int l, int r, _Tp vadd) noexcept
    {
        if (r <= begin or end <= l) return;
        if (begin <= l and r <= end)
        {
            range_add[pos] += vadd;
            return;
        }
        _add(begin, end, pos * 2, l, (l + r) / 2, vadd);
        _add(begin, end, pos * 2 + 1, (l + r) / 2, r, vadd);
        _merge(pos);
    }
    // Add `vadd` to (x_begin, ..., x_{end - 1})
    void add(int begin, int end, _Tp vadd) noexcept
    {
        return _add(begin, end, 1, 0, head, vadd);
    }
    _Tp _get(int begin, int end, int pos, int l, int r) const noexcept
    {
        if (r <= begin or end <= l) return defaultMin;
        if (begin <= l and r <= end) return range_min[pos] + range_add[pos];
        return f(_get(begin, end, pos * 2, l, (l + r) / 2), _get(begin, end, pos * 2 + 1, (l + r) / 2, r)) + range_add[pos];
    }
    // Return f(x_begin, ..., x_{end - 1})
    _Tp get(int begin, int end) const noexcept
    {
        return _get(begin, end, 1, 0, head);
    }
};


int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    cin >> A;
    vector<pint> a2i;
    REP(i, N) a2i.emplace_back(A[i], i);
    sort(ALL(a2i));
    vector<int> vinit(N);
    REP(i, N) vinit[i] = N - i;
    RangeAddRangeMin<int> segtree(vinit, 1e9);
    vector<int> coeff(N, 1);
    int n_plus = N, n_minus = 0;
    for (auto p : a2i)
    {
        if (n_plus == n_minus) break;
        n_plus--;
        int i = p.second;
        segtree.add(0, i + 1, -2);
        if (segtree.get(0, N) < 0)
        {
            segtree.add(0, i + 1, 1);
            coeff[i] = 0;
            if (segtree.get(0, N) < 0)
            {
                segtree.add(0, i + 1, 1);
                coeff[i] = 1;
                n_plus++;
            }
        }
        else
        {
            coeff[i] = -1;
            n_minus++;
        }
    }
    lint ret = 0;
    REP(i, N) ret += A[i] * coeff[i];
    cout << ret << '\n';
}