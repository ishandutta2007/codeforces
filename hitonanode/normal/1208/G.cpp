#include <bits/stdc++.h>
using namespace std;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)

vector<int> euler_phis(int n)
{
    vector<int> ret(n + 1);
    iota(ret.begin(), ret.end(), 0);
    FOR(i, 2, n)
    {
        if (ret[i] == i)
        {
            for (int j = i; j <= n; j += i)
            {
                ret[j] = ret[j] / i * (i - 1);
            }
        }
    }
    return ret;
}

int main()
{
    int N, K;
    cin >> N >> K;
    if (K == 1)
    {
        puts("3");
        return 0;
    }
    vector<int> v = euler_phis(N);
    sort(v.begin() + 2, v.end());
    cout << accumulate(v.begin() + 2, v.begin() + 2 + K + 1, 0LL) + 1 << endl;
}