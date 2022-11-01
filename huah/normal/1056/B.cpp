#include<bits/stdc++.h>
using namespace std;
int a[1005];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
        a[i]=n/m;
    for(int i=(n/m)*m+1;i<=n;i++)
        a[i%m]++;
    long long ans=0;
    for(int i=0;i<m;i++)
        for(int j=0;j<m;j++)
        if((i*i+j*j)%m==0) ans+=(long long)a[i]*a[j];
    cout<<ans<<endl;
}