#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> void ndarray(vector<T> &vec, int len) { vec.resize(len); }
template<typename T, typename... Args> void ndarray(vector<T> &vec, int len, Args... args) { vec.resize(len); for (auto &v : vec) ndarray(v, args...); }
template<typename T> bool chmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;

constexpr int INF = 1e9;

int main()
{
    int N;
    string S;
    cin >> N >> S;
    vector<int> pk, pv, po;
    vector<int> rk(N), rv(N), ro(N);
    REP(i, N)
    {
        char c = S[i];
        if (c == 'K') pk.push_back(i), rk[i]++;
        else if (c == 'V') pv.push_back(i), rv[i]++;
        else po.push_back(i), ro[i]++;
    }
    int nk = pk.size(), nv = pv.size(), no = po.size();

    REP(i, N - 1) rk[i + 1] += rk[i];
    REP(i, N - 1) rv[i + 1] += rv[i];
    REP(i, N - 1) ro[i + 1] += ro[i];
    vector<vector<vector<vector<int>>>> dp;
    ndarray(dp, nk + 1, nv + 1, no + 1, 2);
    int ret = INF;
    for (auto &vvv : dp) for (auto &vv : vvv) for (auto &v : vv) for (auto &x : v) x = INF;
    dp[0][0][0][1] = 0;

    REP(ik, nk + 1) REP(iv, nv + 1) REP(io, no + 1) REP(d, 2) if (dp[ik][iv][io][d] < INF)
    {
        if (ik < nk and d)
        {
            int i = pk[ik];
            int add = max(rv[i] - iv, 0) + max(ro[i] - io, 0);
            chmin(dp[ik + 1][iv][io][1], dp[ik][iv][io][d] + add);
        }
        if (iv < nv)
        {
            int i = pv[iv];
            int add = max(rk[i] - ik, 0) + max(ro[i] - io, 0);
            chmin(dp[ik][iv + 1][io][0], dp[ik][iv][io][d] + add);
        }
        if (io < no)
        {
            int i = po[io];
            int add = max(rk[i] - ik, 0) + max(rv[i] - iv, 0);
            chmin(dp[ik][iv][io + 1][1], dp[ik][iv][io][d] + add);
        }
    }
    REP(d, 2) chmin(ret, dp[nk][nv][no][d]);
    cout << ret << '\n';
}