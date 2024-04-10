#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)

lint solve()
{
    lint N, S;
    cin >> N >> S;
    vector<lint> lo(N), hi(N);
    REP(i, N) cin >> lo[i] >> hi[i];

    lint l = 1, r = 1e15;
    while (r - l > 1)
    {
        lint c = (l + r) / 2;
        int n_low = 0;
        lint low_sum = 0;
        int n_hi = 0;
        lint hi_sum = 0;
        lint med_sum = 0;
        vector<lint> tmp;
        REP(i, N)
        {
            if (hi[i] < c)
            {
                n_low++;
                low_sum += lo[i];
            }
            else if (lo[i] > c)
            {
                n_hi++;
                hi_sum += lo[i];
            }
            else
            {
                med_sum += lo[i];
                tmp.emplace_back(c - lo[i]);
            }
        }
        sort(tmp.begin(), tmp.end());
        if (n_low > N / 2) 
        {
            r = c;
            continue;
        }
        lint req = low_sum + hi_sum + med_sum + accumulate(tmp.begin(), tmp.begin() + max(min<int>(tmp.size(), N / 2 + 1 - n_hi), 0), 0LL);
        (req <= S ? l : r) = c;
    }
    return l;
}

int main()
{
    int T;
    cin >> T;
    while (T--) cout << solve() << endl;
}