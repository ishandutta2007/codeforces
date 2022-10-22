#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

typedef long long ll;

const int P=1e9+7;
void Add(int&x,int y){if((x+=y)>=P)x-=P;}
int N,k,R,C,fac[100010];
struct node{
  int x,y,z;
}A[60],B[60];

void discretize(){
  sort(A+1,A+k+1,[](node P,node Q){
    return P.x<Q.x;
  });
  rep(i,1,k)B[i].x=B[i-1].x+(A[i].x!=A[i-1].x);
  rep(i,1,k)A[i].x=B[i].x,swap(A[i].x,A[i].y);
  sort(A+1,A+k+1,[](node P,node Q){
    return P.x<Q.x;
  });
  rep(i,1,k)B[i].x=B[i-1].x+(A[i].x!=A[i-1].x);
  rep(i,1,k)A[i].x=B[i].x,swap(A[i].x,A[i].y);
  sort(A+1,A+k+1,[](node P,node Q){
    return P.x<Q.x||(P.x==Q.x&&P.y<Q.y);
  });
}

int solve1(){
  static int dp[1<<20],mp[60][60];
  rep(i,1,k)mp[A[i].x][A[i].y]=A[i].z;
  dp[0]=1;
  rep(i,1,R){
    per(S,(1<<C)-1,0){
      int x=dp[S];
      if(!x)continue;
      rep(j,1,C)if(mp[i][j]&&(~S>>(j-1)&1)){
        int &z=dp[S|1<<(j-1)];
        z=(z+1ll*x*mp[i][j])%P;
      }
    }
  }
  int ans=0;
  rep(S,0,(1<<C)-1)Add(ans,1ll*fac[N-__builtin_popcount(S)]*dp[S]%P);
  return ans;
}
int ecnt=1,h[120],par[120],dp[120][120][2];bool vis[120],cho[120];
struct edges{
  int nxt,to,w;
}E[120];
void addline(int u,int v,int w){
  E[++ecnt]={h[u],v,w},h[u]=ecnt;
}
int find(int x){
  return par[x]==x?x:par[x]=find(par[x]);
}
void dfs(int u){
  vis[u]=1,dp[u][0][cho[u]]=1;
  for(int i=h[u];i;i=E[i].nxt){
    int v=E[i].to;
    if(!vis[v]){
      dfs(v);
      static int tmp[120][2];
      rep(j,0,R+C){
        int x=dp[v][j][0],y=dp[v][j][1];
        if(x||y)rep(k,0,R+C){
          int p=dp[u][k][0],q=dp[u][k][1];
          if(p&&x)Add(tmp[j+k+1][1],1ll*x*p%P*E[i].w%P);
          if(p)Add(tmp[j+k][0],1ll*p*(x+y)%P);
          if(q)Add(tmp[j+k][1],1ll*q*(x+y)%P);
        }
      }
      memcpy(dp[u],tmp,sizeof tmp),memset(tmp,0,sizeof tmp);
    }
  }
}
int solve2(){
  vector<node>vec;
  rep(i,1,R+C)par[i]=i;
  rep(i,1,k){
    int u=A[i].x,v=R+A[i].y;
    if(find(u)!=find(v))par[find(u)]=find(v),addline(u,v,A[i].z),addline(v,u,A[i].z);
    else vec.push_back(A[i]);
  }
  int sz=vec.size(),ans=0;
  rep(S,0,(1<<sz)-1){
    memset(dp,0,sizeof dp),memset(vis,0,sizeof vis),memset(cho,0,sizeof cho);int dt=1,ct=0;
    rep(i,0,sz-1)if(S>>i&1){
      bool&f1=cho[vec[i].x],&f2=cho[vec[i].y+R];
      if(f1||f2)dt=0;
      dt=1ll*dt*vec[i].z%P,f1=f2=1,ct++;
    }
    int lsj[120],tmp[120];
    memset(lsj,0,sizeof lsj),memset(tmp,0,sizeof tmp),lsj[0]=1;
    rep(u,1,R+C)if(!vis[u]){
      dfs(u);
      rep(i,0,R+C){
        int x=(dp[u][i][0]+dp[u][i][1])%P;
        if(x)rep(j,0,R+C)Add(tmp[i+j],1ll*x*lsj[j]%P);
      }
      memcpy(lsj,tmp,sizeof tmp),memset(tmp,0,sizeof tmp);
    }
    rep(i,0,R+C)ans=(ans+1ll*dt*fac[N-(ct+i)]%P*lsj[i])%P;
  }
  return ans;
}

int main(){
  cin>>N>>k;
  fac[0]=1;rep(i,1,N)fac[i]=1ll*i*fac[i-1]%P;
  rep(i,1,k)cin>>A[i].x>>A[i].y>>A[i].z,A[i].z=(P-1+A[i].z)%P;
  discretize();
  rep(i,1,k)R=max(R,A[i].x),C=max(C,A[i].y);
  if(R<C){
    swap(R,C);
    rep(i,1,k)swap(A[i].x,A[i].y);
  }
  printf("%d\n",C<=20?solve1():solve2());
  return 0;
}