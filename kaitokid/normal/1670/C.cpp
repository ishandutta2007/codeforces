#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int mod=1e9+7;
int n,a[100009],b[100009],c[100009];
int pos[100009];
bool vis[100009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
      cin>>n;
    for(int i=0;i<n;i++){cin>>a[i];pos[a[i]]=i;vis[i]=0;}
    for(int i=0;i<n;i++)cin>>b[i];
    for(int i=0;i<n;i++)cin>>c[i];
    int ans=1;
    for(int i=0;i<n;i++)
    {
        if(c[i]==0 || a[i]==b[i])continue;
        int u=i;
        while(!vis[u]){vis[u]=true;u=pos[b[u]];}
    }
    for(int i=0;i<n;i++)
    {
        if(a[i]==b[i]||vis[i])continue;
        ans=(ans*2)%mod;
        int u=i;
        while(!vis[u]){vis[u]=true;u=pos[b[u]];}

    }
    cout<<ans<<endl;

    }
    return 0;
}