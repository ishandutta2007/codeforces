#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)

//  Nvector<int>[0, N)INVALID
struct Doubling
{
    int N, LN, INVALID;
    vector<vector<int>> mat;
    Doubling() : N(0), LN(0) {}
    Doubling(const vector<int> vec_nxt, int INVALID=-1) : N(vec_nxt.size()), LN(1), INVALID(INVALID)
    {
        while (1 << LN < N) LN++;
        mat.assign(LN, vector<int>(N, INVALID));
        mat[0] = vec_nxt;
        REP(i, N) if (mat[0][i] < 0 or mat[0][i] >= N) mat[0][i] = INVALID;
        REP(d, LN - 1) REP(i, N) if (mat[d][i] != INVALID) mat[d + 1][i] = mat[d][mat[d][i]];
    }
    int kth_forward(int now, int l)
    {
        for (int p = 0; l and now != INVALID; p++, l >>= 1) if (l & 1) now = mat[p][now];
        return now;
    }
};


template <typename T>
struct RangeMinimumQuery
{
    int N;
    int head;
    vector<T> x;
    T defaultT;
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
    RangeMinimumQuery(const vector<T> &vals, T defaultT) : N(vals.size()), defaultT(defaultT)
    {
        int N_tmp = 1; while (N_tmp < N) N_tmp <<= 1;
        x.assign(N_tmp*2, defaultT), head = N_tmp - 1;
        copy(vals.begin(), vals.end(), x.begin() + head);
        IREP(i, head) x[i] = min(x[i * 2 + 1], x[i * 2 + 2]);
    }
    RangeMinimumQuery() : RangeMinimumQuery(0, T()) {}
    void build(const vector<T> &vals) { copy(vals.begin(), vals.end(), x.begin() + head); IREP(i, head) x[i] = min(x[i * 2 + 1], x[i * 2 + 2]); }
    void update(int pos, T val) { pos += head, x[pos] = val; while (pos) pos = (pos - 1) / 2, x[pos] = min(x[pos*2+1], x[pos*2+2]); }
    T get(int begin, int end) const { return _get(begin, end, 0, 0, (int)x.size() / 2); }
    friend ostream &operator<<(ostream &os, const RangeMinimumQuery<T> &s) { os << "["; REP(i, s.N) os << s.get(i, i + 1) << ","; os << "]"; return os; }
};


int main()
{
    int N, M, Q;
    cin >> N >> M >> Q;

    vector<int> P(N), A(M);
    REP(i, N) cin >> P[i];
    REP(i, M) cin >> A[i];

    vector<int> prv_val(N + 1);
    REP(i, N) prv_val[P[(i + 1) % P.size()]] = P[i];

    vector<int> nxt1(M, M);
    map<int, vector<int>> ma;
    REP(i, M)
    {
        int a = A[i], prva = prv_val[a];
        for (auto v : ma[prva]) nxt1[v] = i;
        ma.erase(prva);
        ma[a].push_back(i);
    }

    Doubling dbl(nxt1, M);
    vector<int> r(M);
    REP(i, M) r[i] = dbl.kth_forward(i, N - 1);

    RangeMinimumQuery<int> rmq(r, 1e9);
    string ans;
    REP(_, Q)
    {
        int l, r;
        cin >> l >> r;
        int q = rmq.get(l - 1, r);
        if (q < r) ans += "1";
        else ans += "0";
    }
    cout << ans << endl;
}