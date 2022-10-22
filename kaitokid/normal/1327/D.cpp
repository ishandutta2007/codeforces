#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int ans,t,n;
vector<int>f;
int a[200008],c[200009];
bool vis[200009];
bool ch(int x)
{
    int s=f.size();
    for(int i=0;i<x;i++)
    {bool bl =true;
        for(int j=i+x;j<s;j+=x)if(c[f[i]]!=c[f[j]]){bl=false;break;}
        if(bl)return true;
    }
    return false;
}
void go()
{
    int s=f.size();
    for(int i=1;i<=s;i++)
    if(s%i==0&&ch(i)){ans=min(ans,i);return;}
}
int main()
{
ios::sync_with_stdio(0);
cin>>t;
while(t--)
{
    cin>>n;
    ans=n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>c[i];
    for(int i=1;i<=n;i++)
    {
        if(vis[i])continue;
        f.push_back(i);
        int u=a[i];
        while(u!=i){vis[u]=true;f.push_back(u);u=a[u];}
        go();
        f.clear();
    }
    cout<<ans<<endl;
    for(int i=1;i<=n;i++)vis[i]=false;
}
 return 0;
}