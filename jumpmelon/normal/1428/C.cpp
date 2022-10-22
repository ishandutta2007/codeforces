#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200000;
char S[MAXN + 1], St[MAXN + 1];

int main()
{
    int kase;
    scanf("%d", &kase);
    while (kase--)
    {
        scanf("%s", S);
        int n = strlen(S);
        char *top = St;
        for (int i = 0; i < n; i++)
            if (S[i] == 'B' && top > St)
                top--;
            else
                *top++ = S[i];
        printf("%d\n", int(top - St));
    }
    return 0;
}