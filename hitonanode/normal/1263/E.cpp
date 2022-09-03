#include <bits/stdc++.h>
using namespace std;
using pint = pair<int, int>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> bool mmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool mmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }

struct LazySegTree
{
    using T_NODE = pint;
    using T_DELAY = int;
    using T_RETVAL = pint;
    T_NODE zero_node = pint(0, 0);
    T_DELAY zero_delay = 0;
    T_RETVAL zero_retval = pint(0, 0);

    int N;
    int head;
    vector<T_NODE> vvalue;
    vector<T_DELAY> vdelay;

    void merge_node(int pos)
    {
        // Here, you have to calculate vvalue[pos] from children (vvalue[l], vvalue[r]),
        // Assumptions: `vdelay[pos] = vdelay[l] = vdelay[r] = zero_delay`
        int l = pos * 2 + 1, r = pos * 2 + 2;
        vvalue[pos] = vvalue[l];
        mmax(vvalue[pos].first, vvalue[r].first);
        mmin(vvalue[pos].second, vvalue[r].second);
    }

    void reflect_delay(int pos)
    {
        // Here, you must update vvalue[pos] by reflecting vdelay[pos], without inconsistency
        if (vdelay[pos] == zero_delay) return;
        if (pos < head)
        {
            pushdown_dval(pos * 2 + 1, vdelay[pos]);
            pushdown_dval(pos * 2 + 2, vdelay[pos]);
        }
        vvalue[pos].first += vdelay[pos];
        vvalue[pos].second += vdelay[pos];
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
        return make_pair(max(l.first, r.first), l.second + r.second);
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
    int N;
    cin >> N;
    string S;
    cin >> S;
    int p = 0;
    LazySegTree st(vector<pint>(1 << 20));
    vector<char> history(N, 'a');
    for (auto c : S)
    {
        if (c == 'L') p--;
        else if (c == 'R') p++;
        else
        {
            if (history[p] == '(') st.update(p, 1 << 20, -1);
            if (history[p] == ')') st.update(p, 1 << 20, 1);
            history[p] = c;
            if (c == '(') st.update(p, 1 << 20, 1);
            if (c == ')') st.update(p, 1 << 20, -1);
        }
        mmax(p, 0);
        pint maxmin = st.getvalue(0, N);
        pint valid = st.getvalue(N + 1, N + 2);
        if (valid.first == 0 and valid.second == 0 and maxmin.second >= 0)
        {
            printf("%d ", maxmin.first);
        }
        else printf("-1 ");
    }
}