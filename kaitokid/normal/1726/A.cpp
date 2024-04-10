#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[2009];
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
        for(int i=0;i<n;i++)
            cin>>a[i];
        int ans=a[n-1]-a[0];
        for(int i=1;i<n;i++)ans=max(ans,a[i]-a[0]);
        for(int i=0;i<n-1;i++)ans=max(ans,a[n-1]-a[i]);
        for(int i=0;i<n;i++)
            ans=max(ans,a[i]-a[(i+1)%n]);
        cout<<ans<<endl;
    }
    return 0;
}