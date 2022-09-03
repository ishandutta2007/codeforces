#include <bits/stdc++.h>
using namespace std;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)


int solve()
{
    string S, T;
    cin >> S >> T;
    int N = S.length();
    S += S;
    vector<vector<int>> nxt(S.length(), vector<int>(26, S.length()));
    IREP(i, int(S.length()) - 1) {
        nxt[i] = nxt[i + 1];
        nxt[i][S[i + 1] - 'a'] = i + 1;
    }
    int ret = 0, now = N - 1;
    for (auto c : T) {
        now = nxt[now][c - 'a'];
        if (now == S.length()) return -1;
        if (now >= N) now %= N, ret++;
    }
    return ret;
}


int main()
{
    int T;
    cin >> T;
    while (T--) cout << solve() << endl;
}