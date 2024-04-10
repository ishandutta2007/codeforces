#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> bool chmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool chmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;

int main()
{
    vector<vector<int>> states;
    REP(S, 10000)
    {
        vector<int> v(4);
        int t = S;
        REP(i, 4) v[i] = t % 10, t /= 10;
        bool flg = true;
        REP(i, 3) if (v[i] > v[i + 1]) flg = false;
        if (flg) states.emplace_back(v);
    }
    int M = states.size();
    vector to(M, vector<int>(4, -1));
    REP(s, M) REP(d, 4) if (states[s][d])
    {
        vector<int> v = states[s];
        // REP(i, 4) if (v[i] == v[d] and i != d) v[i] = 0;
        v[d] = 0;
        sort(v.begin(), v.end());
        int i = find(states.begin(), states.end(), v) - states.begin();
        to[s][d] = i;
    }

    vector add(M, vector<int>(10, -1));
    REP(s, M) if (states[s][0] == 0)
    {
        FOR(a, 1, 10)
        {
            vector<int> v = states[s];
            v[0] = a;
            sort(v.begin(), v.end());
            int i = find(states.begin(), states.end(), v) - states.begin();
            add[s][a] = i;
        }
    }


    int N;
    cin >> N;
    constexpr int INF = 1e9;
    vector dp(10, vector<int>(M, INF));
    dp[1][0] = 0;
    while (N--)
    {
        int a, b;
        cin >> a >> b;
        vector nxt(10, vector<int>(M, INF));
        FOR(now, 1, 10) REP(m, M) if (add[m][b] >= 0)
        {
            chmin(nxt[a][add[m][b]], dp[now][m] + 1 + abs(now - a));
        }
        dp = nxt;
        IREP(m, M) FOR(now, 1, 10) REP(d, 4) if (to[m][d] >= 0) {
            chmin(dp[states[m][d]][to[m][d]], dp[now][m] + 1 + abs(states[m][d] - now));
        }
    }

    int ret = INF;
    FOR(now, 1, 10) chmin(ret, dp[now][0]);
    cout << ret << '\n';
}