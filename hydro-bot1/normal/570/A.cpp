// Hydro submission #625506c817cd4d0a417647da@1649739465030
#include<bits/stdc++.h>
using namespace std;
int a[100],s[100];
int main()
{
    int n,m,i,j,k,mx;
    cin>>n>>m;
    for(i=0;i<m;i++)
    {
        mx=0,k=0;
        for(j=0;j<n;j++)
        {
            cin>>a[j];
            if(a[j]>mx)
            {
                mx=a[j];
                k=j;
            }
        }
        s[k]++;
    }
    mx=0,k=0;
    for(j=0;j<n;j++)
    if(s[j]>mx)
    {
        mx=s[j];
        k=j;
    }
    printf("%d\n",k+1);
    return 0;
}