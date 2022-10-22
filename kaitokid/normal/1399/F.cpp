#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
pair<int,int>a[3009];
vector<int> h,f[6009],en[6009];
int m;
bool d[6009][6009];
int dp[6009][6009];
int hs[200009];
int go(int x,int y)
{
    if(dp[x][y]!=-1)return dp[x][y];
    int res=0;
    if(x==y){if(d[x][y])return 1;else return 0;}
    res=max(go(x,y-1),go(x+1,y));
    if(d[x][y])res++;
    for(int i=0;i<en[x].size();i++)
    {
        if(en[x][i]<y)res=max(res,go(x,en[x][i])+go(en[x][i]+1,y)+d[x][y]);
    }
    for(int i=0;i<f[y].size();i++)
    {
        if(f[y][i]>x)res=max(res,go(x,f[y][i]-1)+go(f[y][i],y)+d[x][y]);
    }
    return dp[x][y]=res;
}
int main()
{
ios::sync_with_stdio(0);
int n,t;
cin>>t;
while(t--)
{
    h.clear();

    cin>>n;
    for(int i=0;i<n;i++){cin>>a[i].first>>a[i].second;h.push_back(a[i].first);h.push_back(a[i].second);}
    sort(h.begin(),h.end());
     m=h.size();
    for(int i=0;i<m;i++)
  {f[i].clear();en[i].clear();
      for(int j=0;j<m;j++)
    {d[i][j]=false;dp[i][j]=-1;}}
  hs[h[0]]=0;
  int u=0;
  for(int i=1;i<m;i++)
  {
      if(h[i]>h[i-1]){u++;hs[h[i]]=u;}
  }
  //m=u;
  
  for(int i=0;i<n;i++)
  {
      int u=hs[a[i].first],v=hs[a[i].second];
      d[u][v]=true;
      en[u].push_back(v);
      f[v].push_back(u);
  }
  cout<<go(0,m-1)<<endl;
}
    return 0;
}