#include <bits/stdc++.h>

using namespace std;

namespace jumpmelon
{
    const int MAXN = 52;
    int A[MAXN + 1], B[MAXN + 1];
    bool F[MAXN + 1];
    
    void work()
    {
        // freopen("D.in", "r", stdin);
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &A[i]);
        vector<vector<int>> Ans;
        while (1)
        {
            memset(F + 1, 0, sizeof(bool[n]));
            for (int i = 1; i < n; i++)
                if (A[i] + 1 == A[i + 1])
                    F[i] = 1;
            int x = 0, y = 0;
            for (int i = 1; i <= n; i++)
                if (!F[i])
                    for (int j = 1; j < i; j++)
                        if (A[j] == A[i] + 1)
                        {
                            x = i;
                            y = j;
                        }
            if (x == 0 && y == 0)
                break;
            int p = x;
            while (p > 1 && F[p - 1])
                p--;
            vector<int> D;
            if (y > 1)
                D.push_back(y - 1);
            D.push_back(p - y);
            D.push_back(x - p + 1);
            if (x < n)
                D.push_back(n - x);
            Ans.push_back(D);
            int l = 1, r = n;
            for (int v : D)
            {
                r -= v;
                for (int i = 1; i <= v; i++)
                    B[r + i] = A[l + i - 1];
                l += v;
            }
            memcpy(A + 1, B + 1, sizeof(int[n]));
        }
        printf("%d\n", (int)Ans.size());
        for (auto &&D : Ans)
        {
            printf("%d", (int)D.size());
            for (int v : D)
                printf(" %d", v);
            putchar('\n');
        }
    }
}

int main()
{
    jumpmelon::work();
    return 0;
}