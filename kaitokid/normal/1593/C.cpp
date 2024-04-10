#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[400009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;

    while(t--)
    {

    int n,k;
    cin>>n>>k;
    for(int i=0;i<k;i++)cin>>a[i];
    sort(a,a+k);
    ll r=n-1,ans=0;
    for(int i=k-1;i>=0;i--)
    {
        r-=(n-a[i]);
        if(r<0)break;
        ans++;
    }
    cout<<ans<<endl;

    }
    return 0;
}