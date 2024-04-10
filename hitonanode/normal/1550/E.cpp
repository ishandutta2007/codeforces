#include <iostream>
#include <vector>
using namespace std;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template <typename T> bool chmin(T &m, const T q) { return m > q ? (m = q, true) : false; }

int main() {
    cin.tie(nullptr), ios::sync_with_stdio(false);
    int N, K;
    string S;
    cin >> N >> K >> S;
    int ok = 0, ng = N / K + 1;
    vector cum(K, vector<int>(N + 1));
    REP(i, N) {
        REP(d, K) cum[d][i + 1] = cum[d][i] + (S[i] == '?');
        if (S[i] != '?') cum[S[i] - 'a'][i + 1]++;
    }
    while (ng > ok + 1) {
        const int c = (ok + ng) / 2;
        vector sucs(K, vector<int>(N + 1, N));
        REP(k, K) {
            REP(i, N - c + 1) {
                if (cum[k][i + c] - cum[k][i] == c) {
                    sucs[k][i] = i;
                }
            }
            IREP(i, sucs[k].size() - 1) chmin(sucs[k][i], sucs[k][i + 1]);
        }
        vector dp(1 << K, N + 1);
        dp[0] = 0;
        REP(s, dp.size()) if (dp[s] < N) {
            REP(k, K) {
                if ((s >> k) & 1) continue;
                chmin(dp[s + (1 << k)], sucs[k][dp[s]] + c);
            }
        }
        (dp.back() <= N ? ok : ng) = c;
    }
    cout << ok << '\n';
}