#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using pint = pair<int, int>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> bool mmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa){ os << "(" << pa.first << "," << pa.second << ")"; return os; }
template<typename TK, typename TV> ostream &operator<<(ostream &os, const map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }
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
    int N, M, P;
    cin >> N >> M >> P;
    vector<pint> A2C(N), B2C(M);
    REP(i, N) cin >> A2C[i].first >> A2C[i].second;
    REP(i, M) cin >> B2C[i].first >> B2C[i].second;

    sort(ALL(A2C));
    sort(ALL(B2C));
    vector<int> bz;
    for (auto p : B2C) bz.push_back(p.first);
    sort(ALL(bz));
    vector<lint> cost;
    for (auto p : B2C) cost.push_back(-p.second);
    LazySegTree<lint, lint> rmq(cost, -1e18, 0LL,
                              [](lint a, lint b) { return max(a, b); }, // merge
                              [](lint &a, lint b) { a += b; },          // 
                              [](lint &a, lint b) { a += b; });         // 

    vector<pair<int, pint>> x2yz(P);
    REP(i, P) {
        int x, y, z;
        cin >> x >> y >> z;
        x2yz[i] = make_pair(x, pint(y, z));
    }
    x2yz.emplace_back(1e9, pint(1e9, 1e9));
    sort(ALL(x2yz));
    int ix = 0;
    lint ret = -1e18;

    for (auto p : A2C) {
        int a = p.first, c = p.second;
        while (x2yz[ix].first < a) {
            int y = x2yz[ix].second.first, z = x2yz[ix].second.second;
            auto i = upper_bound(ALL(bz), y) - bz.begin();
            rmq.update(i, M, z);
            ix++;
        }
        mmax(ret, rmq.getvalue(0, M) - c);
    }
    cout << ret << endl;
}