#include<bits/stdc++.h>
using namespace std;
int n,k,a[200005];
int vis[105];
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        a[i]%=k;
        vis[a[i]]++;
    }
    long long ans=vis[0]/2;
    int l=1,r=k-1;
    while(l<r)
    {
        ans+=min(vis[l],vis[r]);
        l++;r--;
    }
    if(l==r)
        ans+=vis[l]/2;
    cout<<ans*2<<endl;
}