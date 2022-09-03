#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((lint)(x).size())
#define POW2(n) (1LL << (n))
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)

int main()
{
    int T;
    cin >> T;
    vector<int> pow2(22, 1);
    REP(i, 21) pow2[i + 1] = pow2[i] * 2;

    REP(_, T)
    {
        string S;
        cin >> S;
        int N = S.length();
        reverse(ALL(S));
        vector<int> z(N);
        IREP(i, N - 1)
        {
            if (S[i + 1] == '0') z[i] = z[i + 1] + 1;
        }
        int ret = 0;
        REP(i, N)
        {
            int t = 0;
            REP(j, 20)
            {
                if (i + j == N) break;
                t += (S[i + j] == '1') * pow2[j];
                if (t >= j + 1 and t <= j + 1 + z[i + j])
                {
                    ret++;
                    j = t - 1;
                }
            }
        }
        printf("%d\n", ret);
    }
}