//Bartosz Kostka
//You are not prepared!

#include "bits/stdc++.h"

using namespace std;

const int MAXN = 100007;
static int tab[2*MAXN], ile[2*MAXN];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%d", tab+i);
    for(int i=0; i<n; i++)
        tab[n+i] = tab[i];
    for(int i=1; i<2*n; i++)
    {
        if(tab[i]>=tab[i-1])
            ile[i] = ile[i-1]+1;
        else
            ile[i] = 0;
        //printf("%d\n", ile[i]);
    }
    for(int i=2*n-1; i>=0; i--)
        if(ile[i]==n-1)
        {
            printf("%d\n", (2*n-1-i)%n);
            return 0;
        }
    printf("-1\n");
    return 0;
}