// Hydro submission #6274ce00bda16328ffbafb9a@1651822080700
#include<bits/stdc++.h>
using namespace std;
int a[50];
int main()
{
    int t,n,mn,mx,s,i,j;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n;s=0;
        for(j=0;j<n;j++)
        cin>>a[j];
        for(j=1;j<n;j++)
        {
            mn=min(a[j],a[j-1]);
            mx=max(a[j],a[j-1]);
            while(mn*2<mx)
            {
                mn*=2;
                s++;
            }
        }
        printf("%d\n",s);
    }
    return 0;
}