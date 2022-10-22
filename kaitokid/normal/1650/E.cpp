#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll p[200009],a[200009],suf[200009][2],pr[200009][2];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        ll n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=n;i++)p[i]=a[i]-a[i-1];
        pr[0][0]=suf[n+1][0]=INT_MAX;
        pr[0][1]=suf[n+1][1]=0;
        for(int i=1;i<=n;i++)pr[i][0]=min(pr[i-1][0],p[i]),pr[i][1]=max(pr[i-1][1],p[i]);
        for(int i=n;i>=1;i--)suf[i][0]=min(suf[i+1][0],p[i]),suf[i][1]=max(suf[i+1][1],p[i]);
        ll ans=min(pr[n-1][0],d-a[n-1]);
        for(int i=1;i<n;i++)
        {
            ll tmp=pr[i-1][0];
            tmp=min(tmp,suf[i+2][0]);
            ll tmp2=tmp;
            tmp=min(tmp,p[i]+p[i+1]);
            ll tmp3=tmp;
            tmp=min(tmp,d-a[n]);
            ans=max(ans,tmp);
            tmp2=min(tmp2,(p[i]+p[i+1])/2);
            ans=max(ans,tmp2);
            tmp3=min(tmp3,max(pr[i-1][1],suf[i+2][1])/2);
            ans=max(ans,tmp3);
         //   cout<<i<<" "<<tmp<<" "<<tmp2<<" "<<tmp3<<endl;

        }
        ll tmp=min(pr[n-1][0],pr[n-1][1]/2);
        ans=max(ans,tmp);
        cout<<ans-1<<endl;


    }
    return 0;
}