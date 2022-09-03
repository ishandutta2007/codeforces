#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)

int main()
{
    int N, M;
    cin >> N >> M;
    if (N > M + 1) {
        puts("Impossible");
        return 0;
    }
    vector<pair<int, int>> e;
    FOR(i, 1, N + 1) if (M) {
        FOR(j, i + 1, N + 1) {
            if (M and __gcd(i, j) == 1) {
                e.emplace_back(i, j);
                M--;
            }
        }
    }
    if (M) puts("Impossible");
    else {
        puts("Possible");
        for (auto p : e) printf("%d %d\n", p.first, p.second);
    }
}