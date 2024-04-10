#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> bool mmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool mmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa){ os << "(" << pa.first << "," << pa.second << ")"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;


constexpr lint INF = 10000000000000LL;

int main()
{
    int N;
    cin >> N;
    vector<plint> A(N);
    REP(i, N)
    {
        cin >> A[i].first;
        A[i].second = i + 1;
    }
    A.emplace_back(INF, N + 1);
    sort(A.begin(), A.end());
    vector<lint> prof(N + 1, 0), path(N + 1, -1);
    prof[0] = 0;
    int best_pos = 0;
    FOR(i, 3, N + 1)
    {
        prof[i] = prof[best_pos] + A[i].first - A[i - 1].first;
        path[i] = best_pos;
        if (prof[i - 2] > prof[best_pos]) best_pos = i - 2;
    }
    vector<set<int>> team;
    int now = N;
    while (now >= 3)
    {
        set<int> s;
        FOR(i, path[now], now) s.insert(A[i].second);
        now = path[now];
        team.emplace_back(s);
    }
    // dbg(team);
    lint ret = INF - prof.back() - A[0].first;
    printf("%lld %d\n", ret, (int)team.size());
    vector<int> tv(N);
    REP(i, (int)team.size()) for (auto x : team[i]) tv[x - 1] = i + 1;
    REP(i, N) printf("%d ", tv[i]);
    puts("");
}