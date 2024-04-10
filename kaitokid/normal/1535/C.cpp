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
        string s;
        ll ans=0;
        cin>>s;
        ll n=s.size();
        ll u=-1,v=-1;
        for(ll i=0;i<n;i++)
        {
            if(s[i]=='?')
            {ans+=i-min(u,v);continue;}
            int r=s[i]-'0';
            if(r==(i%2)){ans+=i-u;v=i;continue;}
            ans+=i-v;
            u=i;
        }
        cout<<ans<<endl;
    }
    return 0;
}