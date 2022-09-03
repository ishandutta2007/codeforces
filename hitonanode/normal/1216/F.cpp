#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> void ndarray(vector<T> &vec, int len) { vec.resize(len); }
template<typename T, typename... Args> void ndarray(vector<T> &vec, int len, Args... args) { vec.resize(len); for (auto &v : vec) ndarray(v, args...); }
template<typename T> bool mmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool mmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
///// This part below is only for debug, not used /////


constexpr lint INF = 1e15;

using T = lint;
struct RangeMinimumQuery
{
    int N;
    T defaultT = 1e9;
    int head;
    vector<T> x;
    T _get(int begin, int end, int pos, int l, int r) const
    {
        if (r <= begin or l >= end) return defaultT;
        if (l >= begin and r <= end) return x[pos];
        return min(_get(begin, end, 2 * pos + 1, l, (l + r) / 2), _get(begin, end, 2 * pos + 2, (l + r) / 2, r));
    }
    RangeMinimumQuery(int N, T defaultT) : N(N), defaultT(defaultT)
    {
        int N_tmp = 1; while (N_tmp < N) N_tmp <<= 1;
        x.assign(N_tmp*2, defaultT), head = N_tmp - 1;
    }
    void build(const vector<T> &vals)
    {
        copy(vals.begin(), vals.end(), x.begin() + head);
        for (int i = head - 1; i >= 0; i--)
        {
            x[i] = min(x[i * 2 + 1], x[i * 2 + 2]);
        }
    }
    RangeMinimumQuery(const vector<T> &vals, T defaultT) : N(vals.size()), defaultT(defaultT)
    {
        int N_tmp = 1; while (N_tmp < N) N_tmp <<= 1;
        x.assign(N_tmp*2, defaultT), head = N_tmp - 1;
        build(vals);
    }
    RangeMinimumQuery() : RangeMinimumQuery(0, T()) {}
    void update(int pos, T val)
    {
        pos += head, x[pos] = val;
        while (pos) pos = (pos - 1) / 2, x[pos] = min(x[pos * 2 + 1], x[pos * 2 + 2]);
    }
    T get(int begin, int end) const { return _get(begin, end, 0, 0, (int)x.size() / 2); }
    friend ostream &operator<<(ostream &os, const RangeMinimumQuery &s)
    {
        os << "[";
        for (int i = 0; i < s.N; i++) os << s.get(i, i + 1) << ",";
        os << "]";
        return os;
    }
};

int main()
{
    lint N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    RangeMinimumQuery rmq(N + K + 1, INF);
    rmq.update(0, 0);
    REP(i, N)
    {
        lint cost_add = i + 1;
        lint tp = rmq.get(i, i + 1), tn = rmq.get(i + 1, i + 2);
        if (mmin(tn, tp + cost_add)) rmq.update(i + 1, tn);
        if (S[i] == '1')
        {
            lint mini = rmq.get(max((i + 1) - K - 1, 0LL), i + 1 + K + 1);
            rmq.update(i + 1 + K, mini + cost_add);
        }
    }
    cout << rmq.get(N, N + K + 1) << endl;
}