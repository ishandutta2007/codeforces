#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int>g[300009];
int a[300009];
bool vis[300009];
map<pair<int,int>,bool >mp;
ll ans;
void go(int x,int y)
{
    //cout<<x<<" "<<y<<" "<<g[x].size()<<" "<<g[y].size()<<endl;
    if(g[x].size()>g[y].size())swap(x,y);
    int lst=g[y].size();
    for(int i=0;i<g[x].size();i++)
        for(int j=0;j<lst;j++)
    {
        int u=g[x][i],v=g[y][j];
      //  cout<<44<<" "<<u<<" "<<v<<endl;
        if(u>v)swap(u,v);
        if(u==v||mp[{u,v}])continue;
        ans=max(ans,(x+y)*1LL*(u+v));
        lst=j;
        break;
    }

}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        mp.clear();
        for(int i=0;i<=n;i++){g[i].clear();vis[i]=false;}
        for(int i=0;i<n;i++)scanf("%d",&a[i]);

        sort(a,a+n);
        int s=1;
        vector<int>r;
        for(int i=1;i<n;i++)
        {
            if(a[i]>a[i-1]){g[s].push_back(a[i-1]);
            if(!vis[s]){r.push_back(s);vis[s]=true;}
            s=1;continue;}
            s++;
        }
        g[s].push_back(a[n-1]);
        if(!vis[s]){r.push_back(s);vis[s]=true;}
        for(int i=0;i<r.size();i++)
            {sort(g[r[i]].begin(),g[r[i]].end());reverse(g[r[i]].begin(),g[r[i]].end());}
       for(int i=0;i<m;i++)
       {
           int x,y;
           scanf("%d%d",&x,&y);
           //cin>>x>>y;
           mp[{x,y}]=true;
       }
       ans=0;
       for(int i=0;i<r.size();i++)
          for(int j=i;j<r.size();j++)go(r[i],r[j]);
cout<<ans<<endl;
    }
    return 0;
}