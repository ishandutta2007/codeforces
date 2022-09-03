#include <bits/stdc++.h>
using namespace std;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> bool chmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa){ os << "(" << pa.first << "," << pa.second << ")"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;

vector<int> mapping;

struct rand_int_
{
    using lint = long long;
    mt19937 mt;
    rand_int_() : mt(chrono::steady_clock::now().time_since_epoch().count()) {}
    lint operator()(lint x) { return this->operator()(0, x); } // [0, x)
    lint operator()(lint l, lint r) {
        uniform_int_distribution<lint> d(l, r - 1);
        return d(mt);
    }
} rnd;

int ask(int i, int j)
{
    assert(i != j);
    cout << "? " << mapping[i] << ' ' << mapping[j] << endl;
    int ret;
    cin >> ret;
    if (ret == -1) exit(8);
    return ret;
}

void answer(vector<int> v_)
{
    vector<int> ret(v_.size());
    REP(i, v_.size()) ret[mapping[i] - 1] = v_[i];
    cout << '!';
    for (auto x : ret) cout << ' ' << x;
    cout << endl;
    exit(0);
}

int main()
{
    int N;
    cin >> N;
    mapping.resize(N);
    iota(mapping.begin(), mapping.end(), 1);
    random_shuffle(mapping.begin(), mapping.end(), rnd);

    if (N * (N - 1) / 2 <= 4269)
    {
        vector<vector<int>> q(N, vector<int>(N));
        REP(i, N) REP(j, i) q[i][j] = q[j][i] = ask(i, j);

        vector<int> iot(N);
        iota(iot.begin(), iot.end(), 0);
        REP(i, N)
        {
            auto v = q[i];
            sort(v.begin(), v.end());
            if (iot == v)
            {
                answer(q[i]);
            }
        }
        exit(8);
    }

    int D = 1;
    while ((1 << D) < N) D++;
    int allon = (1 << D) - 1;

    vector<int> p1(N - 1);
    vector<int> m_on(D, -1);
    vector<int> m_off(D, -1);

    set<int> zero_cand;
    REP(i, N) zero_cand.insert(i);

    vector<int> offmask(N);
    REP(i, N - 1)
    {
        p1[i] = ask(i, i + 1);
        offmask[i] |= (~p1[i] & allon);
        offmask[i + 1] |= (~p1[i] & allon);
        REP(d, D) if (!((p1[i] >> d) & 1)) m_off[d] = i;
    }

    // vector<int> onmask(N);
    REP(i, N - 2)
    {
        int diff = p1[i + 1] & ~p1[i];
        REP(d, D) if ((diff >> d) & 1) m_on[d] = i + 2, zero_cand.erase(i + 2);
        // onmask[i + 2] |= diff;

        diff = p1[i] & ~p1[i + 1];
        REP(d, D) if ((diff >> d) & 1) m_on[d] = i, zero_cand.erase(i);
        // onmask[i] |= diff;
    }

    vector<int> dist(1 << D, 1e9), prv(1 << D, -1), use(1 << D, -1);
    // vector<pint> use(1 << D, pint(-1, -1));
    dist[0] = 0;
    REP(S, 1 << D) REP(i, N)
    {
        if (chmin(dist[S | offmask[i]], dist[S] + 1))
        {
            prv[S | offmask[i]] = S;
            use[S | offmask[i]] = i;
        }
    }
    int n_ = (1 << D) - 1;
    vector<int> cv;
    while (n_)
    {
        cv.emplace_back(use[n_]);
        n_ = prv[n_];
    }

    int i0 = -1;
    for (auto i : zero_cand)
    {
        bool flg = true;
        for (auto icv : cv)
        {
            int t = ask(i, icv);
            if (t & offmask[icv])
            {
                flg = false;
                break;
            }
        }
        if (flg)
        {
            i0 = i;
            break;
        }
    }
    vector<int> ret(N, -1);
    ret[i0] = 0;
    REP(i, N) if (i != i0) ret[i] = ask(i, i0);
    answer(ret);
}