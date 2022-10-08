#include "bits/stdc++.h"

using namespace std;

int taba[100007], tabb[100007];

long long res = 0;

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    for(int i=0; i<a; i++)
        scanf("%d", &taba[i]);
    for(int i=0; i<b; i++)
        scanf("%d", &tabb[i]);
    int mini = 1000000007, maxi = 0;
    for(int i=0; i<a; i++)
        mini = min(mini, taba[i]);
    for(int i=0; i<b; i++)
        maxi = max(maxi, tabb[i]);
    sort(taba, taba+a);
    sort(tabb, tabb+b);
    reverse(tabb, tabb+b);
    if(mini >= maxi)
    {
        puts("0");
        return 0;
    }
    for(int i=0; i<min(a,b); i++)
    {
        if(taba[i] >= tabb[i])
            break;
        res += tabb[i]-taba[i];
    }
    printf("%lld\n", res);
}