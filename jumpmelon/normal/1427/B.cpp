#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100000;
char S[MAXN + 1];
int A[MAXN + 1];

int main()
{
    int kase;
    scanf("%d", &kase);
    while (kase--)
    {
        int n, k;
        scanf("%d%d", &n, &k);
        scanf("%s", S);
        int m = 0, ans = 0, c = n, prev = -1;
        for (int i = 0; i < n; i++)
            if (S[i] == 'W')
            {
                c--;
                ans++;
                if (prev != -1 && prev == i - 1)
                    ans++;
                if (prev != -1 && prev != i - 1)
                    A[m++] = i - prev - 1;
                prev = i;
            }
        sort(A, A + m);
        ans += 2 * min(k, c);
        if (c == n && k)
            ans--;
        for (int i = 0; i < m; i++)
            if (k >= A[i])
            {
                k -= A[i];
                ans++;
            }
        printf("%d\n", ans);
    }
}