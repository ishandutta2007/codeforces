#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<typename T> void ndarray(vector<T> &vec, int len) { vec.resize(len); }
template<typename T, typename... Args> void ndarray(vector<T> &vec, int len, Args... args) { vec.resize(len); for (auto &v : vec) ndarray(v, args...); }
template<typename T> bool mmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template<typename T> bool mmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
template<typename T1, typename T2> pair<T1, T2> operator+(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first + r.first, l.second + r.second); }
template<typename T1, typename T2> pair<T1, T2> operator-(const pair<T1, T2> &l, const pair<T1, T2> &r) { return make_pair(l.first - r.first, l.second - r.second); }
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
///// This part below is only for debug, not used /////
template<typename T> ostream &operator<<(ostream &os, const vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
#define dbg(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ") " << __FILE__ << endl;
///// END /////

constexpr int M = 251;
constexpr int INF = 100000000;

int main()
{
    int N, Q;
    string S;
    cin >> N >> Q >> S;
    vector<vector<vector<int>>> dp;
    ndarray(dp, M, M, M); // reshape

    REP(i, M) REP(j, M) REP(k, M) dp[i][j][k] = INF;
    dp[0][0][0] = -1;

    vector<vector<int>> search;
    ndarray(search, 26, S.length());
    REP(c, 26)
    {
        int now = INF;
        IREP(i, S.length())
        {
            if (S[i] - 'a' == c) now = i;
            search[c][i] = now;
        }
    }

    vector<string> word(3);
    REP(i, Q)
    {
        char c;
        int j;
        cin >> c >> j;
        j--;
        if (c == '+')
        {
            char v;
            cin >> v;
            word[j].push_back(v);
            REP(s, M) REP(t, M)
            {
                int l, m, n;
                if (j == 0) l = word[j].length(), m = s, n = t;
                else if (j == 1) l = s, m = word[j].length(), n = t;
                else l = s, m = t, n = word[j].length();

                if (l + m + n == 0) continue;
                dp[l][m][n] = INF;
                if (l > 0 and l - 1 < word[0].size() and dp[l - 1][m][n] + 1 < N) mmin(dp[l][m][n], search[word[0][l - 1] - 'a'][dp[l - 1][m][n] + 1]);
                if (m > 0 and m - 1 < word[1].size() and dp[l][m - 1][n] + 1 < N) mmin(dp[l][m][n], search[word[1][m - 1] - 'a'][dp[l][m - 1][n] + 1]);
                if (n > 0 and n - 1 < word[2].size() and dp[l][m][n - 1] + 1 < N) mmin(dp[l][m][n], search[word[2][n - 1] - 'a'][dp[l][m][n - 1] + 1]);
            }
        }
        else word[j].pop_back();

        if (dp[word[0].length()][word[1].length()][word[2].length()] < INF) puts("YES");
        else puts("NO");
    }
}