#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {

     int n,x;
     cin>>n;
     for(int i=0;i<n;i++)cin>>x;
     int ans=10-n;
     ans*=(ans-1);
     ans*=3;
     cout<<ans<<endl;

    }

    return 0;
}