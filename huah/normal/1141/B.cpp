#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
int main()
{
    scanf("%d",&n);
    int pre=0,bk=0;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
    {
        if(a[i]==0) break;
        pre++;
    }
    for(int i=n;i>=1;i--)
    {
        if(a[i]==0) break;
        bk++;
    }
    int ans=pre+bk,cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==0) cnt=0;
        else cnt++;
        ans=max(ans,cnt);
    }
    cout<<ans<<endl;
}