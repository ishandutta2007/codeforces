#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200008];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        ll ans=0;
        for(int i=1;i<=n;i++)cin>>a[i];
        int u=1;
        while(u<n &&(a[u]==0))u++;
        for(int i=u;i<n;i++)
        {
            ans+=a[i];
            if(a[i]==0)ans++;
        }
        cout<<ans<<endl;
    }

    return 0;
}