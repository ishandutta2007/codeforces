#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int t,n,a[100009],p[100009];
bool vis[100009];
int main()
{
ios::sync_with_stdio(0);
cin>>t;
while(t--)
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        vis[i+1]=false;
        cin>>a[i];
        p[a[i]]=i;
    }
    int en=n,fr;
    bool ans=true;
    for(int i=1;i<=n;i++)
    {
        if(vis[i])continue;
        int fr=p[i];
        for(int j=fr+1;j<en;j++){if(a[j]!=a[j-1]+1){ans=false;break;}vis[a[j]]=true;}
        en=fr;
        if(!ans)break;
    }
    if(ans)cout<<"Yes\n";
    else cout<<"No\n";
}
    return 0;
}