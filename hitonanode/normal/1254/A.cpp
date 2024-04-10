#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }


vector<char> cs;
void solve()
{
    int R, C, K;
    cin >> R >> C >> K;
    vector<string> S(R);
    cin >> S;
    REP(i, R) if (i % 2 == 0) reverse(S[i].begin(), S[i].end());
    int cr = 0;
    for (auto s : S) for (auto c : s) if (c == 'R') cr++;
    vector<int> n(K, cr / K);
    REP(i, cr % K) n[i]++;

    vector<vector<char>> ret(R, vector<char>(C));
    int now = 0;
    REP(i, R) REP(j, C)
    {
        if (S[i][j] == 'R')
        {
            n[now]--;
            if (n[now] < 0)
            {
                now++;
                n[now]--;
            }
        }
        ret[i][j] = cs[now];
    }

    REP(i, R) if (i % 2 == 0) reverse(ret[i].begin(), ret[i].end());
    REP(i, R)
    {
        for (auto c : ret[i]) printf("%c", c);
        puts("");
    }
}

int main()
{
    cs.resize(62);
    REP(i, 26)
    {
        cs[i] = 'a' + i;
        cs[i + 26] = 'A' + i;
    }
    REP(i, 10) cs[26 * 2 + i] = '0' + i;
    int T;
    cin >> T;
    while (T--) solve();
}