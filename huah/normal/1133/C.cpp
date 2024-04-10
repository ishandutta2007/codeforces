#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    int ans=1;
    for(int i=1;i<=n;i++)
    {
        int t=upper_bound(a+1,a+1+n,a[i]+5)-a;
        ans=max(ans,t-i);
    }
    cout<<ans<<endl;
}