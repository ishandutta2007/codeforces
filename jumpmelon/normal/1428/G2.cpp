#include <bits/stdc++.h>

using namespace std;

typedef long long big;

const int N = 1000000, M = 6;
big F[N + 1], G[N + 1], C[M];
struct st { int i; big v; } Q[N + 1];

int main()
{
    int k;
    scanf("%d", &k);
    for (int i = 0; i < M; i++)
        scanf("%lld", &C[i]);
    memset(F + 1, 0xc0, sizeof(big[N]));
    for (int b = 0, t = 1; b < M; b++, t *= 10)
    {
        int w = 3 * t, lim = 3 * (k - 1);
        memset(G + 1, 0xc0, sizeof(big[N]));
        for (int r = 0; r < w; r++)
        {
            st *h = Q, *t = Q - 1;
            for (int i = r, p = 0; i <= N; i += w, p++)
            {
                big vi = F[i] - p * C[b];
                while (h <= t && t->v <= vi)
                    t--;
                *++t = {i, vi};
                while (h <= t && (i - h->i) / w > lim)
                    h++;
                if (h <= t)
                    G[i] = max(G[i], h->v + p * C[b]);
            }
        }
        memcpy(F + 1, G + 1, sizeof(big[N]));
        for (int i = N; i >= 0; i--)
        {
            for (int j = 1; j <= 9 && j * t <= i; j++)
            {
                big v = 0;
                if (j % 3 == 0)
                    v = (j / 3) * C[b];
                F[i] = max(F[i], F[i - j * t] + v);
            }
        }
    }
    int q;
    scanf("%d", &q);
    while (q--)
    {
        int n;
        scanf("%d", &n);
        printf("%lld\n", F[n]);
    }
    return 0;
}