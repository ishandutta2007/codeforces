#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using pint = pair<int, int>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> bool mmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool mmin(T &m, const T q) { if (q < m) {m = q; return true;} else return false; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
template<typename T> ostream &operator<<(ostream &os, const set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
template<typename T1, typename T2> ostream &operator<<(ostream &os, const pair<T1, T2> &pa){ os << "(" << pa.first << "," << pa.second << ")"; return os; }
template<typename TK, typename TV> ostream &operator<<(ostream &os, const map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;


constexpr int INF = 1.1e9;
int main()
{
    int N, M, K;
    cin >> N >> M >> K;
    vector<pint> lr(N);
    for (auto &p : lr) cin >> p.first >> p.second;
    sort(lr.begin(), lr.end());

    set<int> z;
    for (auto p : lr) z.insert(p.first), z.insert(p.second + 1);

    map<int, vector<int>> l2r;
    for (auto p : lr) l2r[p.first].push_back(p.second + 1);

    vector<int> dp(1 << K, -INF);
    dp[0] = 0;
    vector<int> R(K, 0);
    int exist = 0;
    int xp = 0;
    for (auto x : z) {
        REP(S, 1 << K) if (!((~exist) & S) and (__builtin_popcount(S) & 1)) {
            dp[S] += x - xp;
        }
        REP(d, K) if (R[d] == x) {
            R[d] = 0;
            exist -= 1 << d;
            REP(S, 1 << K) if ((S >> d) & 1) {
                mmax(dp[S - (1 << d)], dp[S]);
                dp[S] = -INF;
            }
        }
        for (auto nxtr : l2r[x]) {
            int d = 0;
            while (R[d]) d++;
            R[d] = nxtr;
            exist += 1 << d;
            REP(S, 1 << K) if ((S >> d) & 1) {
                mmax(dp[S], dp[S - (1 << d)]);
            }
        }
        xp = x;
    }
    cout << *max_element(dp.begin(), dp.end()) << endl;
}