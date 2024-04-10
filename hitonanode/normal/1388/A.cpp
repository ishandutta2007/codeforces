#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)

vector<int> solve()
{
    int N;
    cin >> N;
    vector<int> ret{6, 10, 14, N - 30};
    REP(d, 3) if (ret[d] == ret.back()) ret[2]++, ret.back()--;
    if (ret.back() <= 0) return {};
    return ret;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        auto ret = solve();
        if (ret.size())
        {
            cout << "YES\n";
            for (auto s : ret) cout << s << ' ';
            cout << '\n';
        }
        else cout << "NO\n";
    }
}