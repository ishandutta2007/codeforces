#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
ll a[50],b[50];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++)cin>>b[i];
        ll ans=0;
        for(int i=0;i+1<n;i++)
            ans+=min(abs(a[i]-a[i+1])+abs(b[i]-b[i+1]),abs(a[i]-b[i+1])+abs(b[i]-a[i+1]));
        cout<<ans<<endl;
    }


    return 0;
}