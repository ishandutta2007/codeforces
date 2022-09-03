#include <bits/stdc++.h>
using namespace std;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
struct fast_ios { fast_ios(){ cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
template <typename T> bool chmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
template <typename T> bool chmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }


constexpr int INF = 1 << 20;
int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    for (auto &x : A) cin >> x;

    int N0 = count(A.begin(), A.end(), 0), N1 = N - N0;

    vector dp(N0 * N1 + 1, vector(N1 + 1, vector(N0 + 1, INF))); // dp[move][last zero pos][successive zero] = min. invalid pair
    dp[0][0][0] = 0;
    int cnt1 = 0;
    for (auto a : A)
    {
        if (a == 1)
        {
            cnt1++;
            continue;
        }
        vector dpnxt(N0 * N1 + 1, vector(N1 + 1, vector(N0 + 1, INF)));
        for (int mv = 0; mv <= N0 * N1; mv++)
        {
            for (int last0 = 0; last0 <= N1; last0++)
            {
                for (int suc = 0; suc <= N0; suc++)
                {
                    if (dp[mv][last0][suc] < INF)
                    {
                        chmin(dpnxt[mv + abs(last0 - cnt1)][last0][suc + 1], dp[mv][last0][suc] + suc);
                        for (int l0nxt = last0 + 1; l0nxt <= N1; l0nxt++)
                        {
                            chmin(dpnxt[mv + abs(l0nxt - cnt1)][l0nxt][1], dp[mv][last0][suc]);
                        }
                    }
                }
            }
        }
        swap(dp, dpnxt);
    }
    vector<int> ret(N * (N - 1) / 2 + 1);
    for (int mv = 0; mv <= N0 * N1; mv++) if (mv < int(ret.size()))
    {
        for (auto vec : dp[mv])
        {
            chmax(ret[mv], N0 * (N0 - 1) / 2 - *min_element(vec.begin(), vec.end()));
        }
    }
    for (int i = 0; i < int(ret.size()) - 1; i++)
    {
        chmax(ret[i + 1], ret[i]);
    }

    for (auto x : ret) cout << x << ' ';
    cout << '\n';
}