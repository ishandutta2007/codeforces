#include <bits/stdc++.h>
using namespace std;

int tab[1007];
bool odw[1007];


int main()
{
    int N;
    scanf("%d",&N);
    int il = 0;
    for (int i = 0;i < N;i++)
        scanf("%d",&tab[i]);
    int odp = -1;
    while (il < N)
    {
        odp++;
        if (odp%2 == 0)
        {
            for (int i = 0;i < N;i++)
            {
                if (tab[i] <= il && !odw[i])
                {
                    odw[i] = true;
                    il++;
                }
            }
        }
        else
        {
            for (int i = N-1;i >= 0;i--)
            {
                if (tab[i] <= il && !odw[i])
                {
                    odw[i] = true;
                    il++;
                }
            }
        }
    }
    printf("%d",odp);
    return 0;
}