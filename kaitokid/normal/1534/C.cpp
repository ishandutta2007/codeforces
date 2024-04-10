#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod=1e9+7;
int a[400009],b[400009],id[400009];
bool vis[400009];
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
        for(int i=1;i<=n;i++){cin>>a[i];vis[i]=false;id[a[i]]=i;}
        for(int i=1;i<=n;i++)cin>>b[i];
        ll ans=1;
        for(int i=1;i<=n;i++)
        {
            if(vis[i])continue;
            ans=(ans*2)%mod;
            int u=i;
            while(!vis[u])
            {

                vis[u]=true;
                u=id[b[u]];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}