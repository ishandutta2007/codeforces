#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)

struct LazySegTree
{
    using T_NODE = lint;
    using T_DELAY = lint;
    using T_RETVAL = lint;
    T_NODE zero_node = 0;
    T_DELAY zero_delay = 0;
    T_RETVAL zero_retval = -1e9;

    int N;
    int head;
    vector<T_NODE> vvalue;
    vector<T_DELAY> vdelay;

    void merge_node(int pos)
    {
        // Here, you have to calculate vvalue[pos] from children (vvalue[l], vvalue[r]),
        // Assumptions: `vdelay[pos] = vdelay[l] = vdelay[r] = zero_delay`
        int l = pos * 2 + 1, r = pos * 2 + 2;
        vvalue[pos] = max(vvalue[l], vvalue[r]);
    }

    void reflect_delay(int pos)
    {
        // Here, you must update vvalue[pos] by reflecting vdelay[pos], without inconsistency
        if (pos < head)
        {
            pushdown_dval(pos * 2 + 1, vdelay[pos]);
            pushdown_dval(pos * 2 + 2, vdelay[pos]);
        }
        vvalue[pos] += vdelay[pos];
        vdelay[pos] = zero_delay;
    }

    void pushdown_dval(int pos, const T_DELAY &d)
    {
        // operate d to vdelay[pos] (merge two T_DELAY's)
        vdelay[pos] += d;
    }

    T_RETVAL calc_retval(int pos)
    {
        // Assumption: `vdelay[pos] = zero_delay`
        return vvalue[pos];
    }
    T_RETVAL merge_retval(const T_RETVAL &l, const T_RETVAL &r)
    {
        return max(l, r);
    }

    ////// general description //////
    LazySegTree(const vector<T_NODE> &val_init) : N(val_init.size())
    {
        int N_tmp = 1;
        while (N_tmp < N) N_tmp <<= 1;
        vvalue.assign(N_tmp * 2, zero_node);
        vdelay.assign(N_tmp * 2, zero_delay);
        head = N_tmp - 1;
        copy(val_init.begin(), val_init.end(), vvalue.begin() + head);
        for (int pos = head - 1; pos >= 0; pos--)
        {
            merge_node(pos);
        }
    }

    void update(int begin, int end, T_DELAY delay, int pos=0, int l=0, int r=-1)
    {
        // Operate `delay` to the node pos
        // After this, vdelay[pos] MUST be zero to work merge_node() correctly
        if (r < 0) r = head + 1;
        if (begin <= l and r <= end) { // Update whole [l, r) by delay
            pushdown_dval(pos, delay);
            reflect_delay(pos);
        }
        else if (begin < r and l < end) { // Update somewhere in [l, r)
            reflect_delay(pos);
            update(begin, end, delay, pos * 2 + 1, l, (l + r) / 2);
            update(begin, end, delay, pos * 2 + 2, (l + r) / 2, r);
            merge_node(pos);
        }
        else reflect_delay(pos);
    }

    T_RETVAL getvalue(int begin, int end, int pos=0, int l=0, int r=-1) // Get value in [begin, end)
    {
        if (r < 0) r = head + 1;
        reflect_delay(pos);
        if (begin <= l and r <= end) return calc_retval(pos);
        else if (begin < r and l < end) {
            T_RETVAL vl = getvalue(begin, end, pos * 2 + 1, l, (l + r) / 2);
            T_RETVAL vr = getvalue(begin, end, pos * 2 + 2, (l + r) / 2, r);
            return merge_retval(vl, vr);
        }
        else return zero_retval;
    }
};


int main()
{
    int N, M, K;
    cin >> N >> M >> K;
    vector<vector<lint>> A(N + 1, vector<lint>(M));
    REP(i, N) REP(j, M) cin >> A[i][j];
    vector<vector<lint>> AA(N + 1, vector<lint>(M + 1));
    REP(i, N) REP(j, M) AA[i][j + 1] = AA[i][j] + A[i][j];
    vector<lint> init(M - K + 1);
    REP(i, M - K + 1) init[i] = AA[0][i + K] + AA[1][i + K] - AA[0][i] - AA[1][i];
    LazySegTree dp(init);
    FOR(t, 1, N) {
        vector<lint> dpnxt(M - K + 1);
        FOR(l, -K + 1,  M - K + 1) {
            int r = l + K;
            dp.update(max(0, l), r, -A[t][r - 1]);
            if (l - 1 >= 0) dp.update(max(0, l - K), l, A[t][l - 1]);
            if (l >= 0) dpnxt[l] = dp.getvalue(0, M - K + 1) + AA[t + 1][l + K] + AA[t][l + K] - AA[t + 1][l] - AA[t][l];
        }
        dp = LazySegTree(dpnxt);
    }
    cout << dp.getvalue(0, M - K + 1) << endl;
}