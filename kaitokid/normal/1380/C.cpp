#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
//int a[1009];
//int p[1009],s[1009];
int a[100009];
int main()
{
    ios::sync_with_stdio(0);
    int t;
    cin>>t;
    ll n,x,y;
    while(t--)
    {
        ll ans=0;
        cin>>n>>x;
        ll u=n;
        for(int i=0;i<n;i++)cin>>a[i];
        sort(a,a+n);
        for(int i=0;i<n;i++)
    {
        y=a[i];
        ll v=((x+y-1)/y);
        u=min(u,i+v-1);
        if(u==i){ans++;u=n;}
    }
    cout<<ans<<endl;
    }
    return 0;
}