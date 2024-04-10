#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll fr[400009];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n,x;
        ll ans=0;
        cin>>n;
for(int i=0;i<=2*n;i++)fr[i]=0;
for(int i=0;i<n;i++)
{
    cin>>x;
    ans+=fr[x-i+n];
    fr[x-i+n]++;
}
cout<<ans<<endl;
    }
    return 0;
}