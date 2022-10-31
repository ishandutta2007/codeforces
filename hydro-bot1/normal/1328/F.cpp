// Hydro submission #62c6d648c3a9fda5622b1f0d@1657198152904
#include<bits/stdc++.h>
#define INF 0x7f7f7f7f

using namespace std;
typedef long long ll;
const int N=200001;

int n,k;
ll a[N];
ll pre[N],suf[N];
ll ans;

int main()
{
    ans=LLONG_MAX;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    int cnt=1;
    for(int i=2;i<=n;i++){
       if(a[i]==a[i-1])cnt++;
       else cnt=1;
       if(cnt>=k){
         puts("0");
         return 0;
       }
    }

    for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
    for(int i=n;i>=1;i--)suf[i]=suf[i+1]+a[i];
    for(int i=1;i<=n;i++){
       if(i>=k)ans=min(ans,i*a[i]-pre[i]-(i-k));
       if(n-i+1>=k)ans=min(ans,suf[i]-(n-i+1)*a[i]-(n-i+1-k));
       ans=min(ans,i*a[i]-pre[i]+suf[i]-(n-i+1)*a[i]-(n-k));
    }
    cout<<ans<<endl;

    return 0;
}