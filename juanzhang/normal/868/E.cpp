#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

void chkmax(int&x,int y){if(x<y)x=y;}
int n,m,St,ecnt=1,h[55],bbbuk[55],deg[55];
struct edges{int nxt,to,w;}E[105];
void addline(int u,int v,int w){
  E[++ecnt]={h[u],v,w},h[u]=ecnt,deg[u]++;
}
int df$s(int u,int f){
  int res=bbbuk[u];for(int i=h[u];i;i=E[i].nxt){
    int v=E[i].to;if(v!=f)res+=df$s(v,u);
  }return res;
}

int dp[105][55][55];
int DP(int id,int x,int y){
  int T=E[id].to;
  if(deg[T]==1)y=0;
  int&res=dp[id][x][y];
  if(res!=-1)return res;
  if(!y){
    if(!x)return res=E[id].w;
    return res=DP(id^1,0,x)+E[id].w;
  }
  int dp2[2][55];
  memset(dp2,0,sizeof dp2),dp2[0][0]=1e9;int sel=0;
  for(int i=h[T];i;i=E[i].nxt)if(i!=(id^1)){
    memcpy(dp2[sel^1],dp2[sel],sizeof dp2[sel^1]);
    rep(p,0,y){
      rep(q,1,y-p){
        chkmax(dp2[sel^1][p+q],min(dp2[sel][p],DP(i,x+y-q,q)));
      }
    }
    sel^=1;
  }
  return res=dp2[sel][y]+E[id].w;
}

int main(){
  cin>>n;rep(i,2,n){
    int u,v,w;cin>>u>>v>>w;addline(u,v,w),addline(v,u,w);
  }
  cin>>St>>m;
  rep(i,1,m){
    int x;cin>>x;bbbuk[x]++;
  }if(n==1)return puts("0"),0;
  int ans=1e9;
  memset(dp,-1,sizeof dp);
  for(int i=h[St];i;i=E[i].nxt){
    int u=E[i].to;
    ans=min(ans,DP(i,df$s(St,u),df$s(u,St)));
  }
  cout<<ans<<endl;
  return 0;
}