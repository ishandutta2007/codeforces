#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int a[300009];
int go(int l,int r)
{
    if(l==r)return 0;

    int mid=(l+r)/2;
    int mn0=INT_MAX,mx0=0,mn1=INT_MAX,mx1=0;

    for(int i=l;i<=mid;i++)
        mn0=min(mn0,a[i]),mx0=max(mx0,a[i]);
    for(int i=mid+1;i<=r;i++)
        mn1=min(mn1,a[i]),mx1=max(mx1,a[i]);
    if((mn0<mx1)&&(mn1<mx0))return -1;

    int ans=go(l,mid);
    if(ans==-1)return -1;
    int g=go(mid+1,r);
    if(g==-1)return -1;
    ans+=g;
    if((mx1<mn0))ans++;
    return ans;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)cin>>a[i];
        int ans=go(0,n-1);
        cout<<ans<<endl;
     }
    return 0;
}