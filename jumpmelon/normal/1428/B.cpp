#include <bits/stdc++.h>

using namespace std;

const int MAXN = 300000;
char S[MAXN + 1];

int main()
{
    // freopen("B.in", "r", stdin);
    int kase;
    scanf("%d", &kase);
    while (kase--)
    {
        int n;
        scanf("%d", &n);
        scanf("%s", S);
        int cl = 0, cr = 0;
        for (int i = 0; i < n; i++)
            if (S[i] == '<')
                cl++;
            else if (S[i] == '>')
                cr++;
        if (cl == 0 || cr == 0)
            printf("%d\n", n);
        else
        {
            int ans = 0;
            for (int i = 0; i < n; i++)
                if (S[i] == '-' || S[(i + 1) % n] == '-')
                    ans++;
            printf("%d\n", ans);
        }
    }
}