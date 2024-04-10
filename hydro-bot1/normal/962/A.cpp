// Hydro submission #6259210637de167dd82bd174@1650008364027
#include<bits/stdc++.h>
using namespace std;
int a[200000],s,t;
int main()
{
    int n,i;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        s+=a[i];
    }
    for(i=0;i<n;i++)
    {
        t+=a[i];
        if(t>=(s+1)/2)
        {
            printf("%d\n",i+1);
            return 0;
        }
    }
    return 0;
}