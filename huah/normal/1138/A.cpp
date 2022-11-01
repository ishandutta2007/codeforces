#include<bits/stdc++.h>
using namespace std;
int n,a[100005],b[100005],c[100005];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
    {
        if(a[i]!=a[i-1]) b[i]=1;
        else b[i]=b[i-1]+1;
    }
    for(int i=n;i>=1;i--)
    {
        if(a[i]!=a[i+1]) c[i]=1;
        else c[i]=c[i+1]+1;
    }
    int ans=0;
    for(int i=1;i<n;i++)
    {
        if(a[i]!=a[i+1])
        {
            int t=min(b[i],c[i+1])*2;
            ans=max(ans,t);
        }
    }
    cout<<ans<<endl;
}