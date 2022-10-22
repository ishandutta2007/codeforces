#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll sum=0;
        for(int i=0;i<n;i++)
        {
            ll x;
            cin>>x;
            sum+=x;
        }
        if(sum==n){cout<<0<<endl;continue;}
        if(sum<n){cout<<1<<endl;continue;}
        cout<<sum-n<<endl;
    }
    return 0;

}