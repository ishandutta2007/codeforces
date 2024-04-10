#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200009],n,k,lm;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);


    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(int i=1;i<=n;i++)cin>>a[i];
        ll mx=a[k],cur=a[k];
        lm=k-1;
        ll sm=0;
        bool ans=false;
        for(int i=k+1;i<=n+1;i++)
        {
            if(i==n+1){ans=true;break;}
            while((lm>0)&&cur+sm+a[lm]>=0){sm+=a[lm];lm--;if(sm>0){cur+=sm;sm=0;}}
            if(a[i]+cur<0)break;
            cur+=a[i];
        }
        if(ans){cout<<"YES"<<endl;continue;}

        reverse(a+1,a+n+1);
        k=n-k+1;
        mx=a[k],cur=a[k];
        lm=k-1;
         sm=0;
        for(int i=k+1;i<=n+1;i++)
        {
            if(i==n+1){ans=true;break;}
            while((lm>0)&&cur+sm+a[lm]>=0){sm+=a[lm];lm--;if(sm>0){cur+=sm;sm=0;}}
            if(a[i]+cur<0)break;
            cur+=a[i];
        }
        if(ans){cout<<"YES"<<endl;continue;}

        cout<<"NO"<<endl;
        }
    return 0;
}