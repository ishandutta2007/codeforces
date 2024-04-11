//Bartosz Kostka
//You are not prepared!

#include "bits/stdc++.h"

using namespace std;

const int MAXN = 100007;
long long tab[MAXN];

bool czy(long long a, int n)
{
    tab[0] = a;
    long long ene = 0;
    for(int i=1; i<=n; i++)
    {
        long long diff = tab[i]-tab[i-1];
        //printf("%lld %lld\n", ene, diff);
        if(ene < diff)
            return false;
        ene -= diff;
    }
    return true;
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
        scanf("%I64d", tab+i);
    long long lo = 0, hi = 1000000000000000LL;
    while(hi-lo>1)
    {
        long long me = (lo+hi)/2;
        if(czy(me,n))
            hi = me;
        else
            lo = me;
    }
    printf("%I64d\n", lo+1);
    return 0;
}