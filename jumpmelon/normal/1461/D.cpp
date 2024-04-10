#include <bits/stdc++.h>

using namespace std;

typedef long long big;

const int MAXN = 100000;
int A[MAXN + 1], D[MAXN + 1], C[MAXN + 1];
vector<big> S;

big solve(int a, int b)
{
    while (a < b && C[a] == 0)
        a++;
    while (a < b && C[b] == 0)
        b--;
    if (a == b)
    {
        S.push_back((big)D[a] * C[a]);
        return S.back();
    }
    else
    {
        int m = upper_bound(D + a, D + b + 1, (D[a] + D[b]) / 2) - D - 1;
        size_t s0 = S.size();
        big t1 = solve(a, m);
        size_t s1 = S.size();
        big t2 = solve(m + 1, b);
        inplace_merge(S.begin() + s0, S.begin() + s1, S.end());
        S.push_back(t1 + t2);
        return t1 + t2;
    }
}

int main()
{
    int kase;
    scanf("%d", &kase);
    while (kase--)
    {
        int n, q, m;
        scanf("%d%d", &n, &q);
        for (int i = 1; i <= n; i++)
            scanf("%d", &A[i]);
        memcpy(D + 1, A + 1, sizeof(int[n]));
        sort(D + 1, D + n + 1);
        m = unique(D + 1, D + n + 1) - D - 1;
        memset(C + 1, 0, sizeof(int[m]));
        for (int i = 1; i <= n; i++)
            C[lower_bound(D + 1, D + m + 1, A[i]) - D]++;
        S.clear();
        solve(1, m);
        while (q--)
        {
            big s;
            scanf("%lld", &s);
            puts(binary_search(S.begin(), S.end(), s) ? "Yes" : "No");
        }
    }
    return 0;
}