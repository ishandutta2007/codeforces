#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> bool mmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool mmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;

template <typename VAL, typename DVAL>
struct LazySegTree
{
    int N;
    int head;

    vector<VAL> val;
    vector<DVAL> dval;
    VAL I_val;
    DVAL I_dval;

    using vv2v = function<VAL(const VAL&, const VAL&)>;
    using d2d = function<void(DVAL&, const DVAL&)>;
    using d2v = function<void(VAL&, const DVAL&)>;
    vv2v merge_val;
    d2d add_dval;
    d2v refl_dval;

    LazySegTree(vector<VAL> &val_init, VAL val_default, DVAL dval_default,
                vv2v f, d2d dadd, d2v dreflect)
            : N(val_init.size()), I_val(val_default), I_dval(dval_default),
              merge_val(f),
              add_dval(dadd),
              refl_dval(dreflect)
    {
        int N_tmp = 1;
        while (N_tmp < N) N_tmp <<= 1;
        val = vector<VAL>(N_tmp*2, I_val);
        dval = vector<DVAL>(N_tmp*2, I_dval);
        head = N_tmp - 1;
        for (int i=0; i<N; i++) val[head+i] = val_init[i];
        for (int pos=head-1; pos>=0; pos--) val[pos] = merge_val(val[pos*2+1], val[pos*2+2]);
    }

    void resolve_dval(int pos, int l, int r) { // pos
        refl_dval(val[pos], dval[pos]);
        if (pos < head)
        {
            add_dval(dval[pos*2+1], dval[pos]);
            add_dval(dval[pos*2+2], dval[pos]);
        }
        dval[pos] = I_dval;
    }

    void update(int begin, int end, DVAL dval_q) { update(begin, end, dval_q, 0, 0, head+1); }
    void update(int begin, int end, DVAL dval_q, int pos, int l, int r)
    {
        // 
        if (begin <= l && r <= end) { // 
            add_dval(dval[pos], dval_q);
            resolve_dval(pos, l, r);
        }
        else if (begin < r && l < end) { // 
            resolve_dval(pos, l, r);
            update(begin, end, dval_q, pos*2+1, l, (l+r)/2);
            update(begin, end, dval_q, pos*2+2, (l+r)/2, r);
            val[pos] = merge_val(val[pos*2+1], val[pos*2+2]);
        }
        else resolve_dval(pos, l, r);
    }

    VAL getvalue(int begin, int end) { return getvalue(begin, end, 0, 0, head+1); }
    VAL getvalue(int begin, int end, int pos, int l, int r)
    {
        resolve_dval(pos, l, r);
        if (begin <= l && r <= end) return val[pos];
        else if (begin<r && l<end) {
            VAL vl = getvalue(begin, end, pos*2+1, l, (l+r)/2);
            VAL vr = getvalue(begin, end, pos*2+2, (l+r)/2, r);
            val[pos] = merge_val(val[pos*2+1], val[pos*2+2]);
            return merge_val(vl, vr);
        }
        else return I_val;
    }
};

int main()
{
    int N;
    cin >> N;
    vector<int> P(N), A(N);
    cin >> P >> A;
    vector<lint> vec(N + 1);
    REP(i, N) vec[P[i]] += A[i];
    REP(i, N) vec[i + 1] += vec[i];
    LazySegTree<lint, lint> rmq(vec, 1e18, 0,
                                [](lint a, lint b) { return min(a, b); }, // merge
                                [](lint &a, lint b) { a += b; },          // 
                                [](lint &a, lint b) { a += b; });         // 
    lint ret = 1e18;
    REP(i, N - 1)
    {
        int p = P[i];
        rmq.update(0, p, A[i]);
        rmq.update(p, N + 1, -A[i]);
        mmin(ret, rmq.getvalue(0, N + 1));
    }
    cout << ret << endl;
}