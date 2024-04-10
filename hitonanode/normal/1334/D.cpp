#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

vector<int> solve()
{
    lint N, L, R;
    cin >> N >> L >> R;
    vector<int> ret(R - L + 1);
    lint now = 1;
    lint d = 1;
    while (d <= N)
    {
        if (now > R) return ret;
        lint w = (N - d) * 2;
        for (lint i = max(L, now); i <= min(R, now + w - 1); i++)
        {
            ret.at(i - L) = (i % 2 ? d : (i - now) / 2 + 1 + d);
        }
        now += w;
        d++;
    }
    return ret;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        auto ret = solve();
        if (!ret.back()) ret.back() = 1;
        for (auto x : ret) printf("%d ", x);
        puts("");
    }
}