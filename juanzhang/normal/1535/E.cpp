#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

typedef long long ll;
typedef pair<int,int>pii;
const int maxn=3e5+10;
int n=1,q,fa[19][maxn];ll sum[19][maxn],cnt[19][maxn],val[19][maxn];

int main(){
  cin>>q>>sum[0][1]>>cnt[0][1],val[0][1]=cnt[0][1]*sum[0][1];
  rep(_,2,q+1){
    int op,x,y;
    scanf("%d%d%d",&op,&x,&y);
    if(op==1){
      int z;scanf("%d",&z),cnt[0][_]=z;
      n=_,x++,fa[0][n]=x,sum[0][n]=y,val[0][n]=1ll*y*z;
      rep(i,1,18){
        fa[i][n]=fa[i-1][fa[i-1][n]];
        sum[i][n]=sum[i-1][n]+sum[i-1][fa[i-1][n]];
        cnt[i][n]=cnt[i-1][n]+cnt[i-1][fa[i-1][n]];
        val[i][n]=val[i-1][n]+val[i-1][fa[i-1][n]];
      }
    }else{
      int u=++x,w=y;ll ans=0;
      while(w){
        if(!sum[0][u]){
          break;
        }
        int v=u;
        per(i,18,0)if(sum[0][fa[i][v]]){
          v=fa[i][v];
        }
//        printf("(%d %d)\n",v,w);
        int t=min((ll)w,sum[0][v]);
        w-=t,sum[0][v]-=t,ans+=t*cnt[0][v];
      }
      printf("%d %lld\n",y-w,ans);
      fflush(stdout);
    }
  }
  return 0;
}