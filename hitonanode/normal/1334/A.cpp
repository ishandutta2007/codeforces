#include <bits/stdc++.h>
using namespace std;
using pint = pair<int, int>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)

bool solve()
{
    int N;
    cin >> N;
    pint l(0, 0);
    vector<pint> PC(N);
    REP(i, N) cin >> PC[i].first >> PC[i].second;
    for (auto p : PC)
    {
        int dp = p.first - l.first;
        int dw = p.second - l.second;
        if (dw > dp or dp < 0 or dw < 0)
        {
            return false;
        }
        l = p;
    }
    return true;
}

int main()
{
    int TC;
    cin >> TC;
    while (TC--)
    {
        cout << (solve() ? "YES" : "NO") << "\n";
    }
}