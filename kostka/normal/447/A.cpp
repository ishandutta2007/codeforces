#include "bits/stdc++.h"

using namespace std;

const int MAXN = 307;
bool tab[MAXN];

int main()
{
    int n, p;
    scanf("%d%d", &p, &n);
    for(int i=0; i<n; i++)
    {
        int a;
        scanf("%d", &a);
        if(tab[a%p]!=0)
        {
            printf("%d\n", i+1);
            return 0;
        }
        tab[a%p] = 1;
    }
    printf("-1\n");
    return 0;
}