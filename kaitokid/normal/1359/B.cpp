#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll t,n,m,x,y;
int main()
{
    ios::sync_with_stdio(0);
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>x>>y;
        y=min(y,2*x);
       // cout<<y<<endl;
        ll ans=0;
        string s;
        for(int i=0;i<n;i++)
        {
            cin>>s;
            ll u=0;
            for(int j=0;j<m;j++)
            {
                if(s[j]=='.')u++;
                else {ans+=(u/2)*y+(u%2)*x;u=0;}
            }
            ans+=(u/2)*y+(u%2)*x;
        }
        cout<<ans<<endl;
        }
    return 0;
}