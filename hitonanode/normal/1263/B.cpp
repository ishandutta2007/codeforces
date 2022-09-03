#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)

void solve()
{
    int N;
    cin >> N;
    vector<int> P(N);
    REP(i, N) cin >> P[i];
    vector<int> S(10000);
    int n = 0;
    vector<int> ret(N);
    REP(i, N)
    {
        if (!S[P[i]])
        {
            ret[i] = P[i];
        }
        else
        {
            n++;
            REP(d, 10000)
            {
                if (S[d] or find(ALL(P), d) != P.end()) continue;
                int u = 0;
                int R = d, T = P[i];
                REP(j, 4)
                {
                    if (R % 10 != T % 10) u++;
                    R /= 10, T /= 10;
                }
                if (u != 1) continue;
                ret[i] = d;
                break;
            }
        }
        S[ret[i]] = 1;
    }
    printf("%d\n", n);
    REP(i, N) printf("%04d\n", ret[i]);
}

int main()
{
    int T;
    cin >> T;
    while (T--) solve();
}