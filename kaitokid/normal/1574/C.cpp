#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200009];
int main(){
int n;
//cin>>n;
scanf("%d",&n);
ll sum=0;
for(int i=1;i<=n;i++){scanf("%lld",&a[i]);sum+=a[i];}
sort(a+1,a+n+1);
int m;
scanf("%d",&m);
while(m--)
{
    ll x,y;
    scanf("%lld%lld",&x,&y);
    int u=lower_bound(a+1,a+n+1,x)-a;
    ll ans=3000000000000000000;
    if(u<=n)
    {
        ll res=y-(sum-a[u]);
        res=max(res,0LL);
        ans=min(ans,res);

      //  cout<<u<<" "<<a[u]<<" "<<sum<<" "<<res<<endl;
    }
    u--;
    if(u>0)
    {
        ll res=x-a[u];
        res+=max(y-(sum-a[u]),0LL);
        ans=min(ans,res);

        //cout<<u<<" "<<a[u]<<" "<<sum<<" "<<res<<endl;
    }
    printf("%lld\n",ans);
}
  return 0;
}