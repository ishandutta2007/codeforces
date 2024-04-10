#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[3009];
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
        for(int i=0;i<n;i++)cin>>a[i];
        sort(a,a+n);
        ll ans=LLONG_MAX;
        for(int i=1;i+1<n;i++)ans=min(ans,a[i+1]-a[i-1]);
        cout<<ans<<endl;
    }
    return 0;
}