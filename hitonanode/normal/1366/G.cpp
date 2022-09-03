#include <bits/stdc++.h>
using namespace std;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> bool chmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;


int main()
{
    string S, T;
    cin >> S >> T;
    int N = S.length();

    vector<int> nxt(S.length(), -1);
    vector<int> ns(N * 2 + 1, -1);
    int s = N;
    ns[s] = 0;
    REP(i, S.length())
    {
        if (S[i] == '.')
        {
            ns[s] = -1;
            s--;
        }
        else s++;

        if (ns[s] >= 0) nxt[ns[s]] = i + 1;
        ns[s] = i + 1;
    }
    vector<int> dp(S.length() + 1, 1e9);
    dp[0] = 0;
    REP(i, S.length())
    {
        chmin(dp[i + 1], dp[i] + 1);
        if (nxt[i] >= 0) chmin(dp[nxt[i]], dp[i]);
    }

    for (auto c : T)
    {
        IREP(i, S.length())
        {
            if (S[i] == c) dp[i + 1] = dp[i];
            else dp[i + 1] = 1e9;
        }
        dp[0] = 1e9;
        REP(i, S.length())
        {
            chmin(dp[i + 1], dp[i] + 1);
            if (nxt[i] >= 0) chmin(dp[nxt[i]], dp[i]);
        }
    }
    cout << dp.back() << '\n';
}