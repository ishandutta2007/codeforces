#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)


int main()
{
    int N;
    cin >> N;
    vector<lint> x(N), y(N);
    REP(i, N)
    {
        cin >> x[i] >> y[i];
    }
    vector<int> ret;
    while (true) {
        int b0 = 0, b1 = 0;
        REP(i, N) (abs(x[i] + y[i]) % 2 ? b1 : b0)++;
        if (b0 and b1) break;
        if (b1) REP(i, N) x[i]++;
        REP(i, N) {
            int u = (x[i] + y[i]) / 2;
            int v = (x[i] - y[i]) / 2;
            x[i] = u, y[i] = v;
        }
    }
    REP(i, N) if (abs(x[i] + y[i]) % 2) ret.emplace_back(i + 1);
    printf("%d\n", (int)ret.size());
    for (auto x : ret) printf("%d ", x);
    puts("");
}