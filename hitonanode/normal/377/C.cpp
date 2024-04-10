#include <bits/stdc++.h>
using namespace std;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template <typename T> bool chmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template <typename T> bool chmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }

int main() {
    cin.tie(nullptr), ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<int> S(N);
    for (auto &s : S) cin >> s;
    int M;
    cin >> M;
    vector<char> pb(M);
    vector<int> ids(M);
    REP(i, M) cin >> pb[i] >> ids[i], ids[i]--;
    

    sort(S.rbegin(), S.rend());
    S.resize(M);

    vector<int> dp(1 << M);
    FOR(s, 1, 1 << M) {
        int rem = __builtin_popcount(s);
        int t = M - rem;
        if (ids[t] == 0) {
            // 
            dp[s] = -(1 << 30);
            REP(i, M) if ((s >> i) & 1) {
                int add = 0;
                if (pb[t] == 'p') add = S[i];
                chmax(dp[s], dp[s - (1 << i)] + add);
            }

        } else {
            dp[s] = 1 << 30;
            REP(i, M) if ((s >> i) & 1) {
                int add = 0;
                if (pb[t] == 'p') add = -S[i];
                chmin(dp[s], dp[s - (1 << i)] + add);
            }
        }
    }
    cout << dp.back() << '\n';
}