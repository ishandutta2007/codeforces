#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll a[100];
int main()
{
    ios::sync_with_stdio(0);
ll t,n,x;
cin>>t;
while(t--)
{
    ll s[2]={0,0};
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        s[i%2]+=a[i];
    }
    int u=(s[0]>s[1]);

        for(ll i=0;i<n;i++)
if(i%2==u)cout<<1<<" ";
else cout<<a[i]<<" ";
cout<<endl;
}

    return 0;
}