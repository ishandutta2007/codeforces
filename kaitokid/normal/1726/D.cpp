#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool vis[200009];
int x[300009],y[300009],pr[300009],lvl[300009];
vector<int>v[200009];
int ans[300009];
bool vs[300009];
void go(int x,int p,int l=0)
{
    pr[x]=p;
    lvl[x]=l;
    vis[x]=true;
    for(int i=0;i<v[x].size();i++)
        if(!vis[v[x][i]])go(v[x][i],x,l+1);
}
bool cmp(int x,int y)
{
    return lvl[x]<lvl[y];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++){v[i].clear();vis[i]=false;vs[i]=false;}
        for(int i=0;i<m;i++)
        {
            cin>>x[i]>>y[i];
            v[x[i]].push_back(y[i]);
            v[y[i]].push_back(x[i]);

        }
       go(1,0);
       vector<int>g;

       for(int i=0;i<m;i++)
            if(pr[x[i]]==y[i] || pr[y[i]]==x[i])
                ans[i]=0;else {ans[i]=1;g.push_back(i);}
      vector<int>vv;
      for(int i=0;i<g.size();i++)
      {
          int u=g[i];
          if(!vs[x[u]]){vv.push_back(x[u]);vs[x[u]]=true;}
          if(!vs[y[u]]){vv.push_back(y[u]);vs[y[u]]=true;}

      }
      if(g.size()<3 || (vv.size()!=3))
      {
          for(int i=0;i<m;i++)cout<<ans[i];
          cout<<endl;
          continue;
      }

      sort(vv.begin(),vv.end(),cmp);
      for(int i=0;i<m;i++)
      {

          if(((pr[x[i]]==y[i] ) &&(x[i]==vv[2])) || ((pr[y[i]]==x[i])&&(y[i]==vv[2])))ans[i]=1;
        if((x[i]==vv[2]) && (y[i]==vv[0]))ans[i]=0;
        if((x[i]==vv[0]) && (y[i]==vv[2]))ans[i]=0;

      }
       for(int i=0;i<m;i++)cout<<ans[i];
          cout<<endl;
          continue;
    }
    return 0;
}