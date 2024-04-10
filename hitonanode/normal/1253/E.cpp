#include <bits/stdc++.h>
using namespace std;
using pint = pair<int, int>;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template<typename T> bool mmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }


int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    vector<pint> lrs(N);
    REP(i, N)
    {
        int x, s;
        cin >> x >> s;
        lrs[i] = make_pair(x - s, x + s);
    }
    lrs.emplace_back(0, 0);

    vector<int> dp(M * 2 + 1, M * 2 + 10);
    dp[0] = 0;
    priority_queue<pint, vector<pint>, greater<pint>> pq;
    pq.emplace(M * 2 + 10, M * 2 + 10);
    FOR(x, 1, M * 2 + 1)
    {
        for (auto lr : lrs)
        {
            int l = lr.first, r = lr.second;
            if (l <= x and x <= r)
            {
                if (mmin(dp[x], dp[max(l - 1, 0)])) pq.emplace(dp[x], r);
            }
            else
            {
                int c = min(abs(l - x), abs(r - x));
                if (mmin(dp[x], dp[max(0, l - c - 1)] + c)) pq.emplace(dp[x], r + c);
            }
        }
        while (pq.top().second < x) pq.pop();
        mmin(dp[x], pq.top().first);
    }
    // dbg(dp);
    cout << *min_element(dp.begin() + M, dp.end()) << endl;
}