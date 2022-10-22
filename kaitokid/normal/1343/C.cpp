#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll t,n,a[200009];
int main()
{

    ios::sync_with_stdio(0);
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)cin>>a[i];
        ll u=a[0],ans=0;
        for(int i=1;i<n;i++)
        {
            if((a[i]>0&&a[i-1]<0)||(a[i]<0&&a[i-1]>0)){ans+=u;u=a[i];continue;}
            u=max(a[i],u);
        }
        ans+=u;
        cout<<ans<<endl;
    }

    return 0;
}