#include <iostream>
#define DMAX 1000004
using namespace std;

int a, v[DMAX], l[DMAX], r[DMAX], n;

int main()
{
cin>>n;

    for(int i=1;i<=n;i++)
    {
        cin>>a;
        if(v[a]==0)
        {
            l[a]=i;
        }
        else r[a]=i;
        v[a]++;
    }
    int imax, vmax=-1;
    for(int i=1;i<=1000000;i++)
    {
        if(v[i]>vmax)
            vmax=v[i], imax=i;
        if(v[i]==vmax)
        {
            if(r[i]-l[i] < r[imax]-l[imax])
                vmax=v[i], imax=i;
        }
    }
    if(r[imax]==0)
        r[imax]=l[imax];
    cout<<l[imax]<<' '<<r[imax];
    return 0;
}