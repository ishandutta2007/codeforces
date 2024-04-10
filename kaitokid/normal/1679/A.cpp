#include<bits/stdc++.h>
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
        ll n,mx=-1,mn=-1;
        cin>>n;
        for(ll i=0;i<10;i++)
        {
            ll g=n-4*i;

            if(g<0)continue;
            if(g%6)continue;
            mn=i+g/6;
            break;
        }

        for(ll i=0;i<10;i++)
        {
            ll g=n-6*i;

            if(g<0)continue;
            if(g%4)continue;
            mx=i+g/4;
            break;
        }
        if(mx==-1)cout<<-1<<endl;
        else cout<<mn<<" "<<mx<<endl;
    }
    return 0;
}