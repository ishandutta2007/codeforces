#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template <typename T> bool chmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }


int main()
{
    int N, M;
    cin >> N >> M;
    string A, B;
    cin >> A >> B;
    vector dp(N + 1, vector<int>(M + 1, 0));
    REP(i, dp.size()) {
        REP(j, dp[i].size()) {
            if (i < N and j < M and A[i] == B[j]) {
                chmax(dp[i + 1][j + 1], dp[i][j] + 2);
            }
            if (i < N) {
                chmax(dp[i + 1][j], dp[i][j] - 1);
            }
            if (j < M) {
                chmax(dp[i][j + 1], dp[i][j] - 1);
            }
        }
    }
    int ret = 0;
    for (auto vec : dp) {
        chmax(ret, *max_element(vec.begin(), vec.end()));
    }
    cout << ret << '\n';
}