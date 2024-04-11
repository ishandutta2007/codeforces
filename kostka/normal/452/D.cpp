//Bartosz Kostka
//You are not prepared!

#include "bits/stdc++.h"

using namespace std;

int n[5], t[5];
long long ost[5][1007];

int laundry(int step, long long ready)
{
    if(step==3)
        return 0;
    long long mini = 1LL<<62;
    int miniid = -1;
    for(int i=0; i<n[step]; i++)
    {
        if(ost[step][i] < mini)
        {
            mini = ost[step][i];
            miniid = i;
        }
    }
    ready = max(ready, mini);
    int tmp = laundry(step+1, ready + t[step]);
    if(tmp > ready+t[step])
        ost[step][miniid] = tmp - t[step+1];
    else
        ost[step][miniid] = ready+t[step];
    //printf("%d %lld\n", step, ost[step][miniid]);
    return ost[step][miniid];
}

void test()
{
    int k;
    scanf("%d", &k);
    for(int i=0; i<3; i++)
        scanf("%d", &n[i]);
    for(int i=0; i<3; i++)
        scanf("%d", &t[i]);    
    for(int i=0; i<k; i++)
        laundry(0,0);
    long long res = 0;
    for(int i=0; i<n[2]; i++)
        res = max(res, ost[2][i]);
    printf("%lld\n", res);
}

int main()
{
    int t = 1;
    while(t--)
        test();
    return 0;
}