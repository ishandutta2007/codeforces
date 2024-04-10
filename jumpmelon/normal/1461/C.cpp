#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100000;
int A[MAXN + 1];

int main()
{
    int kase;
    scanf("%d", &kase);
    while (kase--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
            scanf("%d", &A[i]);
        int t = n;
        while (t && A[t] == t)
            t--;
        double s = 1.0;
        while (m--)
        {
            int r;
            double p;
            scanf("%d%lf", &r, &p);
            if (r >= t)
                s *= 1.0 - p;
        }
        if (t == 0)
            s = 0;
        printf("%.8f\n", 1.0 - s);
    }
    return 0;
}