#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)

int main()
{
    int N, M;
    cin >> N >> M;
    if (M == 1)
    {
        puts("1.0");
        return 0;
    }
    vector<int> xs(N);
    for (auto &x : xs) cin >> x;
    // xs.resize(100, 1);
    // M = 1000;

    int xtot = 0;
    vector<double> prob(1 + N * M, 0.0);
    prob[0] = 1.0;
    double inv = 1.0 / (M - 1);
    for (auto x : xs)
    {
        xtot += x;
        IREP(j, prob.size() - 1) if (prob[j])
        {
            double p = prob[j] * inv;
            if (j + 1 <= N * M) prob[j + 1] += p;
            if (j + x <= N * M) prob[j + x] -= p;
            if (j + 1 + x <= N * M) prob[j + 1 + x] += p;
            if (j + M + 1 <= N * M) prob[j + M + 1] -= p;
            prob[j] = 0;
        }
        REP(j, prob.size() - 1) prob[j + 1] += prob[j];
    }
    double lo_prob = accumulate(prob.begin(), prob.begin() + xtot, 0.0);
    cout << 1.0 + lo_prob * (M - 1) << '\n';
}