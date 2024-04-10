#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf=1000000000000000;
ll n,x,y;
ll dp[5009][5009][2];
string a,b;
ll go(int pos,int lf,int z)
{
    if(pos==n)
    {
        if(z)return inf;
        if(lf%2)return inf;
        return 0;
    }
    if(dp[pos][lf][z]!=-1)return dp[pos][lf][z];
    int u=(a[pos]==b[pos]);
    if(z)u=1-u;

    if(u)
        dp[pos][lf][z]=go(pos+1,lf,0);
    else
        dp[pos][lf][z]=min(x+go(pos+1,lf,1),y+go(pos+1,lf+1,0));
    if(lf==0)return dp[pos][lf][z];
    u=1-u;
    if(u)
        dp[pos][lf][z]=min(dp[pos][lf][z],go(pos+1,lf-1,0));
    else
        dp[pos][lf][z]=min(dp[pos][lf][z],min(x+go(pos+1,lf-1,1),y+go(pos+1,lf,0)));

    return dp[pos][lf][z];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
      cin>>n>>x>>y>>a>>b;

      vector<int>g;
      for(int i=0;i<n;i++)
            if(a[i]!=b[i])g.push_back(i);
      int u=g.size();
      if(u%2)
      {
          cout<<-1<<endl;
          continue;
      }
      if(x>=y){
      if((u==2) && (g[1]==(g[0]+1)))
      {
          ll res=min(x,2*y);
         cout<<res<<endl;
        continue;
      }
      y*=(u/2);
      cout<<y<<endl;
      continue;
    }
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
          dp[i][j][0]=dp[i][j][1]=-1;
    cout<<go(0,0,0)<<endl;
    }
    return 0;
}