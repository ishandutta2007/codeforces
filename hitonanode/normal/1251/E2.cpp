#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)


lint solve()
{
    int N;
    cin >> N;
    map<int, vector<lint>> m2p;
    lint ret = 0;
    REP(i, N)
    {
        int m, p;
        cin >> m >> p;
        m2p[m].push_back(p);
        ret += p;
    }

    multiset<lint> ms;
    REP(i, N)
    {
        for (auto x : m2p[i]) ms.insert(x);
        if (!ms.empty())
        {
            auto itr = prev(ms.end());
            ret -= *itr;
            ms.erase(itr);
        }
    }
    return ret;
}

int main()
{
    int T;
    cin >> T;
    while (T--) cout << solve() << endl;
}