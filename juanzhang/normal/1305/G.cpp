#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

typedef long long ll;
int n,A[1<<18],par[1<<18];bool vis[1<<18];

int find(int x){
  return par[x]==x?x:par[x]=find(par[x]);
}

int main(){
  ll ans=0;cin>>n,A[0]=1;while(n--){
    int x;scanf("%d",&x),par[x]=x,ans-=x,A[x]++;
  }
  per(S,(1<<18)-1,0){
    for(int sub=S;sub>S/2;sub=S&(sub-1)){
      if(A[sub]&&A[S^sub]){
        int u=find(sub),v=find(S^sub);
        if(!vis[sub])ans+=1ll*S*(A[sub]-1),vis[sub]=1;
        if(!vis[S^sub])ans+=1ll*S*(A[S^sub]-1),vis[S^sub]=1;
        if(u!=v)par[u]=v,ans+=S;
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}