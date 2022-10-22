#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll t,n,a[200009],k,f[400009],d[400009];
int main()
{

    ios::sync_with_stdio(0);
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(int i=2;i<=2*k+1;i++){f[i]=0;d[i]=0;}
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=n/2;i++){f[min(a[i],a[n-i+1])]++;d[k+max(a[i],a[n-i+1])+1]++;}
        for(int i=2*k;i>1;i--)f[i]+=f[i+1];
        for(int i=2;i<=2*k;i++)d[i]+=d[i-1];
        for(int i=2;i<=2*k;i++)f[i]+=d[i];
        for(int i=2;i<=2*k;i++)f[i]+=n/2;
        for(int i=1;i<=n/2;i++){f[a[i]+a[n-i+1]]--;}
        ll ans=f[2];
        for(int i=2;i<=2*k;i++){ans=min(ans,f[i]);}
        cout<<ans<<endl;
    }

    return 0;
}