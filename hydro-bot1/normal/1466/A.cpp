// Hydro submission #6274cc30bda16328ffbaf932@1651821616491
#include<bits/stdc++.h>
using namespace std;
bool f[50];
int x[50];
int main()
{
    int t,n,i,j,k,s;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n;s=0;
        for(j=0;j<n;j++)
        cin>>x[j];
        for(j=0;j<50;j++)
        f[j]=false;
        for(j=0;j<n;j++)
        for(k=j+1;k<n;k++)
        f[x[k]-x[j]]=true;
        for(j=0;j<50;j++)
        if(f[j]) s++;
        printf("%d\n",s);
    }
    return 0;
}