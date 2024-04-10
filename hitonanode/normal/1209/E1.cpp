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
template<typename T> bool mmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool mmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }


int TC, N, M;

lint solve()
{
    cin >> N >> M;
    if (N <= 3)
    {
        vector<int> A(N * M);
        cin >> A;
        sort(A.rbegin(), A.rend());
        return accumulate(A.begin(), A.begin() + N, 0LL);
    }
    if (M == 1)
    {
        vector<int> A(4);
        cin >> A;
        return accumulate(ALL(A), 0LL);
    }

    vector<vector<int>> A(N, vector<int>(M));
    cin >> A;
    vector<pair<int, pint>> m;
    REP(i, N) REP(j, M) m.emplace_back(A[i][j], pint(i, j));
    sort(m.rbegin(), m.rend());
    lint ret = 0;
    REP(s, 1 << 8) if (__builtin_popcount(s) == 4)
    {
        vector<pint> v;
        lint t = 0;
        REP(d, 8) if (s & (1 << d))
        {
            t += m[d].first;
            v.emplace_back(m[d].second.second, m[d].second.first);
        }
        sort(ALL(v));
        bool bad = false;
        if (v[0].first == v[1].first and v[1].first != v[2].first and v[2].first == v[3].first)
        {
            int f1 = abs(v[1].second - v[0].second), f2 = abs(v[2].second - v[3].second);
            if (f1 == 3) f1 = 1;
            if (f2 == 3) f2 = 1;
            if (f1 + f2 == 3) bad = true;
        }
        if (!bad) mmax(ret, t);
    }
    return ret;
}
int main()
{
    cin >> TC;
    REP(_, TC)
    {
        cout << solve() << endl;
    }
}