#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
ll a[100005];
int main()
{
    ll ans=0;
    a[0]=0;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]),ans+=a[i];
    sort(a+1,a+1+n);
    for(int i=n-1;i>=1;i--)
        if(a[i]>=a[i+1]) a[i]=max((ll)1,a[i+1]-1);
    /*for(int i=1;i<=n;i++) cout<<a[i]<<' ';
    cout<<endl;*/
    for(int i=n;i>=1;i--)
        ans=ans-max(1ll,a[i]-a[i-1]);
    printf("%lld\n",ans);
}