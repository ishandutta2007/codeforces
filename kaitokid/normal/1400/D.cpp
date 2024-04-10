#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll t;
ll n,a[3009],c1[3009],c2[3009];
int main()
{
    ios::sync_with_stdio(0);
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)cin>>a[i];
        ll ans=0;
        for(int i=0;i<n;i++)
        {
            ll res=0;
            for(int j=0;j<=n;j++)c1[j]=c2[j]=0;
            for(int j=i+1;j<n;j++)c1[a[j]]++;
            for(int j=i+1;j<n;j++)
            {
                res-=c1[a[j]]*c2[a[j]];
                c1[a[j]]--;

                c2[a[j]]++;

                res+=c1[a[j]]*c2[a[j]];
           if(a[j]==a[i])   {ans+=res-c1[a[j]];}
         //   cout<<i<<" "<<j<<" "<<res<<endl;

            }

        }
        cout<<ans<<endl;
    }
    return 0;
}