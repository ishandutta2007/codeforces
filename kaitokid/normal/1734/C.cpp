#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool vis[1000009];
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
       string s;
       cin>>s;
       s='#'+s;
       for(int i=1;i<=n;i++)vis[i]=false;
       ll ans=0;
       for(int i=1;i<=n;i++)
            for(int j=i;j<=n;j+=i)
       {
           if(s[j]=='1')break;
           if(vis[j])continue;
           vis[j]=true;
           ans+=i;
       }
       cout<<ans<<endl;
    }
    return 0;
}