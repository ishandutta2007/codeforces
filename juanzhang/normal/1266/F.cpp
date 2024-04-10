#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

int read(){
  int x=0;char c=getchar();
  while(c<48)c=getchar();
  while(c>47)x=x*10+(c^48),c=getchar();
  return x;
}
void write(int x){
  if(x>9)write(x/10);putchar(x%10|48);
}

const int maxn=1e6+10;
int n,ans[maxn];vector<int>E[maxn];

int dp[maxn],vou[maxn],fa[maxn],val0[maxn],val1[maxn];
void dfs1(int u,int f){
  fa[u]=f;
  for(int v:E[u])if(v!=f){
    dfs1(v,u),dp[u]=max(dp[u],dp[v]+1);
  }
}
void dfs2(int u,int f){
  int mx=vou[u],chk=-1,mx2=0;
  for(int v:E[u])if(v!=f){
    int x=dp[v]+1;
    if(mx<x)mx2=mx,mx=x,chk=v;
    else if(mx2<x)mx2=x;
  }
  mx++,mx2++;
  for(int v:E[u])if(v!=f){
    vou[v]=v==chk?mx2:mx;
    dfs2(v,u);
  }
}

map<int,int,greater<int>>S[maxn];

void dfs3(int u,int f){
  S[u][vou[u]]++;
  for(int v:E[u])if(v!=f){
    S[u][dp[v]+1]++;
  }
  for(int v:E[u])if(v!=f){
    dfs3(v,u);
    S[u][dp[v]+1]--;
    for(const auto&p:S[v])if(p.second)S[u][p.first]+=p.second;
    int cnt=0;
    for(const auto&p:S[u]){
      val0[p.first]=max(val0[p.first],cnt+=p.second);
    }
    for(const auto&p:S[v])if(p.second)S[u][p.first]-=p.second;
    S[u][dp[v]+1]++;
    S[v].clear();
  }
  S[u][vou[u]]--;
}

int main(){
  cin>>n;
  rep(i,2,n){
    int u=read(),v=read();E[u].push_back(v),E[v].push_back(u);
  }
  dfs1(1,0),dfs2(1,0);
  rep(u,1,n){
    vector<int>vec;
    vec.push_back(0);
    for(int v:E[u]){
      if(v==fa[u]){
        vec.push_back(vou[u]);
      }else{
        vec.push_back(dp[v]+1);
      }
    }
    sort(vec.begin(),vec.end(),greater<int>());
    int cnt=0;
    for(int x:vec){
      cnt++;
      val0[x]=max(val0[x],cnt);
      val1[x*2-1]=max(val1[x*2-1],cnt);
      if(cnt<(int)vec.size()){
        int t=vec[cnt];
        if(t<x)t=t*2+1,val1[t]=max(val1[t],cnt+1);
      }
    }
  }
  dfs3(1,0);
  per(i,n+n,1)val0[i]=max(val0[i],val0[i+1]);
  per(i,n+n,1)val1[i]=max(val1[i],val1[i+1]);
  rep(i,1,n)write(max(i%2==0?val0[i/2]:val1[i],max(1,ans[i]))),putchar(' ');
  return 0;
}