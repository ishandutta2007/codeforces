#include <bits/stdc++.h>

using namespace std;

namespace jumpmelon
{
    typedef long long big;

    const int M = 63;
    const big MX = 5000000000000000000LL;
    big x, A[M];
    struct opt { int tp; big a, b; };
    vector<opt> Ans;
    set<big> Vis;

    bool insert(big v, vector<pair<big, big>> &R)
    {
        R.clear();
        for (int i = M - 1; i >= 0; i--)
            if (v >> i & 1)
            {
                if (A[i])
                {
                    R.push_back({v, A[i]});
                    v ^= A[i];
                }
                else
                {
                    A[i] = v;
                    return 1;
                }
            }
        return 0;
    }

    bool check(big v)
    {
        for (int i = M - 1; i >= 0; i--)
            if (v >> i & 1)
            {
                if (A[i])
                    v ^= A[i];
                else
                    return 0;
            }
        return 1;
    }

    void work()
    {
        vector<pair<big, big>> R;
        scanf("%lld", &x);
        big v = x;
        Vis.insert(x);
        for (int i = 1; x <= (MX >> i); i++)
        {
            Ans.push_back({0, x << (i - 1), x << (i - 1)});
            Vis.insert(x << i);
        }
        insert(x, R);
        while (!check(1))
        {
            if (insert(v, R))
            {
                big t = v / x, c = 0;
                for (int i = 0; i < M; i++)
                    if (t >> i & 1)
                    {
                        if (Vis.insert(c + (x << i)).second)
                            Ans.push_back({0, c, x << i});
                        c += x << i;
                    }
                for (auto &&p : R)
                {
                    if (Vis.insert(p.first ^ p.second).second)
                        Ans.push_back({1, p.first, p.second});
                }
            }
            v += x;
        }
        printf("%d\n", (int)Ans.size());
        for (auto &&p : Ans)
            printf("%lld %c %lld\n", p.a, p.tp == 0 ? '+' : '^', p.b);
    }
}

int main()
{
    jumpmelon::work();
    return 0;
}