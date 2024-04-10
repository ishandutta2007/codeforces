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
        ll n,a,x;
        cin>>n>>x>>a;
        ll mn=a-x,mx=a+x,ans=0;
        for(int i=1;i<n;i++)
        {
            cin>>a;
            mn=max(mn,a-x);
            mx=min(mx,a+x);
            if(mx<mn){ans++;mx=a+x;mn=a-x;}

        }
        cout<<ans<<endl;
    }

    return 0;

}