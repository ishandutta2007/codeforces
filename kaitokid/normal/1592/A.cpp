#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[2009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        ll h;
        cin>>n>>h;
        for(int i=0;i<n;i++)cin>>a[i];
        sort(a,a+n);
        ll ans=h/(a[n-1]+a[n-2]);
        h-=ans*(a[n-1]+a[n-2]);
        ans*=2;
        if(h>0){ans++;h-=a[n-1];}
        if(h>0){ans++;h-=a[n-2];}
        cout<<ans<<endl;
    }
    return 0;
}