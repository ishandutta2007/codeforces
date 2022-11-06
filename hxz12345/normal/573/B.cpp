#include<bits/stdc++.h>
using namespace std;
long long a[200000],b[200000],c[200000],n,ans,i;
int main()
{
    cin>>n;
    for (i=1;i<=n;i++) cin>>a[i];
    for (i=1;i<=n;i++) b[i]=min(b[i-1]+1,a[i]);
    for (i=n;i>=1;i--) c[i]=min(c[i+1]+1,a[i]);
    for (i=1;i<=n;i++) ans=max(ans,min(b[i],c[i]));
    cout<<ans<<endl;
    return 0;
}