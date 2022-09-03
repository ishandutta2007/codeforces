#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((lint)(x).size())
#define POW2(n) (1LL << (n))
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
///// This part below is only for debug, not used /////
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const deque<T> &vec){ os << "deq["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const unordered_set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const multiset<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T> ostream &operator<<(ostream &os, const unordered_multiset<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa){ os << "(" << pa.first << "," << pa.second << ")"; return os; }
template<typename TK, typename TV> ostream &operator<<(ostream &os, const map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }
template<typename TK, typename TV> ostream &operator<<(ostream &os, const unordered_map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }
template<typename T> void ndarray(vector<T> &vec, int len) { vec.resize(len); }
template<typename T, typename... Args> void ndarray(vector<T> &vec, int len, Args... args) { vec.resize(len); for (auto &v : vec) ndarray(v, args...); }
template<typename T> bool mmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool mmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template<typename T1, typename T2> pair<T1, T2> operator+(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first + r.first, l.second + r.second); }
template<typename T1, typename T2> pair<T1, T2> operator-(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first - r.first, l.second - r.second); }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;
///// END /////

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
            : N(val_init.size()), I_val(val_default), I_dval(dval_default)
    {
        int N_tmp = 1;
        while (N_tmp < N) N_tmp <<= 1;
        val = vector<VAL>(N_tmp*2, I_val);
        dval = vector<DVAL>(N_tmp*2, I_dval);
        head = N_tmp - 1;
        for (int i=0; i<N; i++) val[head+i] = val_init[i];
        for (int pos=head-1; pos>=0; pos--) val[pos] = min(val[pos*2+1], val[pos*2+2]);
    }

    void resolve_dval(int pos, int l, int r) {
        val[pos] += dval[pos];
        if (pos < head)
        {
            dval[pos*2+1] += dval[pos];
            dval[pos*2+2] += dval[pos];
        }
        dval[pos] = I_dval;
    }

    void update(int begin, int end, DVAL dval_q) { update(begin, end, dval_q, 0, 0, head+1); }
    void update(int begin, int end, DVAL dval_q, int pos, int l, int r)
    {
        if (begin <= l && r <= end) {
            dval[pos] += dval_q;
            resolve_dval(pos, l, r);
        }
        else if (begin < r && l < end) {
            resolve_dval(pos, l, r);
            update(begin, end, dval_q, pos*2+1, l, (l+r)/2);
            update(begin, end, dval_q, pos*2+2, (l+r)/2, r);
            val[pos] = min(val[pos*2+1], val[pos*2+2]);
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
            val[pos] = min(val[pos*2+1], val[pos*2+2]);
            return min(vl, vr);
        }
        else return I_val;
    }
};

constexpr int MA = 1000003;
int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> a(N), b(M);
    cin >> a >> b;
    vector<int> rmqinit(MA);
    for (auto v : a) rmqinit[v]--;
    for (auto v : b) rmqinit[v]++;
    IREP(i, MA - 1) rmqinit[i] += rmqinit[i + 1];
    LazySegTree<int, int> rmq(rmqinit, 0, 0,
                              [](int a, int b) { return min(a, b); },
                              [](int &a, int b) { a += b; },
                              [](int &a, int b) { a += b; });

    int Q;
    cin >> Q;
    REP(_, Q)
    {
        int q, i, x;
        cin >> q >> i >> x;
        i--;
        if (q == 1)
        {
            if (x > a[i]) rmq.update(a[i] + 1, x + 1, -1);
            if (x < a[i]) rmq.update(x + 1, a[i] + 1, 1);
            // rmq.update(0, a[i] + 1, 1);
            // rmq.update(0, x + 1, -1);
            a[i] = x;
        }
        else
        {
            if (x > b[i]) rmq.update(b[i] + 1, x + 1, 1);
            if (x < b[i]) rmq.update(x + 1, b[i] + 1, -1);
            // rmq.update(0, b[i] + 1, -1);
            // rmq.update(0, x + 1, 1);
            b[i] = x;
        }

        int l = -1, r = MA - 1;
        while (r - l > 1)
        {
            int c = (l + r) / 2;
            if (rmq.getvalue(c, MA) >= 0) r = c; else l = c;
        }
        printf("%d\n", l);
    }
}