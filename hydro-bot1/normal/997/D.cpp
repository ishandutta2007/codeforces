// Hydro submission #60d72efe0b778688e9ce7164@1624854082153
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<ctime>
#include<vector>
#include<set>
#include<map>
#include<stack>
using namespace std;
#define add(x,y) x=(x+y)%mod
const int mod = 998244353;
int c[80][80],m;
struct tree {
    int n,ans[80],f[80][5000],g[80][5000];
    int root,sum,siz[5000],w[5000],a[5000],tot;
    bool vis[5000];
    vector<int>v[5000];
    inline void getrt(int x,int fa){
      siz[x]=1;
      w[x]=0;
      for(int i=0;i<v[x].size();i++)
        if(v[x][i]!=fa&&!vis[v[x][i]]){
          getrt(v[x][i],x);
          siz[x]+=siz[v[x][i]];
          w[x]=max(w[x],siz[v[x][i]]);
        }
      w[x]=max(w[x],sum-siz[x]);
      if(!root||w[x]<w[root])root=x;
    }
    inline void dfs(int x,int fa){
      a[++tot]=x;
      siz[x]=1;
      for(int i=0;i<v[x].size();i++)
        if(v[x][i]!=fa&&!vis[v[x][i]]){
          dfs(v[x][i],x);
          siz[x]+=siz[v[x][i]];
        }
    }
    inline void work(int x){
      tot=0;
      dfs(x,0);
      int i,j,k;
      memset(f,0,sizeof(f));
      memset(g,0,sizeof(g));
      f[0][x]=g[0][x]=1;
      for(i=1;i<=m;i++)
        for(j=1;j<=tot;j++){
          for(k=0;k<v[a[j]].size();k++){
            if(vis[v[a[j]][k]])continue;
            if(a[j]!=x)add(f[i][a[j]],f[i-1][v[a[j]][k]]);
            add(g[i][a[j]],g[i-1][v[a[j]][k]]);
          }
        }
      for(i=1;i<=tot;i++){
          if(a[i]==x){
            for(j=0;j<=m;j++)add(ans[j],g[j][a[i]]);
          }else {
            for(j=0;j<=m;j++)
              for(k=0;k+j<=m;k++)
                add(ans[k+j],(long long)f[j][a[i]]*g[k][a[i]]%mod);
          }
      }
      vis[x]=1;
      for(i=0;i<v[x].size();i++)
        if(!vis[v[x][i]]){
          root=0;
          sum=siz[v[x][i]];
          getrt(v[x][i],x);
          work(root);
        }
    }
    inline void solve(){
      sum=n;
      root=0;
      memset(vis,0,sizeof(vis));
      memset(ans,0,sizeof(ans));
      getrt(1,0);
      work(root);
    }
};
tree t1,t2;
int main(){
    int i,j,k;
    scanf("%d%d%d",&t1.n,&t2.n,&m);
    c[0][0]=1;
    for(i=1;i<=m;i++)c[i][i]=c[i][0]=1;
    for(i=1;i<=m;i++)
      for(j=1;j<i;j++)c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
    for(i=0;i<=t1.n;i++)t1.v[i].clear();
    for(i=0;i<=t2.n;i++)t2.v[i].clear();
    for(i=1;i<t1.n;i++){
      int x,y;
      scanf("%d%d",&x,&y);
      t1.v[x].push_back(y);
      t1.v[y].push_back(x);
    }
    for(i=1;i<t2.n;i++){
      int x,y;
      scanf("%d%d",&x,&y);
      t2.v[x].push_back(y);
      t2.v[y].push_back(x);
    }
    t1.solve(),t2.solve();
    int Ans=0;
    for(i=0;i<=m;i++)
      Ans=(Ans+(long long)t1.ans[i]*t2.ans[m-i]%mod*c[m][i])%mod;
    cout<<Ans;
    return 0;
}