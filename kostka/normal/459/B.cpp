//Bartosz Kostka
//You are not prepared!

#include "bits/stdc++.h"

using namespace std;

const int MAXN = 200007;
int tab[MAXN];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%d", &tab[i]);
    int maks = tab[0];
    int mini = tab[0];
    long long ile1 = 0, ile2 = 0;
    for(int i=1; i<n; i++)
    {
        maks = max(maks, tab[i]);
        mini = min(mini, tab[i]);
    }
    if(maks==mini)
    {
        for(int i=0; i<n; i++)
        {
            if(tab[i]==maks)
                ile1++;
        }
        printf("0 %lld\n", 1LL*ile1*(ile1-1)/2);
    }
    else
    {
        for(int i=0; i<n; i++)
        {
            if(tab[i]==maks)
                ile1++;
            if(tab[i]==mini)
                ile2++;
        }
        printf("%d %lld\n", maks-mini, 1LL*ile1*ile2);
    }
    return 0;
}