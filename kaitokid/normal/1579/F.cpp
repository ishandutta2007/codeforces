#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int cal(vector<int>&g)
{
    int r=0,mx=0;
    for(int i=0;i<g.size();i++)
    {
        if(g[i]==0){mx=max(r,mx);r=0;continue;}
        r++;
    }
    mx=max(r,mx);
    int m=g.size();
    if(mx==m)return 100000000;
    r=0;
    for(int i=0;i<m;i++)
        if(g[i]==0)break;
    else r++;
    for(int i=m-1;i>=0;i--)
        if(g[i]==0)break;
    else r++;
    mx=max(mx,r);
    return mx;
}

bool vis[1000009];
int a[1000009];
int main() {
ios::sync_with_stdio(0);
cin.tie(0);
int t;
cin>>t;
while(t--)
{
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++){cin>>a[i];vis[i]=0;}
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(vis[i])continue;
        vector<int> g;
        int u=i;
        while(vis[u]==false)
        {
            vis[u]=true;
            g.push_back(a[u]);
            u=(u-k+n)%n;

        }
        ans=max(ans,cal(g));
    }
    if(ans>n)cout<<-1<<endl;
    else cout<<ans<<endl;
}
return 0;
}