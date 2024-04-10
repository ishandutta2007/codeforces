#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll a[200009];
int main()
{

    ios::sync_with_stdio(0);
    int t,l,r;
    cin>>t;
    while(t--)
    {
        int n,k,z;
        cin>>n>>k>>z;
        for(int i=0;i<n;i++)cin>>a[i];
        ll sum=a[0],ans=a[0],mx=0;
        for(int i=1;i<=k;i++)
        {
            sum+=a[i];
            mx=max(mx,a[i]+a[i-1]);

            ll res=sum+min(z,(k-i)/2)*mx;
            ll g=0;
           if(i<k&&z>0)  g=sum+max(0,min(z-1,(k-i-1)/2))*mx+a[i-1];
            res=max(res,g);

            //cout<<i<<" "<<res<<endl;
            ans=max(ans,res);
        }
        cout<<ans<<endl;
    }
    return 0;
}