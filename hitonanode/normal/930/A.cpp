#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)


vector<vector<int>> to;
vector<int> cnt;

void dfs(int now, int prv, int d = 1) {
    cnt[d] ^= 1;
    for (auto nxt : to[now]) if (nxt != prv) {
        dfs(nxt, now, d + 1);
    }
}

int main()
{
    int N;
    cin >> N;
    to.resize(N + 1);
    FOR(i, 2, N + 1)
    {
        int j;
        cin >> j;
        to[i].push_back(j);
        to[j].push_back(i);
    }

    cnt.resize(N + 1);
    dfs(1, 0);
    cout << accumulate(cnt.begin(), cnt.end(), 0) << "\n";
}