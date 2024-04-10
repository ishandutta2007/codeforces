// Long Live The King
#include<bits/stdc++.h>
using namespace std;
const int N = 200005;
int n;
char A[N], T[N];
int main()
{
    int q;
    scanf("%d", &q);
    for (; q; q --)
    {
        int n;
        scanf("%d%s", &n, &A);
        for (int i = 0; i < n; i ++)
            A[i] -= '0';
        int pref = 0, suff = 9;
        while (pref < 9)
        {
            int a = 0, fail = 0;
            for (int i = 0; i < n; i ++)
                if (A[i] <= pref + 1)
                {
                    if (A[i] < a)
                        {fail = 1; break;}
                    a = A[i];
                }
            if (!fail)
                pref ++;
            else
                break;
        }
        while (suff > 0)
        {
            int a = 0, fail = 0;
            for (int i = 0; i < n; i ++)
                if (A[i] >= suff - 1)
                {
                    if (A[i] < a)
                        {fail = 1; break;}
                    a = A[i];
                }
            if (!fail)
                suff --;
            else
                break;
        }
        if (pref >= suff - 1)
        {
            for (int i = 0; i < n; i ++)
                putchar('1' + (A[i] >= suff));
            printf("\n");
            continue;
        }
        if (pref + 2 < suff)
        {
            printf("-\n");
            continue;
        }
        int ids = n, idp = -1, id;
        for (int i = 0; i < n; i ++)
            if (A[i] >= suff)
                {id = i; break;}
        for (int i = id; i < n; i ++)
            if (A[i] == suff - 1)
                {ids = i; break;}
        for (int i = n - 1; i >= 0; i --)
            if (A[i] <= pref)
                {id = i; break;}
        for (int i = id; i >= 0; i --)
            if (A[i] == pref + 1)
                {idp = i; break;}
        if (ids <= idp)
            printf("-\n");
        else
        {
            for (int i = 0; i < n; i ++)
            {
                if (A[i] <= pref)
                    putchar('1');
                else if (A[i] >= suff)
                    putchar('2');
                else if (i >= ids)
                    putchar('1');
                else
                    putchar('2');
            }
            printf("\n");
        }
    }
    return 0;
}