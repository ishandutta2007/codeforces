#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[299],k;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(int i=0;i<n;i++)cin>>a[i];
        sort(a,a+n);
        int ans=0;
        reverse(a,a+n);
        for(int i=0;i<k;i++)ans+=(a[i+k]/a[i]);
        for(int i=2*k;i<n;i++)ans+=a[i];
        cout<<ans<<endl;
    }
    return 0;
}